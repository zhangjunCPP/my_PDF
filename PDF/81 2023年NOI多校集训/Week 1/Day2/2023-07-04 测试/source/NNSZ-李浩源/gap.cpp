#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 110, mod = 998244353;

int n;
int a[N];
bool st[N];
LL ans;

void dfs(int u, int last)
{
	if (u >= n) 
	{
		ans = (ans + 1) % mod; 
		return;
	}
	
	for (int i = 1; i <= n; i ++ ) 
		if (i != last + 1 && i != last -  1 && !st[i]) 
		{ 
			st[i] = true;
			dfs(u + 1, i);
			st[i] = false;
		}
}

int main()
{
	freopen("gap.in", "r", stdin);
	freopen("gap.out", "w", stdout); 
	cin >> n;
	if (n == 0) puts("0");
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	dfs(0, -1);
	cout << ans % mod << endl;
	return 0;
}
