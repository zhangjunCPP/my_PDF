#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
const ll INF=0x3f3f3f3f;
int _;
int n,k,d;
int a[maxn];
ll dis[maxn];
bool vis[maxn];
struct edge{
	int to,w;
};
vector<edge> g[maxn];

struct node{
	int x;
	ll d;
	bool operator <(const node &x) const{
		return x.d<d;
	}
};

priority_queue<node>q;

void dijkstra(){
	for(int i=1;i<=n;i++){
		dis[i]=INF;
	}
	dis[0]=0;
	q.push({0,0});
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		
		if(vis[u])continue;
		vis[u]=1;
		
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			
			if(dis[v]>dis[u]+g[u][i].w){
				dis[v]=dis[u]+g[u][i].w;
				q.push({v,dis[v]});
			}
		}
	}
}


int main(){
    ios::sync_with_stdio(0);
    freopen("happy.in","r",stdin);
    freopen("happy.out","w",stdout);
    cin>>n>>k;
    
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	
    for(int i=1;i<=k;i++){
    	int num,w;
    	cin>>num>>w;
    	for(int j=1;j<=n;j++){
    		int x=upper_bound(a+1,a+n+1,a[j]+num-1)-a-1;
    	
    		g[j-1].push_back({x,w});
		}
	}
	
	cin>>d;
	
	for(int i=1;i<=n;i++){
		g[i-1].push_back({i,d});
		g[i].push_back({i-1,0});
	}
	
    dijkstra();
    
    for(int i=1;i<=n;i++){
    	cout<<dis[i]-dis[i-1]<<endl;
	}
    
    return 0 ^ _ ^ 0;
}

