#include <bits/stdc++.h>

#define x first
#define y second

using namespace std; 

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1000005, mod = 1e9 + 7;

int n;
int f[N][2];
int h[N], e[N], ne[N], idx; 
vector<int> q[2]; 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int j(int x)
{
	LL res = 0;
	for (int i = 1; i <= n; i ++ ) res += i;
	return res;
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	memset(h, -1, sizeof h);
	for (int i = 1; i < n; i ++ )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	} 
	
	
	printf("%d\n", j(n - 1) * 2 % mod);
	
	return 0;
}	
