#include <bits/stdc++.h>
using namespace std;
int p, s, cnt, tot;

int main () {
	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);
	scanf ("%d %d", &p, &s);
	if (p & 1) {
		printf ("Impossible\n");
		return 0;
	}
	int x = p >> 1, flag = 0, tmp;
	for (int i = 1; i <= x - 1; ++i)
		if (i * (x - i) >= s) {
			flag = 1, tmp = i;
			break;
		}	
	if (x - 1 > s || flag == 0) {
		printf ("Impossible\n");
		return 0;
	}
	tmp = max (tmp, x - tmp);
	int cha = tmp * (x - tmp) - s;
	cnt = cha / (tmp - 1);
	++cnt;
	for (int i = 1; i <= (x - tmp); ++i)
		printf ("2");
	printf ("3");
	for (int i = 2; i <= tmp; ++i) {
		if (cnt > 1) {
			--cnt;
			cha -= tmp - 1;
			printf ("3");
			if (cnt == 1) {
				printf ("1");
				++i;
			}
			--i;
			++tot;
		}
		else
			if (tmp - i + 1 == cha) {
				printf ("31");
				--cnt;
				s = 0;
				++tot;
			}
			else
				printf ("2");
	}
	printf ("3");
	for (int i = tot + 2; i <= (x - tmp); ++i)
		printf ("2");
	printf ("3");
	for (int i = 2; i <= tmp; ++i)
		printf ("2");
	printf ("\n");
	return 0;
} 
