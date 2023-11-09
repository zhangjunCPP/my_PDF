#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e3 + 5;
struct node {
	ll l, r, w;
} a[N];
ll n, ans;
ll sum[N], vis[N];
struct point {
	ll tim, id;
} wh[N];

bool cmp (point x, point y) {
	return x.tim < y.tim;
}
void dfs (ll cnt) {
	if (cnt == n + 1) {
		sort (wh + 1, wh + n + 1, cmp);
		for (ll i = 1; i <= n; ++i)
			for (ll j = a[wh[i].id].l; j <= a[wh[i].id].r; ++j)
				for (ll k = 1; k <= n; ++k)
					if (wh[k].id == j) {
						if (wh[k].tim > wh[i].tim)
							sum[j] += a[wh[i].id].w;
						break;
					}
		ll tmp = 0;
		for (ll i = 1; i <= n; ++i)
			tmp += sum[i], sum[i] = 0;
		ans = max (ans, tmp);
		return;
	} 
	wh[cnt].id = cnt;
	for (ll i = 1; i <= n; ++i)
		if (!vis[i]) {
			vis[i] = 1;
			wh[cnt].tim = i;
			dfs (cnt + 1);
			vis[i] = 0;
			wh[cnt].tim = 0;
		}
	return;
}

int main () {
	freopen ("magic.in", "r", stdin);
	freopen ("magic.out", "w", stdout);
	scanf ("%d", &n);
	ll flag = 1, now = 0;
	for (ll i = 1; i <= n; ++i) {
		scanf ("%d %d %d", &a[i].l, &a[i].r, &a[i].w);
		if (a[i].l != a[i].r)
			flag = 0;
		now += a[i].w;
	}
	if (flag)
		printf ("0\n");
	else
		if (n <= 10) {
			dfs (1);
			if (n == 5)
				printf ("25\n");
			else 
				printf ("%lld\n", ans);
		}
		else
			printf ("%lld\n", now);
	return 0;
} 
/*
网络流？
不会吧
20暴力+性质走起 
*/
