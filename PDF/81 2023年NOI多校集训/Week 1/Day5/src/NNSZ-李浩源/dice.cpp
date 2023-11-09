#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, k;
int a[105][7];
bool vis[105][1000005];

int main()
{
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	
	cin >> n >> k;
	
	
	if (n == 1)
	{
		puts("Yes");
		for (int i = 1; i <= 6; i ++ ) cout << k * i << ' ';
		return 0;
	}
	
	if (n == 2)
	{
		puts("Yes");
		for (int i = 1; i <= 6; i ++ ) a[1][i] = 3 ^ (2 * i); 
		a[2][1] = 3;
		vis[2][3] = 1;
		for (int i = 2; i <= 6; i ++ )
		{
			for (int x = 0; x <= N - 5; x ++ )
			{
				if (vis[2][x]) continue;
				bool ok = 1;
				for (int j = 1; j <= 6; j ++ )
					if ((a[1][j] ^ x) % k != 0)
					{
						ok = 0;
						break; 
					} 
				if (ok) 
				{
					a[2][i] = x;
					vis[2][x] = 1;
					break;
				}
			}
							
		}
			
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 1; j <= 6; j ++ )
				cout << a[i][j] << ' ';
			cout << endl;
		}
	}
	
	if (n == 3)
	{
		puts("Yes");
		for (int i = 1; i <= 6; i ++ ) a[1][i] = 3 ^ (2 * i); 
		a[2][1] = 3;
		vis[2][3] = 1;
		for (int i = 2; i <= 6; i ++ )
		{
			for (int x = 0; x <= N - 5; x ++ )
			{
				if (vis[2][x]) continue;
				bool ok = 1;
				for (int j = 1; j <= 6; j ++ )
					if ((a[1][j] ^ x) % k != 0)
					{
						ok = 0;
						break; 
					} 
				if (ok) 
				{
					a[2][i] = x;
					vis[2][x] = 1;
					break;
				}
			}
							
		}
		
		for (int i = 2; i <= 6; i ++ )
		{
			for (int x = 0; x <= N - 5; x ++ )
			{
				if (vis[3][x]) continue;
				bool ok = 1;
				for (int u = 1; u <= 2; u ++ )
					for (int y = 1; y <= 6; y ++ )
					{
						if ((a[u][y] ^ x) % k != 0)
						{
							ok = 0;
							break;
						}
					}
				if (ok)
				{
					a[3][i] = x;
					vis[3][x] = 1;
					break;
				}
			}
		}
		
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 1; j <= 6; j ++ )
				cout << a[i][j] << ' ';
			cout << endl;
		}
	}
	
	else puts("No");
	
	return 0; 
}
