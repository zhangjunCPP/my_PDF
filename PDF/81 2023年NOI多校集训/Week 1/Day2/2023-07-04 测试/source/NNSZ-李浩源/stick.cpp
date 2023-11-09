#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	freopen("stick.in", "r", stdin);
	freopen("stick.out", "w", stdout);
	
	int Q;
	cin >> Q;
	while (Q -- )
	{
		int n, m;
		cin >>  n >> m;
		if (n <= 5)
		{
			if (n == 0) puts("0");
			else if (m == 0) puts("1");
			else if (n == 1) puts("0");
			else if (n == 2) 
			{
				if (m == 1) puts("1");
				else puts("0");
			}
			else if (n == 3)
			{
				if (m == 2 || m == 3) puts("1");
				else puts("0");
			}
			else if (n == 4) 
			{
				if (m == 3 || m == 4 || m == 5 || m == 6) puts("1");
				else puts("0");	
			} 
			else if (n == 5) 
			{
				if (m == 4 || m == 5 || m == 6 || m == 7 || m == 8 || m == 9 || m == 10) puts ("1");
				else puts("0");
			}
		}
	}
	return 0;
} 
