#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 5;
const int base = 1145141;

void file() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
}

char s[N], t[N];
int K, q, n, m;
ull hs[N], ht[N], pw[N];

ull calcs(int l, int r) { if(l > r) return 0; return hs[r] - hs[l - 1] * pw[r - l + 1]; }
ull calct(int l, int r) { if(l > r) return 0; return ht[r] - ht[l - 1] * pw[r - l + 1]; }
bool check(int sl, int sr, int tl, int tr) { return calcs(sl, sr) == calct(tl, tr); } 

signed main() {
//	freopen("ex_match3.in", "r", stdin);
	file();
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for(int i = pw[0] = 1; i < N; ++ i) pw[i] = pw[i - 1] * base;
	
	cin >> K >> (s + 1) >> q, n = strlen(s + 1);
	for(int i = 1; i <= n; ++ i) hs[i] = hs[i - 1] * base + s[i];
	
	if(n <= 300) {
		for(int i = 1; i <= q; ++ i) {
			cin >> (t + 1), m = strlen(t + 1);
			
			int ans = 0;
			for(int j = 1; j + m - 1 <= n; ++ j) {
				int l = m + 1, r = 0;
				for(int k = 1; k <= m; ++ k)
					if(t[k] != s[j + k - 1])
						l = min(l, k), r = max(r, k);
				if(r - l < K) ++ ans;
			}
			printf("%d\n", ans);
		}
		return 0;
	}
	if(n <= 2000) {
		for(int i = 1; i <= q; ++ i) {
			cin >> (t + 1), m = strlen(t + 1);
			
			for(int i = 1; i <= m; ++ i) ht[i] = ht[i - 1] * base + t[i];
			
			int ans = 0;
			for(int j = 1; j + m - 1 <= n; ++ j) {
				int l = 0, r = m, L = 0, R = 0;
				while(l <= r) {
					int mid = (l + r) >> 1;
					if(check(j, j + mid - 1, 1, mid))
						L = mid, l = mid + 1;
					else r = mid - 1;
				}
				l = 0, r = m;
				while(l <= r) {
					int mid = (l + r) >> 1;
					if(check(j + m - 1 - mid + 1, j + m - 1, m - mid + 1, m))
						R = mid, l = mid + 1;
					else r = mid - 1;
				}
				
				if((m - R) - (L + 1) < K) ++ ans;
			}
			printf("%d\n", ans);
		}
		return 0;
	}
	for(int i = 1; i <= q; ++ i)
		puts("0");
	return 0; 
}
