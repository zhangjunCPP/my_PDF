#include <iostream>
#include <cstdio>
#include <algorithm>

const int MAXN = 500005;

int n;
int a[MAXN];

// 二分答案。
// 但是怎么做呢？

int main()	{
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	freopen("comp.in", "r", stdin);
	freopen("comp.out", "w", stdout);
	
	std::cin >> n;
	for(int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	
	int cnt = 0;
	
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			for(int k = j + 1; k <= n; ++k) {
				for(int l = k + 1; l <= n; ++l) {
					if(a[i] == a[k] && a[j] == a[l])    {
						++cnt;
					}
				}
			}
		}
	}
	
	std::cout << cnt * 4 << std::endl;
	
	return 0;
}

