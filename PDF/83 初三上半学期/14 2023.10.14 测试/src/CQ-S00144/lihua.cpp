#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, flag = 0;
int sum[N][35], t[N][35];
char a[N][35], s[N][35];

int main () {
	freopen ("lihua.in", "r", stdin);
	freopen ("lihua.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%s", a[i]);
		int lena = strlen (a[i]);
		sum[i][0] = a[i][0] - 'a';
		for (int j = 1; j < lena; ++j)
			sum[i][j] = sum[i][j - 1] + 1000 + a[i][j] - 'a';
		if (sum[i][lena - 1] != (lena - 1) * (1000 + a[i][0] - 'a') + a[i][0] - 'a')
			flag = 0;
	}
	scanf ("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf ("%s", s[i]);
		int lens = strlen (s[i]);
		t[i][0] = s[i][0] - 'a';
		for (int j = 1; j < lens; ++j)
			t[i][j] = t[i][j - 1] + 1000 + s[i][j] - 'a';
		if (t[i][lens - 1] != (lens - 1) * (1000 + s[i][0] - 'a') + s[i][0] - 'a')
			flag = 0;
	}
	if (flag) {
		for (int k = 1; k <= q; ++k) {
			int ans = 0, lens = strlen (s[k]);
			for (int i = 1; i <= n; ++i) {
				++ans;
				if (a[i][0] == s[k][0]) {
					int lena = strlen (a[i]);
					ans += min (lena, lens);
					if (lena == lens)
						break;
				}
			}
			printf ("%d\n", ans);
		}			
	}
	else {
		for (int k = 1; k <= q; ++k) {
			int ans = 0, lens = strlen (s[k]);
			for (int i = 1; i <= n; ++i) {
				int lena = strlen (a[i]), lt = 0;
				for (int j = 0; j < lens; ++j)
					if (sum[i][j] == t[k][j])
						lt = j;
					else
						break;
				++ans;
				if (lt || sum[i][0] == t[k][0])
					ans += lt + 1;
				if (lt == lena - 1 && lena == lens)
					break;
			}
			printf ("%d\n", ans);
		}
	}
	return 0;
} 
