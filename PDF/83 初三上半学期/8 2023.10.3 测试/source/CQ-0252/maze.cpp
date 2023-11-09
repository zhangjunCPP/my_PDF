#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
#define i64 __int128
const int N = 3e5+5;
const int inf = 2e9+1;
int n,m,k,s[N],sp[N],d[N],vis[N],dis[N]; 
struct node{
	int u,dis;
	bool operator < (const node &x) const{
		return x.dis<dis;
	}
}; 
struct G{
	int v,w;
};
vector<G> e[N];
priority_queue<int,vector<int>,less<int> > re[N];
priority_queue<node> q;
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) dis[i] = inf;
	for(int i=1;i<=k;i++) cin >> s[i],dis[s[i]] = 0,q.push({s[i],0}),sp[s[i]] = 1;
	for(int i=1;i<=n;i++) cin >> d[i]; 
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].pb({v,w}),e[v].pb({u,w});
	} 
	while(q.size()){
		int u = q.top().u;q.pop();
		if(vis[u]) continue; 
		vis[u] = 1;
		for(G g:e[u]){
			int v = g.v,w = g.w,siz = re[v].size();
			if(sp[v]) continue;
			if(siz<d[v]) re[v].push(dis[u]+w);
			else if(siz==d[v]){
				re[v].push(dis[u]+w);
				dis[v] = re[v].top(); 
				if(!vis[v]) q.push({v,dis[v]});
			}else{
				if(dis[v]>dis[u]+w){
					re[v].pop();
					re[v].push(dis[u]+w);
					dis[v] = re[v].top();
					if(!vis[v]) q.push({v,dis[v]});
				}
			}
		}
	} 
	if(dis[1]<inf) cout << dis[1];
	else cout << -1;
	return 0;
}
//����һ�����ȶ��У�
//d�����ݷ�Χ��ƭ�˵ģ�sum_deg = 2*m����˱�����set���ܸ��Ӷ���O(mlogm)
//���Ƚ�s�������ȶ��У���ans[u] = 0
//����������s��ÿ���ߣ���ans[u]+w�������v�ļ��ϣ�
//��siz[v]<=kʱ������ 
//��siz[v]=k+1ʱ���ó����ֵ
//��siz[v]>k+1ʱ��ά��ǰk+1С�������С�����롣
//������dij:
//����ÿ���㣬����౻����deg�Σ�ÿ��log�����帴�Ӷ�O(mlogn).
//���հ��� 

