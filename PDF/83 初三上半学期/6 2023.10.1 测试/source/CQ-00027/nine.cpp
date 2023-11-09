#include <bits/stdc++.h>
using namespace std;
int k, x, y;

int main () {
	freopen ("nine.in", "r", stdin);
	freopen ("nine.out", "w", stdout);
	scanf ("%d %d %d", &k, &x, &y);
	int sum = abs (x) + abs (y);
	if (k == 1) {
		printf ("%d\n", sum);
		for (int i = 1; i <= abs (x); ++i) {
			int tmp = i;
			if (x < 0)
				tmp = -tmp;
			printf ("%d 0\n", tmp);
		}
		for (int i = 1; i <= abs (y); ++i) {
			int tmp = i;
			if (y < 0)
				tmp = -tmp;
			printf ("%d %d\n", x, tmp);
		}
		return 0;
	}
	if (!(k & 1) && (sum & 1))
		printf ("-1");
	else {
		printf ("%d\n", (sum / k) + (sum - sum / k * k));
		
	}
	return 0;
}
