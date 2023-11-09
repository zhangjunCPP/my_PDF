#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair <ll, ll>
const ll N = 2e5 + 5;
ll n, m, k;
ll vis[N], s[N], d[N];
vector <PII> G[N];

ll dfs (ll u) {
	ll mx = -1, tmpd = d[u], tmp = 0;
	vis[u] = 1;
	for (ll i = 0; i < G[u].size (); ++i) {
		PII v = G[u][i];
		if (!vis[v.first])
			if (s[v.first] == 1) {
				mx = max (mx, v.second);
				++tmp;
			}
			else {
				ll now = dfs (v.first);
				if (now != -1) {
					mx = max (mx, now + v.second);
					++tmp;
				} 
			}
	}
	if (tmpd > tmp)
		return -1;
//	printf ("%lld %lld\n", u, mx);
	return mx;
} 

int main () {
	freopen ("maze.in", "r", stdin);
	freopen ("maze.out", "w", stdout);
	scanf ("%lld %lld %lld", &n, &m, &k);
	for (ll i = 1, x; i <= k; ++i)
		scanf ("%lld", &x), s[x] = 1;
	for (ll i = 1; i <= n; ++i)
		scanf ("%lld", &d[i]);
	for (ll i = 1, u, v, w; i <= m; ++i) {
		scanf ("%lld %lld %lld", &u, &v, &w);
		G[u].push_back ({v, w});
		G[v].push_back ({u, w});
	}
	ll ans = dfs (1);
	printf ("%lld\n", ans);
	return 0;
} 
/*
�޽⣻ 
û�е����������ĳ��ߵ����ڵ�ĸ������ڵ���������ľ�����
���е�ĳ�����С�ڵ�����������

�н���ô���� 
�������ȶ�ס�����
......


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
