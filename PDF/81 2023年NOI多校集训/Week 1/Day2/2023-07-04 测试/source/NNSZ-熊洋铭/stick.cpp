#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

std::set <int> s[501];
std::set <int> t[501];
std::vector <int> a;

void dfs(int n, int last, int k)	{
	if(k == 0)	{
		int sum = 0, tot = 0;
		for(auto i : a)	{
			tot += i * sum;
			sum += i;
		}
		s[n].insert(tot);
		return;
	}
	if(last == 0)	++last;
	for(int i = last; i <= k; ++i)	{
		a.push_back(i);
		dfs(n, i, k - i);
		a.pop_back();
	}
}

int main()	{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cerr.tie(nullptr);
	freopen("stick.in", "r", stdin);
	freopen("stick.out", "w", stdout);
	
	for(int i = 1; i <= 50; ++i)	{
		dfs(i, 0, i);
	}
	
//	for(int i = 1; i <= 10; ++i)    {
//		for(auto j : s[i])  {
//			std::cerr << j << ' ';
//		}
//		std::cerr << std::endl;
//	}

//	for(int i = 51; i <= 500; ++i)  {
//		for(auto j : s[i - 1])  {
//			s[i].insert(j + i - 1);
//		}
//		for(int j = 1; j * 2 <= i; ++j)  {
//			s[i].insert(j * (i - j));
//		}
//		s[i].insert(0);
//	}

//	for(int i = 51; i <= 100; ++i)  {
//		for(int j = 1; j < i; ++j)  {
//			int x = j, y = i - j;
//			for(auto p : s[x])  {
//				for(auto q : s[y])  {
//					s[i].insert(p + q + x * y);
//				}
//			}
//		}
//		s[i].insert(0);
//		std::cerr << i << std::endl;
//	}
	
//	for(int i = 1; i <= 10; ++i)    {
//		for(auto j : s[i])  {
//			std::cerr << j << ' ';
//		}
//		std::cerr << std::endl;
//	}
	
	int tt;
	std::cin >> tt;
	while(tt--)	{
		int n, m;
		std::cin >> n >> m;
		std::cout << s[n].count(m) << '\n';
	}
	return 0;
}

