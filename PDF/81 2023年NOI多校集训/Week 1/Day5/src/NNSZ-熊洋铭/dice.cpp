#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
    freopen("dice.in", "r", stdin);
    freopen("dice.out", "w", stdout);

	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		std::cout << 0 << ' ' << k << ' ' << k * 64 << ' ' << k * 65 << ' '
				  << k * 4096 << ' ' << k * 4097 << std::endl;
	}
	return 0;
}
