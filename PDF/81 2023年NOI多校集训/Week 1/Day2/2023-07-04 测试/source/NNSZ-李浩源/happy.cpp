#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100010, M = 510; 

int n, k;
int tim[N], one;
LL d[N];
LL res;

struct tj
{
	int num, cost;
}s[N];

int main()
{
	freopen("happy.in", "r", stdin);
	freopen("happy.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &tim[i]);
	for (int i = 1; i <= k; i ++ ) 
	{
		int num, cost;
		scanf("%d%d", &num, &cost);
		s[i] = {num, cost};	
	} 
	scanf("%d", &one);
	
	for (int i = 1; i <= n; i ++ ) d[i] = d[i - 1] + one;
	if (k == 0) for (int i = 1; i <= n; i ++ ) cout << d[i] - d[i - 1] << endl;
	else for (int i = 1; i <= n; i ++ ) cout << d[i] - d[i - 1] << endl;
	
	return 0;
}
