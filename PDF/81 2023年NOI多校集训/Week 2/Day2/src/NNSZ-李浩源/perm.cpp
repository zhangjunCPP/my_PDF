
#include <bits/stdc++.h>

#define x first
#define y second

using namespace std; 

typedef long long LL;
typedef pair<int, int> PII;

const int N = 10000005, M = 200005;

int n, mod;
LL p[N], q[N];
LL f[N];
LL res;
bool vis[N];

void dfs(int u, int x)
{
	if (u > x)
	{
		for (int i = 1; i <= x; i ++ ) q[p[i]] = i;
		bool big = false;
		for (int i = 1; i <= x; i ++ )
			if (q[i] > p[i]) 
			{
				big = true;
				break;
			}
			else if (q[i] < p[i]) break;
			
		if (big) res = (res + 1) % mod;
		return;	
	}
	
	for (int i = 1; i <= x; i ++ )
		if (!vis[i])	
		{
			vis[i] = true;
			p[u] = i;
			dfs(u + 1, x);
			vis[i] = false;
		}
}

int main()
{
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	
	scanf("%d%d", &n, &mod);
	f[1] = f[2] = 0 % mod;
	f[3] = 1 % mod, f[4] = 7 % mod, f[5] = 47 % mod, f[6] = 322 % mod, f[7] = 2404 % mod, f[8] = 19778 % mod, f[9] = 180130 % mod, f[10] = 1809652 % mod;
	f[11] = 19940552 % mod; 
	LL ans = 0; 
	for (int i = 12; i <= n; i ++ )
	{
		res = 0;
		for (int j = 1; j <= i; j ++ ) vis[i] = 0;
		dfs(1, i);
		f[i] = res % mod;
	}
		
		
	for (int i = 1; i <= n; i ++ ) ans ^= f[i];
	
	printf("%lld\n", ans);
	return 0;
} 
