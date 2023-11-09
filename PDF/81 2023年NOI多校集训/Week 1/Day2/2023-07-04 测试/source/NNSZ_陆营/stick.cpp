#include <iostream>
#include <vector>
using namespace std;

const int max_n = 510;
const int max_m = 2510;

struct Node {
	int flag = -1;
	vector <int> p;
};

Node dp[max_n][max_m];
int limit[max_n];

void solve(const int n, const int m);

int main() {
	
	freopen("stick.in", "r", stdin);
	freopen("stick.out", "w", stdout);
	
	for (int i = 2; i <= 501; ++i) {
		limit[i] = limit[i - 1] + i - 1;
	}
	
	int T;
	scanf("%d", &T);
	if (T > 3000) {
		while (T--) {
			int n, m;
			scanf("%d %d", &n, &m);
			printf("%d\n", m <= limit[n]);
		}
		return 0;
	}
	
	dp[1][0].flag = 1;
	dp[2][0].flag = 1;
	dp[2][0].p.push_back(2);
	dp[2][1].flag = 1;
	
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		solve(n, m);
		printf("%d\n", dp[n][m].flag);
	}
	
	return 0;
}

void solve(const int n, const int m) {
	if (~dp[n][m].flag) {
		return;
	}
	if (m > limit[n]) {
		dp[n][m].flag = 0;
		return;
	}
	
	dp[n][m].flag = 0;
	for (int i = 0; i <= m && !dp[n][m].flag; ++i) {
		solve(n - 1, i);
		if (!dp[n - 1][i].flag) {
			continue;
		}
		
		int maxi = n - 1 + i;
		if (maxi == m) {
			dp[n][m].flag = 1;
			for (const int & j : dp[n - 1][i].p) {
				dp[n][m].p.push_back(j);
			}
			break;
		}
		
		int sum = 0;
		int j;
		for (j = 0; j < dp[n - 1][i].p.size(); ++j) {
			if (maxi - dp[n - 1][i].p[j] == m) {
				dp[n][m].flag = 1;
				break;
			}
			sum += dp[n - 1][i].p[j];
		}
		if (sum < n - 1 && maxi - 1 == m) {
			dp[n][m].flag = 1;
			dp[n][m].p.push_back(2);
			for (const int & j : dp[n - 1][i].p) {
				dp[n][m].p.push_back(j);
			}
			break;
		}
		
		if (!dp[n][m].flag) {
			continue;
		}
		for (int k = 0; k < dp[n - 1][i].p.size(); ++k) {
			dp[n][m].p.push_back(dp[n - 1][i].p[k]);
			if (k == j) {
				++dp[n][m].p[k];
			}
		}
	}
}

