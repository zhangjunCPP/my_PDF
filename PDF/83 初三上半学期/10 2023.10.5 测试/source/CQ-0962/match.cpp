#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
}

set<int> G[N];
int n, m;

void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i) G[i].clear();
	for(int i = 1, u, v; i <= m; ++ i)
		u = read(), v = read(),
		G[u].insert(v), G[v].insert(u);
		
	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = max(ans, (int)G[i].size());
	if(ans < 3) {
		for(int i = 1; i <= n; ++ i)
			if(G[i].size() == 2) {
				int u = *G[i].begin(), v = *G[i].rbegin();
				if(G[u].find(v) != G[u].end())
					{ ans = 3; break; }
			} 
	}
	printf("%d\n", ans);
}

signed main() {
	file();
	int T = read();
	while(T --) solve(); 
	return 0; 
} 
// 14:36
