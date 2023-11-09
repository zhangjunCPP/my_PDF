#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int inf=2e9+114;

const int N=2e5+3;
int n, m, k, dis[N], vis[N], d[N];

#define pii pair<int, int>
priority_queue<pii, vector<pii>, greater<pii> > q;
priority_queue<int> mx[N];

struct edge {
	int to, w;
};
vector<edge> e[N];

int main() {
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	n=read(), m=read(), k=read();
	for (int i=1; i<=n; i++) dis[i]=inf, mx[i].push(-1);
	for (int i=1; i<=k; i++) {
		int x=read();
		q.push({0, x}), dis[x]=0;
	}
	for (int i=1; i<=n; i++) d[i]=read();
	for (int i=1; i<=m; i++) {
		int u=read(), v=read(), w=read();
		e[u].push_back({v, w}), e[v].push_back({u, w});
	}
	for (int i=1; i<=n; i++) {
		if (d[i]>=e[i].size()) vis[i]=1;
	}
	while (!q.empty()) {
		int u=q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (auto i:e[u]) {
			int v=i.to;
			if (vis[v]) continue;
			int w=dis[u]+i.w;
			if (!d[v]) {
				if (w>=dis[v]) continue;
				if (w<mx[v].top()) {
					dis[v]=mx[v].top(); mx[v].pop();
					mx[v].push(w);
				}
				else dis[v]=w;
				q.push({dis[v], v});
			}
			else {
				d[v]--;
				mx[v].push(w);
			}
		}
	}
	if (dis[1]==inf) puts("-1");
	else printf("%d\n", dis[1]);
	return 0;
}
