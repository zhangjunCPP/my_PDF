#include <bits/stdc++.h> 
#define mod(x) (x >= P && (x -= P))
#define mk make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 2e5 + 5, P = 998244353;
int n, m, mx, blk, tot;
int L = 1, R = 0;
int id[N], pri[N], vis[N], bel[N], a[N], dif[N][20];
ll pwp[N][20], pw[N], ans[N], now = 1;
vector<pii> fac[N];

struct node {
	int l, r, id;
	friend bool operator<(node a, node b) {
		return bel[a.l] ^ bel[b.l]? 
		bel[a.l] < bel[b.l]: (bel[a.l] & 1? a.r > b.r: a.r < b.r);
	}
} q[N];
ll Pow(ll a, ll b, ll mul = 1) {
	for (; b; b >>= 1, a = a * a  % P) {
		if (b & 1) mul = mul * a % P;
	}
	return mul;
} 
void init() {
	blk = sqrt(n);
	for (int i = 1; i <= n; i++) {
		bel[i] = (i - 1) / blk + 1;
	}
	for (int i = pw[0] = 1; i <= n; i++) {
		pw[i] = pw[i - 1] * 2 % (P - 1);
	}
	
	for (int i = 2; i <= mx; i++) {
		if (!vis[i]) {
			pri[id[i] = ++tot] = i;
			for (int j = pwp[tot][0] = 1; pwp[tot][j - 1] < mx
			; j++) {
				pwp[tot][j] = pwp[tot][j - 1] * i;
			}
		}
		for (int j = 1, t; j <= tot && (t = i * pri[j]) <= mx;
		 j++) {
			vis[t] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}
ll Exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = Exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
ll inv(ll a) {
	ll x, y;
	Exgcd(a, P, x, y);
	x += P;
	mod(x);
//	printf("inv %lld = %lld\n", a, x);
	return x;
}
inline void add(int i, int op) {
	for (pii tmp: fac[i]) {
		int num = tmp.fi, cnt = tmp.se;
		for (int i = 1; i <= cnt; i++) {
			if (pw[dif[num][i]] ^ pw[dif[num][i + 1]]) 
				now = now * inv(Pow(pwp[num][i]
			 , pw[dif[num][i]] - pw[dif[num][i + 1]] + P - 1)) % P;
			mod(now);
			dif[num][i] += op;
		}
		for (int i = cnt; i >= 1; i--) {
			if (pw[dif[num][i]] ^ pw[dif[num][i + 1]]) 
				now = now * Pow(pwp[num][i]
			 , pw[dif[num][i]] - pw[dif[num][i + 1]] + P - 1) % P;
			mod(now);
		}
	}
}
int main() {
	freopen("ddickky.in", "r", stdin);
	freopen("ddickky.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	init();
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		for (int j = 1; pri[j] * pri[j] <= x; j++) {
			if (x % pri[j] == 0) {
				pii tmp = mk(id[pri[j]], 0);
				while (x % pri[j] == 0) ++(tmp.se), x /= pri[j];
				fac[i].pb(tmp);
			}
		}
		if (x > 1) fac[i].pb(mk(id[x], 1));
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
	}
	sort(q + 1, q + 1 + m);
	for (int i = 1; i <= m; i++) {
		int l = q[i].l, r = q[i].r;
//		printf("//// %d %d\n", l, r);
		while (L > l) add(--L, 1);
		while (R < r) add(++R, 1)
//		, printf("now = %lld\n", now)
		;
		while (L < l) add(L++, -1);
		while (R > r) add(R--, -1);
		
		ans[q[i].id] = now;
	}
	for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
	return 0;
}
