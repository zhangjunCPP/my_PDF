#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	freopen("cut.in", "r", stdin);
	freopen("cut.out", "w", stdout);

	int n;
	std::cin >> n;
	std::vector<int> col(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		std::cin >> col[i];
	}

	int ans = 0;
	std::vector<int> ans_list;
	bool flag_1 = 0, flag_2 = 0;
	for (int i = 1; i <= n; ++i) {
		if(col[i] == 0)	{
			if(flag_1)	{
				ans += 1;
				ans_list.push_back(i - 1);
			}
			else	{
				flag_1 = 1;
				if(flag_2 == 1)	{
					ans_list.push_back(i - 1);
					ans += 2;
					flag_1 = flag_2 = 0;
				}
			}
		}
		else	{
			flag_2 = 1;
			if(flag_1 == 1)	{
				ans_list.push_back(i - 1);
				ans += 2;
				flag_1 = flag_2 = 0;
			}
		}
	}
	if(*ans_list.begin() != 1)	ans_list.insert(ans_list.begin(), 1);
	std::cout << ans << ' ' << ans_list.size() << std::endl;
	for (auto i : ans_list) std::cout << i << ' ';

	return 0;
}
