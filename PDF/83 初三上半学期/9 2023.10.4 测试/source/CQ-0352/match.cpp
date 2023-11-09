#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int k, q;
char s[N], p[N];

int main () {
	freopen ("match.in", "r", stdin);
	freopen ("match.out", "w", stdout);
	scanf ("%d", &k);
	cin >> s;
	scanf ("%d", &q);
	int lens = strlen (s);
	while (q--) {
		cin >> p;
		int lenp = strlen (p), ans = 0;
		for (int i = 0; i < lens - lenp + 1; ++i) {
			int flag = 1;
			for (int j = 0; j < lenp - k; ++j)
				if (s[i + j] != p[j])
					for (int o = j + k; o < lenp; ++o)
						if (s[i + o] != p[o])
							flag = 0;
			if (flag)
				++ans;
		}
		printf ("%d\n", ans);
	}
	return 0;
} 
