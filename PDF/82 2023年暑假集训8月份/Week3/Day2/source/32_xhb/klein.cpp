#include<bits/stdc++.h>
#define fi first
#define se second
#define mem(a,b)  memset(a,b,sizeof(a))
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w; 
}
typedef pair<int,int> PII;
const int N=1e3+1;
int n,q;
bool vis[N*N];
vector<int> a[N*N];                      
inline int Get(int x,int y){return x*(n+1)+y+1;}
inline void add(int x,int y){
//	if((x==24&&y==13)||(x==35&&y==24))printf("fu:%d %d\n",x,y);
	a[x].push_back(y);a[y].push_back(x);
} 
inline void FRE(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
}
inline int  bfs(int x,int y){
	priority_queue<PII,vector<PII>,greater<PII> > Q;
	mem(vis,0);
	Q.push({0,x});
//	printf("%d %d\n",x,y);
	while(!Q.empty()){
		int u=Q.top().se,w=Q.top().fi;
//		if(x==13)printf("te:%d\n",u);
		Q.pop();
		if(u==y)return w;
		for(int v:a[u]){
			Q.push({w+1,v});
		} 
	}
	return 0;
}
int main(){
	FRE();
	n=read(),q=read(); 
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			if(j>=1) add(Get(i,j),Get(i,j-1));
			else add(Get(i,0),Get(i,n));
			if(i>=1) add(Get(i,j),Get(i-1,j));
			else add(Get(0,j),Get(n,n-j));
		}                                          
	}
	while(q--){
		int xx=read(),yy=read(),xc=read(),yc=read();
		printf("%d\n",bfs(Get(xx,yy),Get(xc,yc)));
	}
	return 0;
}
