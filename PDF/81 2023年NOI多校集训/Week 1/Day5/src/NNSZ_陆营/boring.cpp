#include <iostream>
#include <map>
using namespace std;

const int max_n = 1e5 + 10;
const int mod = 998244353;

int a[max_n];
map <int, int> fact[max_n];

void divide(int num, const int idx);

void fast_read(int & num);
void fast_write(const int & num);

int main() {

	freopen("boring.in", "r", stdin);
	freopen("boring.out", "w", stdout);

	int n, q;
	fast_read(n);
	fast_read(q);
	for (int i = 1; i <= n; ++i) {
		fast_read(a[i]);
		divide(a[i], i);
	}
	
	while (q--) {
		int k;
		fast_read(k);
		map <int, int> lcm;
		while (k--) {
			int l, r;
			fast_read(l);
			fast_read(r);
			for (int i = l; i <= r; ++i) {
				for (auto it = fact[i].begin(); it != fact[i].end(); ++it) {
					auto temp = lcm.find(it->first);
					if (temp != lcm.end()) {
						temp->second = max(temp->second, it->second);
					}
					else {
						lcm[it->first] = it->second;
					}
				}
			}
		}
		int res = 1;
		for (auto it = lcm.begin(); it != lcm.end(); ++it) {
			for (int i = 1; i <= it->second; ++i) {
				res = (long long)res * it->first % mod;
			}
		}
		fast_write(res);
		putchar('\n');
	}

	return 0;
}

inline void divide(int num, const int idx) {
	for (int i = 2; i * i <= num; ++i) {
		int cnt = 0;
		while (num % i == 0) {
			++cnt;
			num /= i;
		}
		if (cnt) {
			fact[idx].insert(make_pair(i, cnt));
		}
	}
	if (num > 1) {
		fact[idx].insert(make_pair(num, 1));
	}
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
