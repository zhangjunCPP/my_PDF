/*
p1^t1 p2^t2.....
....
....
.....
����ÿ����������������

p^k+p^k2+p^k3+.....
p^(k+k2+k3+....+)
k1
k2
k3
k4
k5
����ÿ���Ӽ�ȡmin���
dp i j 
��ʾ�ڵ� i ����ʱ����С������ j �ķ�������
dp i j->dp i+1 min(j,t_i)
      ->dp i+1 j
������һ�� nqlogv�ĸ��Ӷ�
����ÿ��ֵ�������㣬�ݳ�һ�¡�
�ն���С�������ֵ����ô�𰸾��� >= ������ cnt �� 2^cnt
g(i) �պ����� 
f(i)=\sum g(i)
�����Ǻ�������
������������ʾ 
�������ĸ���Ϊ cnt1,�������ĸ���Ϊ cnt2��
��ô���� (2^cnt1-1)*(2^cnt2) ��Ϊȡ�ȵ�����һ����
�о����ڿ�����һ���ˡ�
2*10^5 �����᲻���е�ࡣ
4000 �������ᱻ����
��ÿ�ο���ѯ�ʺܴ�����䣬�������������������ݴζ����Դﵽ��ߡ�
�Ҹò������ CDQ �ɡ�
��������Ī�ӣ�
������ԡ�
һ�������ܻ��� 7 �������������� 7 n \sqrt n 
2 3 5 7 11 13 17 
����� log ��ʱ�������¼��㹱�ף��е㿨�ˡ�
����һ�������Ǵ����Ĺ��ס�
< ��������
�᷽���������һ�� 2
== ���ķ�����
Ҳ�����һ�� 2 
���ǲ��Ǻܺ�ά����
����һ���������Ĺ��ף�
�����ֻ��<=���ĸ������¼��㡣
�о������ˣ������һ�� log û���Ǹ� 7 �ĳ�����
1024*256 
һ���� 1e9 �е���ˣ����Ǹо��ܲ����� 
�ϴ��Ǹ��� 5e5 Ī�Ӷ��ܳ壬�� 2e5 ��Ӧ��Ҳ�С�
ֻ�Ƕ��˸������� 
3���ˣ���д�ɡ�
����68�ɡ� 
������������¼��������ܿ��ҡ� 
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
������ݴ�Ϊt�ķ�������
��ô�൱�ڶԴ𰸵Ĺ����� p^(t*cnt)
���� cnt ��ģ���� mod-1
Ҫע�⻹���е�ӡ�
��һ�������������и� log �ðɣ��Ż��������ˡ�
�ҿ��԰ѳ��ִ�����¼����������𰸵�ʱ������
��������ô�࣬��Ȼ������ܡ�
�Ҹо�ʲô���岻�Ǻܴ��ˣ��еĶ����ұ�����ɡ�
���ŷ��Σ�
>sqrt(n) ����ֻ�п���Ϊ 1��ֱ��ά�� 
<sqrt(n) �Ҽ�¼���ǵĸ�������������ɨ��100 ������ÿ������̯����
��ɨ�� 
���������� 11 s��
G�ˣ��֡� 
���ڿ��� 2.8 s �ˣ������ˡ�
n sqrt(n) log ��ʵ���ǱȽϴ�
����
n 100 log 
�����������ļ���û��ʡ���������ˡ�
���������ܿ��2�ĳ�����ʵ�ͺ��ˡ� 
��������� 68pts�� 
*/
