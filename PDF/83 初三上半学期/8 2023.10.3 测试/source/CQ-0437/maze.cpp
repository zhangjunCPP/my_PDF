#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define ULL unsigned long long
	#define In inline
	#define Re register
	#define f(a,b,i) for(Re int i=a;i<=b;i++)
	#define ff(a,b,i) for(Re int i=a;i<b;i++)
	#define f_(a,b,i) for(Re int i=a;i>=b;i--)
	#define ff_(a,b,i) for(Re int i=a;i>b;i--)
	const int inf=0x3f3f3f3f;
	const int INF=0x7f7f7f7f;
	const LL infll=0x3f3f3f3f3f3f3f3fll;
	const LL INFll=0x7f7f7f7f7f7f7f7fll;
	template<typename T>void read(T &x){
		x=0;
		bool fl=0;
		char ch=getchar();
		while(ch<'0'||'9'<ch){
			if(ch=='-')fl=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9'){
			x=(x<<3)+(x<<1)+(ch^48);
			ch=getchar();
		}
		x=fl?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

#define N 200050

int n,m,k;

int ed[N];

int d[N];
int cost[N];

struct Edge{
	int v,w;
	Edge(){}
	Edge(int v,int w):v(v),w(w){}
};

vector<Edge>e[N];

multiset<int>s[N];

LL dis[N];
bool vis[N];

In void sol(){
	queue<int>q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	f(1,k,i){
		q.emplace(ed[i]);
		dis[ed[i]]=0;	
//		vis[ed[i]]=1;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(dis[u]){
			auto it=s[u].begin();
			f(1,d[u],i)it++;
			dis[u]=*it;
			s[u].clear();	
		}
		for(auto i:e[u]){
			s[i.v].insert(dis[u]+i.w);
			if(!cost[i.v])q.emplace(i.v);
			else cost[i.v]--;
		}
	}
}

int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	read(n,m,k);
	f(1,k,i)read(ed[i]);
	f(1,n,i)read(d[i]),cost[i]=d[i];
	int u,v,w;
	f(1,m,i){
		read(u,v,w);
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	sol();
//	f(1,n,i)printf("%lld ",dis[i]);
//	puts("");
	printf("%lld",dis[1]==infll?-1:dis[1]);
	return 0;
}
/*
5 8 3
2 3 5
2 0 1 1 2
1 2 1
2 3 2
3 4 5
2 5 3
4 5 2
5 1 3
3 5 2
4 1 1

*/

