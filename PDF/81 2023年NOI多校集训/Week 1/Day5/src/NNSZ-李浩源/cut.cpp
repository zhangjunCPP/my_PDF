#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
int a[N];
int g[N], cnt;
bool vis[N];
map<pair<int, int>, int> mp;

int main()
{
	freopen("cut.in", "r", stdin);
	freopen("cut.out", "w", stdout);
	 
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	for (int i = 1; i <= n; i ++ )
		if (a[i] == 0)
		{
			if (a[i - 1] == 1 && !vis[i - 1]) 
			{
				g[ ++ cnt ] = i - 1;
				res += 2;
				vis[i - 1] = vis[i] = 1;
			}
			else if (a[i + 1] == 1 && !vis[i + 1])
			{
				g[ ++ cnt] = i;
				res += 2;
				vis[i] = vis[i + 1] = 1;
			}
			
			else
			{
				g[ ++ cnt ] = i;
				res ++;
				vis[i] = 1;	
			} 		
		}
	
	for (int i = 1; i <= n; i ++ )	
		if (!vis[i])
			g[ ++ cnt ] = i;
			
	printf("%d %d\n", res, cnt);
	
	sort(g + 1, g + cnt + 1);
	
	for (int i = 1; i <= cnt; i ++ ) cout << g[i] << ' ';
			
	return 0;
}
