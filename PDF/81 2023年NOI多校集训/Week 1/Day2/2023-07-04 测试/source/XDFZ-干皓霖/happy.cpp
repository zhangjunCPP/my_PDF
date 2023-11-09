#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll n, k, one;
ll t[N], sum[N], sp[N];
struct P {
	ll num, cost;
} p[N];

ll erfen (ll now, ll get) {
	get = t[now] + get;
	ll l = now, r = n;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (t[mid] < get) l = mid + 1;
		else r = mid;
	}
	if (t[l] <= get) return l;
	else return l - 1;
} 
void dfs (ll cnt) {
	if (cnt >= n) return;
	for (ll i = 1; i <= k; ++i) {
		ll to = erfen (cnt, p[i].num);
		ll tmp;
		if (p[i].cost % one) tmp = cnt + p[i].cost / one + 1;
		else tmp = cnt + p[i].cost / one;
		if (tmp > n) continue;
		if (p[i].cost % one) {
			if (sum[to] - sum[max (0ll, cnt - 1)] >= p[i].cost)
				sum[to] = sum[max (0ll, cnt - 1)] + p[i].cost;
			else continue;
		}
		else {
			if (sum[to] - sum[cnt] >= p[i].cost)
				sum[to] = sum[cnt] + p[i].cost;
			else continue;
		}
		for (int j = cnt; j <= tmp; ++j) 
			if (sum[j] - sum[j - 1] > one)
				sum[j] = sum[j - 1] + one;
		for (int j = tmp; j <= min (n, to); ++j)
			sum[j] = min(sum[j], sum[to]);
		if (to != cnt) dfs (to);
	}
	dfs (cnt + 1);
	return;
} 

int main () {
	freopen ("happy.in", "r", stdin);
	freopen ("happy.out", "w", stdout);
	scanf ("%lld %lld", &n, &k);
	for (ll i = 1; i <= n; ++i)
		scanf ("%lld", &t[i]);
	for (ll i = 1; i <= k; ++i)
		scanf ("%lld %lld", &p[i].num, &p[i].cost);
	scanf ("%lld", &one);
	if (k == 0) {
		for (ll i = 1; i <= n; ++i)
			printf ("%lld\n", one);	
		return 0;
	}
	for (ll i = 1; i <= n; ++i)
		--p[i].num, sum[i] = i * one;
	dfs (0);
	for (ll i = 1; i <= n; ++i)
		printf ("%lld\n", min (one, sum[i] - sum[i - 1]));
	return 0;
} 

