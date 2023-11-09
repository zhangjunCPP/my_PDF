#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const long long inf = 1e18;
const int max_n = 1e5 + 10;
const int max_k = 510;

int n, k;
int T[max_n];
int len_1, len_2;
long long cost_1, cost_2;
int min_time_1, min_time_2;
long long once;
long long last_sum = 0;

int main() {
	
	freopen("happy.in", "r", stdin);
	freopen("happy.out", "w", stdout);
	
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &T[i]);
	}
	if (k == 2) {
		scanf("%d %lld", &len_1, &cost_1);
		scanf("%d %lld", &len_2, &cost_2);
	}
	else {
		for (int i = 1; i <= k; ++i) {
			int len, cost;
			scanf("%d %d", &len, &cost);
		}
	}
	scanf("%lld", &once);
	
	if (k != 2) {
		while (n--) {
			printf("%lld\n", once);
		}
		return 0;
	}
	
	if (len_1 > len_2) {
		swap(cost_1, cost_2);
		swap(len_1, len_2);
	}
	min_time_1 = ceil((double)cost_1 / once);
	min_time_2 = ceil((double)cost_2 / once);
	
	last_sum = min(once, min(cost_1, cost_2));
	printf("%lld\n", last_sum);
	for (int t = 2; t <= n; ++t) {
		long long sum = 0;
		int idx = 1;
		int dist = T[t] - T[idx];
		while (dist >= len_2) {
			sum += cost_2;
			if (dist == len_2) {
				sum += once;
			}
			idx = upper_bound(T + 1, T + n + 1, T[idx] + len_2) - T;
			dist = T[t] - T[idx];
		}
		while (dist >= len_1) {
			sum += cost_1;
			if (dist == len_1) {
				sum += once;
			}
			idx = upper_bound(T + 1, T + n + 1, T[idx] + len_1) - T;
			dist = T[t] - T[idx];
		}
		if (t - idx + 1 >= min_time_1) {
			sum += cost_1;
		}
		else {
			sum += once * (t - idx + 1);
		}
		
		printf("%lld\n", sum - last_sum);
		last_sum = sum;
	}
	
	return 0;
}

