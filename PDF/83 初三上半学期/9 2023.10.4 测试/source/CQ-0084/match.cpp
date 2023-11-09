#include <bits/stdc++.h> 

using namespace std;

const int N = 2e5 + 5, M = 6e5 + 5;
// 数组大小
// 数组大小
// 数组大小
// 数组大小 
int k, n, m, divi/*分隔符*/ = 26;
struct SA {
	// must all m
	int s[M], x[M], y[M], c[M], st[M][20], sa[M], rk[M], lg[M], n, m;
	void csort() {
		for (int i = 1; i <= n; i++) c[x[i]]++;
		for (int i = 1; i <= m; i++) c[i] += c[i - 1];
		for (int i = n; i >= 1; i--) sa[c[x[y[i]]]--] = y[i];
		for (int i = 1; i <= m; i++) c[i] = 0;
	}
	void ssort() {
		for (int i = 1; i <= n; i++) x[i] = s[i], y[i] = i;
		csort();
		for (int k = 1; k <= n; k <<= 1) {
			int cnt = 0;
			for (int i = n - k + 1; i <= n; i++) 
				y[++cnt] = i;
			for (int i = 1; i <= n; i++) 
				if (sa[i] > k) y[++cnt] = sa[i] - k;
			csort();
			swap(x, y), x[sa[cnt = 1]] = 1;
			for (int i = 2; i <= n; i++) {
				x[sa[i]] = y[sa[i]] == y[sa[i - 1]]
				 && y[sa[i] + k] == y[sa[i - 1] + k]?
				 cnt: ++cnt;
			}
			if ((m = cnt) == n) break;
		}
		for (int i = 1; i <= n; i++) rk[sa[i]] = i;
		st[1][0] = 0;
		for (int i = 1, k = 0; i <= n; i++) {
			if (rk[i] == 1) { k = 0; continue; }
			if (k) k--;
			int j = sa[rk[i] - 1];
			while (i + k <= n && j + k <= n 
			 && s[i + k] == s[j + k]) k++;
			st[rk[i]][0] = k;
		}
//		for (int i = 1; i <= n; i++) {
//			printf("sa[%d] = %d, lcp %d\n", i, sa[i], st[i][0]);
//		}
		
		for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
		for (int j = 1; 1 << j <= n; j++) {
			for (int i = 1; i + (1 << j) - 1 <= n; i++) {
				st[i][j] = min(st[i][j - 1]
				, st[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int rmq(int l, int r) { // 是 sa 上的 
		if (l == r) return n - l + 1;
		l = rk[l], r = rk[r];
		if (l > r) swap(l, r);
		l++;
		int Lg = lg[r - l + 1];
		return min(st[l][Lg], st[r - (1 << Lg) + 1][Lg]);
	}
} z, f;
// 数组大小
// 数组大小
// 数组大小
// 数组大小
char ss[N], tt[N];
int qlen[N], sst[N];
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%s%d", &k, ss + 1, &m);
	
	
	n = strlen(ss + 1), z.n = n;
	for (int i = 1; i <= n; i++) {
		z.s[i] = ss[i] - 'a' + 1;
	}
	
	for (int i = 1; i <= m; i++) {
		scanf("%s", tt + 1);
		qlen[i] = strlen(tt + 1);
		z.s[++z.n] = ++divi;
		sst[i] = z.n + 1;
		for (int j = 1; j <= qlen[i]; j++) {
			z.s[++z.n] = tt[j] - 'a' + 1;
		}
	}
	z.m = divi;
	
	z.ssort();
	
	f = z;
	reverse(f.s + 1, f.s + 1 + n);
	for (int i = 1; i <= m; i++) {
		reverse(f.s + sst[i], f.s + sst[i] + qlen[i]);
	}
	f.ssort();
	
	for (int i = 1; i <= m; i++) {
		int len = qlen[i], res = 0;
		for (int j = 1; j + len - 1 <= n; j++) {
			int L1 = z.rmq(j, sst[i]);
			int L2 = f.rmq(n - (j + len - 1) + 1, sst[i]);
			
			if (L1 + L2 + k >= len) {
//				printf("//	%d %d(%d, %d), sst = %d\n"
//				, j, j + len - 1, L1, L2, sst[i]);
				res++;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
