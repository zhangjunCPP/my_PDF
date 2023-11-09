#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
}

struct Edge {
	int nex, to, dis;
} edge[N << 1];
int head[N], d[N], s[N], dis[N];
priority_queue<pii, vector<pii>, greater<pii> > q;
multiset<int> st[N];
int n, m, k, elen = 1;
bool vis[N];

void addedge(int u, int v, int w) {
	edge[++ elen] = (Edge) {head[u], v, w}, head[u] = elen;
	edge[++ elen] = (Edge) {head[v], u, w}, head[v] = elen;
}
void dijkstra() {
	for(int i = 1; i <= n; ++ i) dis[i] = 2e9 + 2;
	for(int i = 1; i <= k; ++ i)
		dis[s[i]] = 0, q.push(pii(0, s[i]));
	while(q.size()) {
		int u = q.top().se; q.pop();
		if(vis[u]) continue; vis[u] = true;
		
		for(int e = head[u], v; v = edge[e].to, e; e = edge[e].nex) {
			int cur = dis[u] + edge[e].dis;
			if(cur > dis[v]) continue;
					
			if(st[v].size() == d[v] + 1) {
				int mx = *st[v].rbegin();
				if(mx > cur) {
					auto it = st[v].find(mx);
					st[v].erase(it);
					st[v].insert(cur);
				}
			} else st[v].insert(cur);
			
			if(st[v].size() == d[v] + 1)
				dis[v] = *st[v].rbegin(),
				q.push(pii(dis[v], v));
		}
	}
}

signed main() { 
//	freopen("ex_maze4.in", "r", stdin);
	file();
	n = read(), m = read(), k = read();
	for(int i = 1; i <= k; ++ i) s[i] = read();
	for(int i = 1; i <= n; ++ i) d[i] = read();
	for(int i = 1, u, v, w; i <= m; ++ i)
		u = read(), v = read(), w = read(),
		addedge(u, v, w);
		
	dijkstra();
	if(dis[1] > 2e9) puts("-1");
	else printf("%d\n", dis[1]);
	return 0;
}
/*
15:15 skim over 
15:40 T1
16:10 strike by T2
16:30 doubt! skip T2
17:00 T3 but doubt
17:10 find T3's bug through fc.
17:30 T4 GG,fxxk!
18:30 T2 GGG,fxxk!
*/
