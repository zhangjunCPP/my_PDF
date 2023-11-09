#include<bits/stdc++.h>
int n, q;
int Dis(int xl, int yl, int xr, int yr) {
	return abs(xl - xr) + std::min(abs(yl - yr), n + 1 - abs(yl - yr));
}
int main() {
	freopen("klein.in", "r", stdin);
	freopen("klein.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (; q; q--) {
		int xl, yl, xr, yr;
		scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
		int ans1 = Dis(xl, yl, xr, yr);
		int ans2 = Dis(xl, yl, n, yl) + Dis(0, n - yl, xr, yr) + 1;
		int ans3 = Dis(xl, yl, 0, yl) + Dis(n, n - yl, xr, yr) + 1;
//		printf("%d %d %d\n", ans1, ans2, ans3); 
		printf("%d\n", std::min({ans1, ans2, ans3})); 
	}
	return 0;
}

