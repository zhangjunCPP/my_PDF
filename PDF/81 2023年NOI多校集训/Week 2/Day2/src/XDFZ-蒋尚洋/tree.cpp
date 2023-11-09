//不妨只考虑黑点的贡献,白点乘2即可(反色) 
//容斥会发生什么?
//考虑令Pi表示满足链长至少为i的涂色方案集合,好像容斥不了,系数不知道
//考虑用期望*方案数?
//算了...还是正常做吧.
//如何保证白色点的链长不超过x?
//钦定了黑端点后,白色有的是选涂,有的是必涂 
//emm...考虑到黑白必有一个>=n/2,一个<=n/2...好像没什么性质 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
auto qpow=[](ll p,ll t){ll ret=1;for(;t;t>>=1,p=p*p%mod)if(t&1)(ret*=p)%=mod;return ret;};
int n;
vector<int>G[1000010];
namespace case1{
	int dis[20][20];
	void solve(){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=1e9;
		for(int i=1;i<=n;i++)for(int v:G[i])dis[i][v]=1;
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		ll ans=0;
		for(int s=0;s<(1<<n);s++){
			int tmp=0;
			for(int u=1;u<=n;u++)
			for(int v=1;v<=n;v++)
			if(~((s>>u-1)^(s>>v-1))&1)tmp=max(tmp,dis[u][v]);
			(ans+=tmp)%=mod;
		}
		cout<<ans;
	}
}
namespace taskA{
	//此时最长链的两个端点必有一个在最左或最右
	void solve(){
		//钦定1为黑防止算重,最后乘2 
		ll ans=0;
		for(int i=n/2+1;i<n;i++){
			int xpos=n-i+1;
			if(i==xpos)(ans+=(i-1)*2)%=mod;
			else (ans+=qpow(2,i-xpos-1)*(i-1)*3)%=mod; 
		}
		(ans+=(n-1)*qpow(2,n-2))%=mod;
		if(~n&1)(ans+=n/2-1)%=mod;
		cout<<ans*2%mod;
	}
	//写完发现树或许与这个有关?
	//若最长链两个端点均不在直径端点处,那么直径就已经比他们长了 
	//若存在多条直径则答案必为直径长 
}
namespace taskB{
	void solve(){cout<<qpow(2,n)*2%mod;}
}
namespace taskinf{
	struct bfs{
		vector<int>dis;
		int mxver,mxcnt;
		bfs(int s):dis(n+5,-1){
			dis[s]=0;static int q[1000010];
			for(int i=0,tp=0,u=s;i<=tp;u=q[++i])
			for(int v:G[u])if(dis[v]==-1)dis[v]=dis[u]+1,q[++tp]=v;
			mxver=max_element(begin(dis),end(dis))-begin(dis);
			mxcnt=count(begin(dis),end(dis),dis[mxver]);
		}
	};
	int len;
	void solve(){
		int A=bfs(1).mxver,B=bfs(A).mxver;
		auto Adis=bfs(A),Bdis=bfs(B);len=Adis.dis[B];
		if(Adis.mxcnt>1||Bdis.mxcnt>1){cout<<qpow(2,n)*len%mod;return;}
		ll ans=qpow(2,n-2)*len;//直径端点同色 
		//最后输出记得乘2
		vector<vector<int>>nodea(n+5),nodeb(n+5);
		for(int i=1;i<=n;i++)nodea[Adis.dis[i]].push_back(i),nodeb[Bdis.dis[i]].push_back(i);
		unordered_set<int>ableA,ableB;//able中的任何一个被染成和对应端点同色都可以,所以如果两个able有交集就直接成功,否则就只有1种情况失败 
		for(int i=len-1,com=0;i;i--){//转化为至少的方案数求和 
			for(int x:nodea[i])ableA.insert(x),com=com||ableB.count(x);//x!=B
			for(int x:nodeb[i])ableB.insert(x),com=com||ableA.count(x);//x!=A
			if(com)(ans+=qpow(2,n-2))%=mod;
			else if(!ableA.empty()||!ableB.empty()){
				int sum=(int)ableA.size()+(int)ableB.size();
				(ans+=qpow(2,n-2-sum)*(qpow(2,sum)-1))%=mod;
			} 
		}cout<<ans*2%mod;//牛逼,一遍成功 
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	bool flagA=true;
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u),flagA=flagA&&abs(u-v)==1;
//	if(n<=10){case1::solve();return 0;}
//	if(flagA){taskA::solve();return 0;}
//	if((int)G[1].size()==n-1){taskB::solve();return 0;}
	taskinf::solve();
	return 0;
}
