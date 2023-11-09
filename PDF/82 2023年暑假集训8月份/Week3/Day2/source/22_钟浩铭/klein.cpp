#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0'); 
}
int n,T;
vector<int> G[MAXN<<1];
inline int w(int i,int j){return i*(n+1)+j;}
bool vis[MAXN<<1];
int dis[MAXN<<1];
priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > q;
inline void Dijkstra(int s){
	while(!q.empty()) q.pop();
	q.push(make_pair(0,s)); 
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis)); dis[s]=0;
	while(!q.empty()){
		pair<int,int> t=q.top(); q.pop();
		int u=t.second; 
		if(vis[u]) continue; 
		vis[u]=1;
		for(auto v:G[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	read(n,T);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j>=1){
				G[w(i,j)].push_back(w(i,j-1));
				G[w(i,j-1)].push_back(w(i,j));
			}
			if(i>=1){
				G[w(i,j)].push_back(w(i-1,j));
				G[w(i-1,j)].push_back(w(i,j));
			}
		}
	}
	for(int i=0;i<=n;i++) 
		G[w(i,0)].push_back(w(i,n)),
		G[w(i,n)].push_back(w(i,0));
	for(int j=0;j<=n;j++)
		G[w(0,j)].push_back(w(n,n-j)),
		G[w(n,n-j)].push_back(w(0,j));
	int x1,y1,x2,y2; 
	while(T--){
		read(x1,y1,x2,y2);
		Dijkstra(w(x1,y1));
		write(dis[w(x2,y2)]); putchar('\n');
	}
	return 0;
}

