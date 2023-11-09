#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=1e6+3;
int n, m, U[N], V[N], d[N];
vector<int> e[N];
map<pair<int, int>, int> vis;

int pd() {
	vis.clear();
	for (int i=1; i<=n; i++) e[i].clear();
	for (int i=1; i<=m; i++) {
		e[U[i]].push_back(V[i]);
		e[V[i]].push_back(U[i]);
		vis[{U[i], V[i]}]=vis[{V[i], U[i]}]=1;
	}
	for (int i=1; i<=n; i++) {
		if (e[i].size()==2&&vis[{e[i][0], e[i][1]}]) return 1;
	}
	return 0;
}

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int T=read();
	while (T--) {
		for (int i=1; i<=n; i++) d[i]=0;
		n=read(), m=read();
		for (int i=1; i<=m; i++) {
			U[i]=read(), V[i]=read();
			d[U[i]]++, d[V[i]]++;
		}
		int ans=0;
		for (int i=1; i<=n; i++) ans=max(ans, d[i]);
		if (ans<=2&&pd()) ans=3;
		printf("%d\n", ans);
	}
	return 0;
}
