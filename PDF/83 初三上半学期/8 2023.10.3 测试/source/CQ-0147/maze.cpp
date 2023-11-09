#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int N=4e5+10;
void File(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
}
int n,m,k;
int s[N],d[N],du[N],du__[N];
//du__代表附近有几个出口 
int head[N],tot=0;
struct Node{
	int nex,v,w;
}a[N<<1];
void add(int u,int v,int w){
	a[++tot]={head[u],v,w};
	head[u]=tot;
	swap(u,v);
	a[++tot]={head[u],v,w};
	head[u]=tot;
}
int vis[N];
int main(){
	File();
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>s[i],vis[s[i]]=1;
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w); 
		du[u]++;
		du[v]++;
	}
	for(int i=1;i<=k;i++){
		int u=s[i];
		for(int j=head[u];j;j=a[j].nex){
			du__[a[j].v]++;
		}
	}
	vector<int>q;
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		if(d[i]<du__[i]){
			q.pb(i);
		}
	}
	if(q.empty()){
		cout<<-1;
		return 0;
	}
	cout<<-1;
	return 0;
} 
