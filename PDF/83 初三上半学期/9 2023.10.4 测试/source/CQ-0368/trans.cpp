//看着恰好x个国家不好搞?那先考虑至多x个国家再繁衍回来 
//看着是个数据点分治题
//如何表示一个状态呢?
//放当前一个的时候只关心前面的哪些是自己的.
//故设DPi,j,s表示i个国家,前j个点,j属于的集合为s,方案数是多少
//转移考虑枚举前一个集合和新开一个集合?
//还有个问题:枚举了之后我怎么知道能否满足j的集合?那再来一维吧
//显然会炸
//并不关心前一个集合是什么,所以DP不需要多一维
//好像还是一个集合一个集合地加比较方便.
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
auto qpow=[](ll p,ll t){ll res=1;for(;t;t>>=1,p=p*p%mod)if(t&1)(res*=p)%=mod;return res;};
ll C(ll n,ll m){
	m=min(m,n-m);
	if(m<0)return 0;
	ll A=1,B=1;
	for(;m;(A*=n--)%=mod,(B*=m--)%=mod);
	return A*qpow(B,mod-2)%mod;
}
int T,n,m,k;
namespace solve1{
	ll dp[15][1<<12],w[1<<12],dif[15][15],sam[15][15];
	void clr(){
		memset(dp,0,sizeof(dp)),fill_n(w,1<<n,1);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(i!=j)dif[i][j]=sam[i][j]=1;
	}
	void work(){
		clr();
		for(int u,v,df,sm;m--;)
		scanf("%d%d%d%d",&u,&v,&df,&sm),
		(dif[u][v]*=df)%=mod,(sam[u][v]*=sm)%=mod,
		(dif[v][u]*=df)%=mod,(sam[v][u]*=sm)%=mod;
		for(int s=1;s<(1<<n);s++){
			w[s]=1;
			for(int u=1;u<=n;u++)
			if(s>>u-1&1)for(int v=1;v<u;v++)
			(w[s]*=s>>v-1&1?sam[u][v]:dif[u][v])%=mod;
		}dp[0][0]=1;
		for(int s=0;s<(1<<n);s++)
		for(int i=0;i<n;i++)
		for(int is=(1<<n)-1^s,ad=is;ad;ad=ad-1&is)
		(dp[i+1][s|ad]+=dp[i][s]*w[ad])%=mod;
		ll ans=0;
		for(int i=1;i<=n;i++)
		(ans+=dp[i][(1<<n)-1]*C(k,i))%=mod;
		cout<<ans<<endl;
	}
}
namespace solve2{
	ll dp[110][110],tmp[110];
	struct edge{int v,dif,sam;};
	vector<edge>G[110];
	void dfs(int u,int dad){
		memset(dp[u],0,sizeof(dp[u]));
		dp[u][1]=1;
		for(auto e:G[u])if(e.v!=dad){
			dfs(e.v,u);
			copy_n(dp[u]+1,n,tmp+1);
			memset(dp[u],0,sizeof(dp[u]));
			for(int i=1;i<=n;i++)
			for(int j=1;i+j<=n;j++)
			(dp[u][i+j]+=tmp[i]*dp[e.v][j]%mod*e.dif)%=mod,
			(dp[u][i+j-1]+=tmp[i]*dp[e.v][j]%mod*e.sam)%=mod;
		}
	}
	void work(){
		for(int u,v,a,b;m--;)scanf("%d%d%d%d",&u,&v,&a,&b),G[u].push_back({v,a,b}),G[v].push_back({u,a,b});
		dfs(1,0);
		ll ans=0;
		for(int i=1;i<=n;i++)
		(ans+=dp[1][i]*C(k,i))%=mod;
		cout<<ans<<endl;
	}
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int T;for(cin>>T;T--;){
		cin>>n>>m>>k;
		if(n<=12)solve1::work();
		else solve2::work();
	}
	return 0;
}
