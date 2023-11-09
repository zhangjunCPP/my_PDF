#include<bits/stdc++.h>
using ll = long long;
const int N = 30;
int n;
ll a[N];
namespace Subtask1 {
	ll ans = 0x3f3f3f3f3f3f3f3f;
	std::vector<int> stp;
	std::vector<int> ANS;
	void DFS(int w, ll a, ll b, ll c) {
		if (w > n) {
			if (std::max({a, b, c}) - std::min({a, b, c}) < ans) {
				ans = std::max({a, b, c}) - std::min({a, b, c});
				ANS = stp;
			}
		} else {
			stp.push_back(1);
			DFS(w + 1, a + ::a[w], b, c);
			stp.pop_back();
			stp.push_back(2);
			DFS(w + 1, a, b + ::a[w], c);
			stp.pop_back();
			stp.push_back(3);
			DFS(w + 1, a, b, c + ::a[w]);
			stp.pop_back();
		}
	}
	void solve() {
		DFS(1, 0, 0, 0);
		for (int i : ANS) {
			printf("%d " , i);
		}
	}
}
namespace Subtask2 {
	std::map<std::pair<ll, ll>, std::vector<int> > mp;
	std::vector<int> stp;
	void DFS1(int w, ll a, ll b, ll c) {
		if (w > n / 2) {
			if (! mp.count({a - b, a - c})) {
				mp[{a - b, a - c}] = stp;
			}
			return ;
		} else {
			stp.push_back(1);
			DFS1(w + 1, a + ::a[w], b, c);
			stp.pop_back();
			stp.push_back(2);
			DFS1(w + 1, a, b + ::a[w], c);
			stp.pop_back();
			stp.push_back(3);
			DFS1(w + 1, a, b, c + ::a[w]);
			stp.pop_back();
		}
	}
	void DFS2(int w, ll a, ll b, ll c) {
		if (w > n) {
			if (mp.count({b - a, c - a})) {
				for (int i : mp[{b - a, c - a}]) {
					printf("%d ", i);
				}
				for (int i : stp) {
					printf("%d ", i);
				}
				exit(0);
			}
			return ;
		} else {
			stp.push_back(1);
			DFS2(w + 1, a + ::a[w], b, c);
			stp.pop_back();
			stp.push_back(2);
			DFS2(w + 1, a, b + ::a[w], c);
			stp.pop_back();
			stp.push_back(3);
			DFS2(w + 1, a, b, c + ::a[w]);
			stp.pop_back();
		}
	}
	void solve() {
		DFS1(1, 0, 0, 0);
		DFS2(n / 2 + 1, 0, 0, 0);
	}
}
int main() {
	freopen("treasure.in", "r", stdin);
	freopen("treasure.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%lld", &a[i++]));
	if (n <= 0) {
		Subtask1::solve();
	} else {
		Subtask2::solve();
	}
	return 0;
} 
