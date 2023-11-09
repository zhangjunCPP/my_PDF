#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e6+10;
const int mod=998244353;
int n,head[N],cnt,flag,flag2,deg[N],num,turn,siz[N],ans;
int dp[20][1100000],U[N],V[N];
int my_pow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
struct node{
	int to,next;
}e[N<<1];
void add(int u,int v){e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;}
void dfs(int u,int fa){
//	cout<<u<<" "<<fa<<" "<<deg[u]<<" "<<deg[fa]<<" "<<num<<"\n";
//	++turn;
//	if(turn>32382){cout<<"EROOR\n";exit(0);}
	if(deg[u]){
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(v==fa)continue;
			dfs(v,u);
		}
	}else{
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(v==fa||deg[v])continue;
			if(!deg[u])++deg[u],++deg[v],++num,dfs(v,u);
			else dfs(v,u);
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(),flag=1;
	for(int i=1;i<n;++i){
		U[i]=read(),V[i]=read();
		if(U[i]>V[i])swap(U[i],V[i]);
		if(U[i]!=1)flag=0;
		add(U[i],V[i]),add(V[i],U[i]),++siz[U[i]],++siz[V[i]];
	}
	if(flag)printf("%d\n",n);
	else if(n<=20){
		dp[0][0]=1;
		for(int i=1;i<=n;++i){
			for(int s=0;s<(1<<n);++s){
				if(!dp[i-1][s])continue;
				if(((s>>(U[i]-1))&1)||((s>>(V[i]-1))&1))dp[i][s]=(dp[i][s]+dp[i-1][s])%mod;
				else{
					dp[i][s|(1<<(U[i]-1))]=(dp[i][s|(1<<(U[i]-1))]+dp[i-1][s])%mod;
					dp[i][s|(1<<(V[i]-1))]=(dp[i][s|(1<<(V[i]-1))]+dp[i-1][s])%mod;
				}
			}
		}
		int ans=0;
		for(int s=0;s<(1<<n);++s)ans=(ans+dp[n][s])%mod;
		printf("%d\n",ans);
	}
	return 0;
}
/*
7
7 2
7 6
1 2
7 5
4 7
3 5
*/
