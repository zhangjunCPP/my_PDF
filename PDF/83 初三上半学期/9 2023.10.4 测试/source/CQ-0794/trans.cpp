#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const int maxn=105;
inline ll qpow(ll a,ll b){
	ll ret=1ll;
	for( ; b ; b>>=1ll){
		if(b&1ll) ret=ret*a%mod;
		a=a*a%mod;
	}
	return ret;
} 
struct line{
	int x,y;
	ll d,s;
}a[maxn];
inline ll C(int n,int m){
	if(n<m) return 0;
	ll ans=1ll;
	for(ll i=max(m,n-m)+1;i<=n;i++) ans=ans*i%mod;
	ll inv=1ll;
	for(ll i=1;i<=min(n-m,m);i++) inv=inv*i%mod;
	return ans*qpow(inv,mod-2)%mod; 
}
inline ll A(int n,int m){
	if(n<m) return 0;
	ll ans=1ll;
	for(ll i=n-m+1;i<=n;i++) ans=ans*i%mod;
	return ans; 
}
ll ans=0; 
int n,m,k;
int belong[maxn];
inline void dfs1(int now,int col){
	if(now==n+1){
		ll sum=1ll;
		for(int i=1;i<=m;i++){
			if(belong[a[i].x]==belong[a[i].y]){
				sum=sum*a[i].s%mod;
			}
			else{
				sum=sum*a[i].d%mod; 
			}
		}
		ans=(ans+sum)%mod;
		return ;
	}
	for(int i=1;i<=col;i++){
		belong[now]=i;
		dfs1(now+1,col);
	}
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout); 
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		bool f=1;
		for(int i=1;i<=m;i++){
			scanf("%d%d%lld%lld",&a[i].x,&a[i].y,&a[i].d,&a[i].s);
			if(a[i].d!=1ll || a[i].s) f=0;
		} 
		if(n==2){
			ll sum1=1ll,sum2=1ll;
			for(int i=1;i<=m;i++){
				sum1=sum1*a[i].d%mod;
				sum2=sum2*a[i].s%mod;
			} 
			printf("%lld\n",(A(k,2)*sum1%mod+k*sum2%mod)%mod);
			continue;
		}
		if(n<=6 || k<=4){
			ans=0ll;
//			for(int i=1;i<=min(n,k);i++){
//				dfs1(1,i);
//			}
			dfs1(1,k);
			printf("%lld\n",ans);
			continue;
		}
	} 
	return 0;
}
/*
2 1 1 1
2 1 2 2
2 1 2 0
1 2 1 1
大致懂了题目什么意思
k 有点大，是可以弄小一点的。
直接枚举有几个国家分中心，然后乘上组合系数就可以了。
最后 k 与 n 同阶
这个数据真的看的我眼花。
英雄之所以为英雄，便是能置之死地而后生。
T1已经死了，那就在T2多拿点分吧。
n=2 那就没什么说的，直接要么全是一个国家，要么分开，可以做+10pts
然后呢？ 死了。
diffi=1,samei=0：
一定全部都是敌人，没什么大用。
对于m较小的数据
可以枚举m条边，是敌人还是朋友
就形成了多个连通块。
这多个联通块，直接用这么多种颜色染色即可
n^cnt 
diff_i=1 就是全部都是敌人，那么，直接 i^n 之和即可。 
好像不能直接染色。 
因为他们不是互为敌人，真的恶心。
2^m
i^n 
那就枚举n呗，还是染色烦死了。
 5 17 9
3 2 2 4
3 2 7 7
4 3 6 2
4 5 8 8
2 3 7 0
4 1 2 0
3 5 0 8
4 2 0 8
3 4 4 4
3 5 8 7
1 2 3 6
3 1 1 3
3 5 6 4
3 1 8 1
3 4 1 7
4 2 2 8
4 2 4 6

742914571
然后那20pts的档写了，炸了，人都崩了。
怪不得密码是这套题不简单。
最后期望：30pts 
*/
