#include<bits/stdc++.h>
using ll = long long;
const int N = 2e5 + 10;
int n;
std::pair<ll, int> a[N];
std::vector<int> used;
void DFS(int w) {
	if (w == -1) {
		return ;
	}
	for (int i = used[w] + 1; i <= (w ? used[w - 1] - 1 : n); printf("%d ", i), i++);
	DFS(w - 1);
	printf("%d ", used[w]);
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i].first), a[i].second = i;
	}
	std::sort(a + 1, a + n + 1, [](std::pair<ll, int> x, std::pair<ll, int> y) {
		return x.first > y.first;
	});
	int now = n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].second < now) {
			ans += 1ll * a[i].first * (now - a[i].second), now = a[i].second;
			used.push_back(a[i].second);
		}
	}
	printf("%lld\n", ans);
	DFS(int(used.size() - 1)); 
	return 0;
}

