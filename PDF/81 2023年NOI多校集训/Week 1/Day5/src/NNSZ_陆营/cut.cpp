#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int max_n = 5e5 + 10;
const int max_a = 25;

int a[max_n];
int dp_sum[max_n];
int dp_last[max_n];
bool flag[max_a];
vector <int> last;

void fast_read(int & num);
void fast_write(const int & num);

int main() {

	freopen("cut.in", "r", stdin);
	freopen("cut.out", "w", stdout);

	int n;
	fast_read(n);
	for (int i = 1; i <= n; ++i) {
		fast_read(a[i]);
	}

	dp_sum[1] = a[1] == 0 ? 1 : 0;
	for (int i = 2; i <= n; ++i) {
		memset(flag, false, sizeof(flag));
		int mex = 0;
		for (int j = i; j; --j) {
			flag[a[j]] = true;
			while (flag[mex]) {
				++mex;
			}
			if (dp_sum[j - 1] + mex > dp_sum[i]) {
				dp_sum[i] = dp_sum[j - 1] + mex;
				dp_last[i] = j;
			}
		}
	}

	int cur = dp_last[n];
	while (cur) {
		last.push_back(dp_last[cur]);
		cur = dp_last[cur] - 1;
	}
	
	fast_write(dp_sum[n]);
	putchar(' ');
	fast_write(last.size());
	putchar('\n');
	for (int i = last.size() - 1; i >= 0; --i) {
		fast_write(last[i]);
		putchar(' ');
	}

	return 0;
}

inline void fast_read(int & num) {
	char ch = getchar();
	while (ch < '0' || '9' < ch) {
		ch = getchar();
	}
	num = 0;
	while ('0' <= ch && ch <= '9') {
		num = (num << 3) + (num << 1) + (ch ^ 48);
		ch = getchar();
	}
}

void fast_write(const int & num) {
	if (num > 9) {
		fast_write(num / 10);
	}
	putchar(num % 10 + 48);
}
