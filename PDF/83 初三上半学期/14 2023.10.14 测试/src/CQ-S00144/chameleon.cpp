#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, K = 45;
struct node {
	double d;
	int b, op;
} a[N];
int n, k;
double L;
double jl[K];

bool cmp (node x, node y) {
	return x.d < y.d;
}

int main () {
	freopen ("chameleon.in", "r", stdin);
	freopen ("chameleon.out", "w", stdout);
	scanf ("%d %d %lf", &n, &k, &L);
	char flag;
	for (int i = 1; i <= n; ++i) {
		scanf ("%lf %d", &a[i].d, &a[i].b);
		cin >> flag;
		if (flag == 'D')
			a[i].op = 1;
		else
			a[i].op = 0;
	}
	sort (a + 1, a + n + 1, cmp);
	int l = 1, r = n, ltm = 0, rtm = 0;
	for (int i = 1; i <= n; ++i)
		if (!a[i].op)
			jl[a[i].b] += a[i].d;
		else {
			l = i;
			break;
		}
	for (int j = n; j; --j)
		if (a[j].op)
			jl[a[j].b] += (L - a[j].d);
		else {
			r = j;
			break;
		}
//	while (l < r) {
//		while (!a[l].op)
//			jl[a[i].b] += a[i].d, ++l;
//		while (a[l + 1].op)
//			++l;
//		jl[a[l].b] += (a[l + 1].d - a[l].d) / 2.0;
//		jl[a[l + 1].b] += (a[l + 1].d - a[l].d) / 2.0;
//		a[l + 1].op = 1;
//		int lb = a[l + 1].b;
//		a[l + 1].b = a[l].b;
//		a[l].b = a[l];
//		while (!a[r].op)
//			--r;
//		
//	}
	for (int i = 0; i < k; ++i)
		printf ("%.1lf\n", jl[i]);
	return 0;
} 
