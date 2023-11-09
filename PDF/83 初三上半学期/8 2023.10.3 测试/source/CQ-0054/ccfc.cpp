#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

void file() {
	freopen("ccfc.in", "r", stdin);
	freopen("ccfc.out", "w", stdout);
}

char s[N];
vector<int> G[N];
int kmp[N], in[N], out[N], ans[N];
int n, tim;

void dfs(int u) {
	in[u] = ++ tim;
	for(auto v : G[u]) dfs(v);
	out[u] = tim;
}
bool check(int u, int v) {
	return in[u] <= in[v] && out[v] <= out[u];
}
void BF() {
	for(int y = 3; y <= n; ++ y) 
		for(int i = 1; y - 3 * i >= 1; ++ i)
			ans[y] += (check(i, y) && check(i, y - i));
	
	for(int i = n; i >= 1; -- i)
		cout << ans[i] << " ";
}

void dfs2(int u) {
	bool fg = (u && u % 3 == 0 && check(u / 3, u) && check(u / 3, u - u / 3));
	for(auto v : G[u]) {
		ans[v] = ans[u] + fg;
		for(int i = u / 3 + 1; v - 3 * i >= 1; ++ i)
			ans[v] += (check(i, v) && check(i, v - i));
		dfs2(v);
	} 
}

signed main() {
//	freopen("ex_ccfc3.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
	file();
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> (s + 1), n = strlen(s + 1);
	reverse(s + 1, s + 1 + n);
	
	for(int i = 2, j = 0; i <= n; ++ i) {
		while(j && s[i] != s[j + 1]) j = kmp[j];
		if(s[i] == s[j + 1]) ++ j;
		kmp[i] = j;
	}
	for(int i = 1; i <= n; ++ i)
		G[kmp[i]].push_back(i);
	dfs(0);
	
	if(n <= 2000) return BF(), 0;
	
	dfs2(0);
	for(int i = n; i >= 1; -- i)
		cout << ans[i] << " ";
	return 0;
}
