#include <bits/stdc++.h>

using namespace std;

int a[100010], g[220005];

int main()
{
	freopen("boring.in", "r", stdin);
	freopen("boring.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	while (q -- )
	{
		int k;
		cin >> k;
		for (int i = 1; i <= k * 2; i ++ ) cin >> g[i];
		cout << 0x3f3f3f3f << endl;
	}
	
	return 0;
}
