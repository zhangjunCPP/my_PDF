#include<bits/stdc++.h>
#define ppc(x) __builtin_popcount(x)
#define lowbit(x) (-x & x)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const int M = 1 << 7 | 5;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
}

ll c[N];
int l[N], r[N];
int n;

bool cmax(ll &a, ll b) { return a < b ? a = b, 1 : 0; }

bool vis[N];
void BF() {
	vector<int> vec;
	for(int i = 0; i < n; ++ i)
		vec.push_back(i);
	ll ans = 0;
	do {
		ll res = 0;
		for(int i = 1; i <= n; ++ i) vis[i] = true;
		for(int i = 0; i < n; ++ i) {
			int cur = vec[i] + 1, cnt = 0;
			vis[cur] = false;
			for(int j = l[cur]; j <= r[cur]; ++ j)
				cnt += vis[j];
			res += 1ll * cnt * c[cur];
		}
		ans = max(ans, res);
	} while(next_permutation(vec.begin(), vec.end()));
	printf("%lld\n", ans);
}

ll dp[1 << 20 | 5];
void BF2() {
	for(int i = 0; i < (1 << n); ++ i)
		dp[i] = -1e16;
	dp[(1 << n) - 1] = 0;
	for(int s = (1 << n) - 1; s >= 0; -- s)
		for(int i = 0; i < n; ++ i)	
			if(s >> i & 1) {
				ll cost = 0;
				for(int j = l[i + 1]; j <= r[i + 1]; ++ j)
					if(s >> (j - 1) & 1) cost += c[i + 1];
				cost -= c[i + 1];
				cmax(dp[s ^ (1 << i)], dp[s] + cost);
			} 
	printf("%lld\n", dp[0]);
}

signed main() {
//	freopen("magic2.in", "r", stdin);
//	freopen("data.in", "r", stdin);
	file();
	n = read();
	for(int i = 1; i <= n; ++ i)
		l[i] = read(), r[i] = read(), c[i] = read();
		
	if(n <= 10) return BF(), 0;
	if(n <= 20) return BF2(), 0;
	return 0; 
} 
/*
16:00 GGG
16:10:
5
1 3 3
2 4 4
1 3 5
2 4 3
3 5 2
17:10 GG...
*/
