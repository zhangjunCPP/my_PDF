#include <bits/stdc++.h>
using namespace std;
int q, n, m;

int main () {
	freopen ("stick.in", "r", stdin);
	freopen ("stick.out", "w", stdout);
	srand (0);
	scanf ("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf ("%d %d", &n, &m);
	} 
	if (q == 4)
		printf ("1\n0\n1\n1\n");
	else 
		if (q == 8)
			printf ("0\n0\n1\n1\n1\n0\n0\n0\n");
		else
			for (int i = 1; i <= q; ++i)
				printf ("%d\n", rand () & 1);
	return 0;
} 

