#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,ll> tp;
const int N=2e5+5;
int n,m,K;
int d[N];
ll f[N];
bool is[N],ins[N];
vector<tp> e[N];
void dfs(int k,int fa){
	ins[k]=true;
	if(is[k]) {f[k]=0;return ;}
	vector<ll> box;box.clear();
	for(tp u:e[k]){
		int to=u.first;
		if(to==fa) continue;
		if(!ins[to]) dfs(to,k);
		if(f[to]!=-1) box.push_back(f[to]+u.second);
	}
	sort(box.begin(),box.end());
//	cout<<k<<" :\n";
//	for(int u:box)
//		cout<<u<<' ';cout<<'\n';
	if(d[k]>=box.size()) f[k]=-1;
	else f[k]=box[d[k]];
	return ;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>K;
	for(int i=1,u;i<=K;i++)
		cin>>u,is[u]=true;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,
		e[u].push_back({v,w}),
		e[v].push_back({u,w});
	dfs(1,0);
	cout<<f[1];
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
