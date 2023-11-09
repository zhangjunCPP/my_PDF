#include <iostream>
using namespace std;

int main() {

	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);

	int n, k;
	scanf("%d %d", &n, &k);

	if (n == 1) {
		puts("Yes");
		for (int i = 1; i <= 6; ++i) {
			printf("%d ", k * i);
		}
		return 0;
	}
	if (k == 2) {
		puts("Yes");
		for (int i = 1; i <= n - 1; ++i) {
			puts("2 4 6 8 10 12");
		}
		puts("128 130 132 134 136 138");
		return 0;
	}

	puts("No");

	return 0;
}
