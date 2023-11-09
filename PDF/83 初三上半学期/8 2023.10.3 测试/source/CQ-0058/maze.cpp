#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int Maxn=2e5+5;
struct adjacency_list{
	int nxt,t,val;
}tr[Maxn<<1];
int h[Maxn],tot;
inline void add(int x,int y,int z){
	tr[++tot]={h[x],y,z};h[x]=tot;
}
int a[Maxn],c[Maxn],d[Maxn];
int dis[Maxn];
void solve(int n,int m,int k){
	queue<int>q1,q2;
	for(int i=1;i<=k;++i)q1.emplace(a[i]);
	vector<int>vec;
	for(;!q1.empty();q1.swap(q2))
		while(!q1.empty()){
			int x=q1.front();q1.pop();
			vec.resize(0);
			for(int i=h[x];i;i=tr[i].nxt){
				int y=tr[i].t;
				if(~dis[y])vec.emplace_back(dis[y]+tr[i].val);
				else if(~d[y]){
					if(--d[y]==-1)q2.emplace(y);
				}
			}
			if(~dis[x])continue;
			sort(vec.begin(),vec.end());
			dis[x]=vec[c[x]];
		}
	cout<<dis[1]<<'\n';
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=k;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>d[i],c[i]=d[i];
	for(int i=1;i<=m;++i){
		int x,y,z;cin>>x>>y>>z;
		add(x,y,z);add(y,x,z);
	} 
	memset(dis,-1,sizeof dis);
	for(int i=1;i<=k;++i)dis[a[i]]=0,c[a[i]]=d[a[i]]=0;
	solve(n,m,k);
	return 0;
}
