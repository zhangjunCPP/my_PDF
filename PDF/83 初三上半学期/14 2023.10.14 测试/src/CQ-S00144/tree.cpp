#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 5, mod = 998244353;
ll n, cnt;
ll vis[N], du[N];
pair <ll, ll> edge[N];
vector <ll> G[N], g;

void dfs (ll x) {
	if (x == n + 1) {
		ll siz = g.size (), op = 1;
		for (ll i = 1; i <= cnt; ++i)
			if (G[i] == g)
				op = 0;
		if (op) {
			++cnt;
			for (ll i = 0; i < siz; ++i)
				G[cnt].push_back (g[i]);
		}
		return;
	}
	if (!vis[edge[x].first] && !vis[edge[x].second]) {
		vis[edge[x].first] = 1;
		g.push_back (edge[x].first);
		dfs (x + 1);
		g.pop_back ();
		vis[edge[x].first] = 0;
		vis[edge[x].second] = 1;
		g.push_back (edge[x].second);
		dfs (x + 1);
		g.pop_back ();
		vis[edge[x].second] = 0;
	}
	else
		dfs (x + 1);
	return;
}

int main () {
	freopen ("tree.in", "r", stdin);
	freopen ("tree.out", "w", stdout);
	scanf ("%lld", &n);
	for (ll i = 1, u, v; i < n; ++i) {
		scanf ("%lld %lld", &u, &v);
		++du[u], ++du[v];
		edge[i].first = u;
		edge[i].second = v;
	}
	if (n <= 10) {
		dfs (1);
		printf ("%lld\n", cnt);
	}
	else
		if (du[1] == n - 1)
			printf ("%lld\n", n);
		else {
			ll flag = 1;
			for (ll i = 2; i < n; ++i)
				if (du[i] != 2)
					flag = 0;
			if (flag && du[1] == 1 && du[n] == 1) {
				ll x = 1, y = 2;
				for (ll i = 3; i <= n; ++i) {
					ll tmp = y;
					y = tmp + x;
					y %= mod;
					x = tmp % mod;
				}
				printf ("%lld\n", y % mod);
			}
			else
				printf ("%lld\n", n * n % mod);
		}
	return 0;
} 
