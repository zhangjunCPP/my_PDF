/*
p1^t1 p2^t2.....
....
....
.....
对于每个质因数单独考虑

p^k+p^k2+p^k3+.....
p^(k+k2+k3+....+)
k1
k2
k3
k4
k5
对于每个子集取min相加
dp i j 
表示在第 i 个数时，最小的数是 j 的方案数。
dp i j->dp i+1 min(j,t_i)
      ->dp i+1 j
差不多就是一个 nqlogv的复杂度
对于每种值单独计算，容斥一下。
钦定最小的是这个值，那么答案就是 >= 他数的 cnt 的 2^cnt
g(i) 刚好是他 
f(i)=\sum g(i)
好像不是很能做。
可以这样来表示 
等于他的个数为 cnt1,大于他的个数为 cnt2。
那么就是 (2^cnt1-1)*(2^cnt2) 因为取等的至少一个。
感觉现在可以做一下了。
2*10^5 质数会不会有点多。
4000 来算好像会被卡。
他每次可以询问很大的区间，这样质数出现数，和幂次都可以达到最高。
我该不会可以 CDQ 吧。
离线下来莫队？
好像可以。
一个数可能会有 7 个质因数，所以 7 n \sqrt n 
2 3 5 7 11 13 17 
如果花 log 的时间来重新计算贡献，有点卡人。
插入一个数考虑带来的贡献。
< 他的数。
会方案数会乘上一个 2
== 他的方案数
也会乘上一个 2 
还是不是很好维护。
考虑一个质数最后的贡献：
如果我只将<=他的个数重新计算。
感觉卡不了，最多是一个 log 没有那个 7 的常数。
1024*256 
一秒跑 1e9 有点嘿人，但是感觉跑不满。 
上次那个题 5e5 莫队都能冲，我 2e5 的应该也行。
只是多了个常数。 
3点了，先写吧。
至少68吧。 
他在随机数据下几乎不肯能卡我。 
*/
#include<bits/stdc++.h>
#define ll long long 
const ll mod=998244353;
using namespace std;
inline void read(int &x){
	x=0;
	char c=getchar();
	bool f=0;
	while(c<'0' || c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
inline ll qpow(ll a,ll b,ll m){
	ll ret=1ll;
	for( ; b ; b>>=1ll){
		if(b&1ll) ret=ret*a%m;
		a=a*a%m;
	}
	return ret;
}
const int maxn=2e5+5;
int block,n,Q;
int a[maxn];
vector< pair<int,int> > p[maxn];
int book[maxn*9],tot; 
inline void solve(int x,int id){
	for(int i=2;i*i<=x;i++){
		if(x==1) break;
		int cnt=0;
		while(x%i==0) cnt++,x/=i;
		if(cnt) p[id].push_back(make_pair(i,cnt)),book[++tot]=i;
	}
	if(x!=1) p[id].push_back(make_pair(x,1)),book[++tot]=x;
}
struct ask{
	int l,r,id;
}q[maxn];
inline bool cmp(ask x,ask y){
	if(x.l/block==y.l/block) return ((x.l/block)&1)?x.r>y.r:x.r<y.r;
	return x.l/block<y.l/block;
}
const int maxT=479;
vector<int> cnt[maxT];
int Val[maxT];
int CNT[maxn];
ll pw[maxn];
ll ans=1ll;
vector< pair<ll,ll> > pans[maxn]; 
int T;
inline void add(int id){
	for(auto x:p[id]){
		if(x.first<T){
			cnt[x.first][x.second]++;
		}
		else{
			CNT[x.first]++;
			if(CNT[x.first]<(int)pans[x.first].size()){
				ans=ans*pans[x.first][CNT[x.first]-1].second%mod*pans[x.first][CNT[x.first]].first%mod;
			}
			else{
				ll sum=pans[x.first][CNT[x.first]-1].first*pans[x.first][CNT[x.first]-1].first%mod*(ll)x.first%mod;
				ll invsum=qpow(sum,mod-2,mod);
				assert(sum*invsum%mod==1);
				ans=ans*pans[x.first][CNT[x.first]-1].second%mod*sum%mod;
				pans[x.first].push_back(make_pair(sum,invsum));
			}
//			ans=ans*qpow(qpow(x.first,(pw[CNT[x.first]-1]+mod-2)%(mod-1),mod),mod-2,mod)%mod*qpow(x.first,(pw[CNT[x.first]]+mod-2)%(mod-1),mod)%mod;
		}
	}
}
inline void del(int id){
	for(auto x:p[id]){
		if(x.first<T){
			cnt[x.first][x.second]--;
		}
		else{
			CNT[x.first]--;
			ans=ans*pans[x.first][CNT[x.first]+1].second%mod*pans[x.first][CNT[x.first]].first%mod;
//			ans=ans*qpow(qpow(x.first,(pw[CNT[x.first]+1]+mod-2)%(mod-1),mod),mod-2,mod)%mod*qpow(x.first,(pw[CNT[x.first]]+mod-2)%(mod-1),mod)%mod;
		}
	}
}
int ANS[maxn];
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout); 
	read(n),read(Q);
	block=sqrt(n);
	int maxv=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		maxv=max(maxv,a[i]);
		solve(a[i],i);
	}
	T=sqrt(maxv);
	for(int i=1;i<=Q;i++){
		read(q[i].l),read(q[i].r);
		q[i].id=i;
	}
	pw[0]=1ll;
	for(int i=1;i<maxn;i++) pw[i]=pw[i-1]*2ll%(mod-1);
	for(int i=1;i<maxn;i++){
		pans[i].push_back({1,1});
	}
	sort(book+1,book+tot+1);
	tot=unique(book+1,book+tot+1)-(book+1);
	for(int i=1;i<=tot;i++)
		if(book[i]<T){
			Val[book[i]]=1;
			int sum=book[i];
			while(sum<maxn){
				sum*=book[i];
				Val[book[i]]++;
			}
			cnt[book[i]].resize(Val[book[i]]+1);
		}
	sort(q+1,q+Q+1,cmp);
	for(int i=1,l=1,r=0;i<=Q;i++){
		while(l>q[i].l) add(--l);
		while(r<q[i].r) add(++r);
		while(l<q[i].l) del(l++);
		while(r>q[i].r) del(r--);
		ll sum=ans;
		for(int j=1;j<=tot;j++){
			if(book[j]<T){
				ll czc=0;
				int czc2=0;
				for(int k=Val[book[j]];k>=1;k--){
					ll sc=(pw[cnt[book[j]][k]]+mod-2)%(mod-1)*pw[czc2]%(mod-1);
					czc=(czc+(ll)k*sc%(mod-1))%(mod-1);
					czc2+=cnt[book[j]][k];
				}
				sum=sum*qpow(book[j],czc,mod)%mod;
			}
			else{
				break;
			}
		}
		ANS[q[i].id]=sum;
	}
	for(int i=1;i<=Q;i++){
		write(ANS[i]),putchar('\n');
	}
	return 0;
}
/*
求的是幂次为t的方案数。
那么相当于对答案的贡献是 p^(t*cnt)
所以 cnt 的模数是 mod-1
要注意还是有点坑。
等一下我做快速幂有个 log 好吧，优化不下来了。
我可以把出现次数记录下来，在求答案的时候求吗？
质数有这么多，显然不大可能。
我感觉什么意义不是很大了，有的东西我暴力算吧。
根号分治：
>sqrt(n) 次数只有可能为 1，直接维护 
<sqrt(n) 我记录他们的个数，下来单独扫，100 个数，每个数均摊几个
能扫。 
大样例跑了 11 s。
G了，乐。 
现在卡到 2.8 s 了，更乐了。
n sqrt(n) log 其实还是比较大
他是
n 100 log 
这个快速幂真的几乎没法省，真无语了。
如果评测机能快的2的常数其实就好了。 
最后还是期望 68pts。 
*/
