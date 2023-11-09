#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N];

int main () {
	freopen ("ccfc.in", "r", stdin);
	freopen ("ccfc.out", "w", stdout);
	cin >> s;
	int len = strlen (s);
	for (int i = 1; i <= len; ++i)
		printf ("0 ");
	return 0;
} 
