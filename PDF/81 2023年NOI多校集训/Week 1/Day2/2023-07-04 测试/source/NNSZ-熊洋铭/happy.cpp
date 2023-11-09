#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

typedef long long LL;

int n, k;
std::vector <int> t;
struct Ticket	{
	int num, cost;
	Ticket(const int _num, const int _cost) :
		num(_num), cost(_cost) {}
};
std::vector <Ticket> p;
int s;

void init()	{
	std::cin >> n >> k;
	t.resize(n + 1);
	for(int i = 1; i <= n; ++i)	{
		std::cin >> t[i];
	}
	p.push_back(Ticket(0, 0));
	for(int i = 1; i <= k; ++i)	{
		int _num, _cost;
		std::cin >> _num >> _cost;
		p.push_back(Ticket(_num, _cost));
	}
	std::cin >> s;
}

std::vector <LL> f;

int main()	{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cerr.tie(nullptr);
	freopen("happy.in", "r", stdin);
	freopen("happy.out", "w", stdout);
	
	init();
	
	f.push_back(0);
	for(int i = 1; i <= n; ++i)	{
		f.push_back(f[i - 1] + s);
		for(int j = 1; j <= k; ++j)	{
			int last_used = lower_bound(t.begin() + 1, t.end(), t[i] - p[j].num + 1) - t.begin() - 1;
			f[i] = std::min(f[last_used] + p[j].cost, f[i]);
		}
	}
	
	for(int i = 1; i <= n; ++i)	{
		std::cout << f[i] - f[i - 1] << '\n';
	}
	
	return 0;
}

