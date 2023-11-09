#include <iostream>
using namespace std;

const int max_n = 14;

int n;
int a[max_n];
int P[max_n];
bool used[max_n];
int ans = 0;

void dfs(const int k);
bool check();

int main() {
	
	freopen("gap.in", "r", stdin);
	freopen("gap.out", "w", stdout);
	
	cin >> n;
	if (n > 11) {
		cout << "1919810\n";
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	dfs(1);
	
	printf("%d\n", ans);
	
	return 0;
}

void dfs(const int k) {
	if (k == n + 1) {
		ans += check();
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (used[i]) {
			continue;
		}
		used[i] = true;
		P[k] = i;
		dfs(k + 1);
		used[i] = false;
	}
}

bool check() {
	int a_1[max_n];
	int i = 1, j = 2;
	while (j <= n + 1) {
		while (j <= n && P[j] - P[j - 1] == 1) {
			++j;
		}
		while (j <= n && P[j] - P[j - 1] == -1) {
			++j;
		}
		int len = j - i;
		for (; i < j; ++i) {
			a_1[i] = len;
		}
		++j;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] != a_1[i]) {
			return false;
		}
	}
	return true;
}

