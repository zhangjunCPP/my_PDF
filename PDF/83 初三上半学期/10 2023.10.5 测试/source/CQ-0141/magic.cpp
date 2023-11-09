#include<bits/stdc++.h>
using LL = long long;
const int maxn = 1e3 + 2, maxp = 40320, maxq = 5040;
LL F[maxp + 2];
int T[maxp + 2][8], id[maxp + 2];
LL mx[maxq + 2];
std::basic_string<int> v[maxq + 2];
int l[maxn], r[maxn];
LL C[maxn];
int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	int p[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	std::map<int, int> mp;
	int idt = 0, mpt = 0;
	do {
		idt++;
		for (int i = 0; i < 8; i++) T[idt][i] = p[i];
		int x = p[0], sum = 0;
		for (int i = 1; i < 8; i++)
			sum = sum * 10 + p[i], sum -= p[i] > x;
		if (! mp.count(sum)) mp[sum] = ++mpt;
		id[idt] = mp[sum];
		x = p[7], sum = 0;
		for (int i = 0; i < 7; i++)
			sum = sum * 10 + p[i], sum -= p[i] > x;
		if (! mp.count(sum)) mp[sum] = ++mpt;
		v[mp[sum]] += idt;
	} while (std::next_permutation(p, p + 8));
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%lld", &l[i], &r[i], &C[i]);
	memset(F, -0x3f, sizeof(F));
	LL finf = F[0];
	F[1] = 0;
	for (int i = 2; i <= n; i++) {
		memset(mx, -0x3f, sizeof(mx));
		for (int i = 1; i <= maxp; i++) mx[id[i]] = std::max(mx[id[i]], F[i]);
		for (int i = 1; i <= maxq; i++)
			for (int j : v[i]) F[j] = mx[i];
		for (int j = 1; j <= maxp; j++) {
			if (F[j] == finf) continue;
			int a = T[j][0], b = T[j][1], c = T[j][2], d = T[j][3], e = T[j][4], f = T[j][5], g = T[j][6], h = T[j][7];
			LL tot = 0;
			if (i > 1) {
				if (h < g && l[i] <= i - 1) tot += C[i];
				else if (h > g && i <= r[i - 1]) tot += C[i - 1]; 
			}
			if (i > 2) {
				if (h < f && l[i] <= i - 2) tot += C[i];
				else if (h > f && i <= r[i - 2]) tot += C[i - 2]; 
			}
			if (i > 3) {
				if (h < e && l[i] <= i - 3) tot += C[i];
				else if (h > e && i <= r[i - 3]) tot += C[i - 3]; 
			}
			if (i > 4) {
				if (h < d && l[i] <= i - 4) tot += C[i];
				else if (h > d && i <= r[i - 4]) tot += C[i - 4]; 
			}
			if (i > 5) {
				if (h < c && l[i] <= i - 5) tot += C[i];
				else if (h > c && i <= r[i - 5]) tot += C[i - 5]; 
			}
			if (i > 6) {
				if (h < b && l[i] <= i - 6) tot += C[i];
				else if (h > b && i <= r[i - 6]) tot += C[i - 6]; 
			}
			if (i > 7) {
				if (h < a && l[i] <= i - 7) tot += C[i];
				else if (h > a && i <= r[i - 7]) tot += C[i - 7]; 
			}
			F[j] += tot;
		}
	}
	LL ans = 0;
	for (int i = 1; i <= maxp; i++) ans = std::max(ans, F[i]);
	printf("%lld\n", ans);
	return 0;
}