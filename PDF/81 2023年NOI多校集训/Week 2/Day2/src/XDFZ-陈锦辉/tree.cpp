//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 1000001
#define mp make_pair
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int mod=1e9+7;
int qpow(int a,int b,int p){
	int ret=1;
	for(;b;b>>=1,a=1ll*a*a%p)if(b&1)ret=1ll*ret*a%p;
	return ret%p;
}
int n;
vector<int> G[MAXN],E[MAXN];//图，以及从 i 开始的直径。 
int d[MAXN];
int BFS(int S,vector<int>&ret){
	memset(d,0,sizeof d);
	queue<PII> Q;Q.push(mp(S,0));
	int T=0;
	for(PII u;!Q.empty();){
		u=Q.front();Q.pop();
		if((d[u.first]=d[u.second]+1)>d[T]) T=u.first;
		for(int v:G[u.first])if(v!=u.second)Q.push(mp(v,u.first));
	}
	for(int i=1;i<=n;i++)if(d[i]==d[T]) ret.push_back(i);
	return T;
}
int dBFS(int S,const bitset<30>&b,bool o){
	memset(d,0,sizeof d);
	queue<PII> Q;Q.push(mp(S,0));
	int T=0;
	for(PII u;!Q.empty();){
		u=Q.front();Q.pop();
		if((d[u.first]=d[u.second]+1)>d[T] && b[u.first]==o) T=u.first;
		for(int v:G[u.first])if(v!=u.second)Q.push(mp(v,u.first));
	}
	return T;
}
int dans=0;
void dfs(int pos,bitset <30>&b){
	if(pos>n){
		int S=dBFS(1,b,0),T=dBFS(S,b,0);
		int d0=d[T];
		S=dBFS(1,b,1),T=dBFS(S,b,1);
		d0=max(d0,d[T]);
		dans=(dans+d0-1)%mod;
		return;
	}
	dfs(pos+1,b);
	b[pos]=1;
	dfs(pos+1,b);
	b[pos]=0;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	if(n<=10){
		bitset<30> b(0u);
		dfs(1,b);
		printf("%d\n",dans);
		return 0;
	}
	vector<int> s;BFS(1,s);
	static int d1[MAXN];
	memcpy(d1,d,sizeof d1);
	int T=0;
	for(int S:s)T=BFS(S,E[S]);
	int D=d[T];
	printf("%d\n",D);
	for(int S:s)if(d1[S]==D)E[1].push_back(S);
	--D;
	LL ans=0;
	for(int i=1;i<=n;i++){
//		printf("%d: ",i);
		if(!E[i].empty()){
//			for(int x:E[i]) printf("%d ",x);
			int size=E[i].size();
			LL w=(LL)D*(qpow(2,size,mod)-1+mod)%mod*qpow(2,n-size-1,mod)%mod+(LL)(D-1)*qpow(2,n-size-1,mod)%mod;
			ans=(ans+w%mod)%mod;
		}
//		putchar('\n');
	}
	printf("%lld\n",ans);
	printf("%lld\n",ans*qpow(2,mod-2,mod)%mod);
	return 0;
}

