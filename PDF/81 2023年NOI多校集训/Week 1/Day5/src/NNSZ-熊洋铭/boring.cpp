#include <cstring>
#include <iostream>
#include <vector>

typedef long long LL;

const LL MODN = 998244353;

struct Node {
	LL val;
	int l, r;
	Node(LL val, int l, int r) : val(val), l(l), r(r) {}
	Node() : val(1), l(0), r(0) {}
};

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

LL qpow(LL a, LL b) {
	return b ? (b & 1 ? a * qpow(a, b - 1) : qpow(a * a % MODN, b / 2) % MODN)
			 : 1;
}

LL lcm(LL a, LL b) { 
	// std::cerr << a << ' ' << b << ' ' << a * b % MODN << ' ' << gcd(a, b) << ' ' << qpow(gcd(a, b), MODN - 2) << ' ' << qpow(gcd(a, b), MODN - 2) % MODN * (a * b % MODN) % MODN << std::endl;
	return qpow(gcd(a, b), MODN - 2) % MODN * (a * b % MODN) % MODN % MODN;
}

class SegmentTreeLCM {
private:
	int n;
	std::vector<Node> p;
	std::vector<LL> a;
	int ls(int x) { return x * 2; }
	int rs(int x) { return x * 2 + 1; }

public:
	SegmentTreeLCM(int n, std::vector<LL> a) : n(n), p(n * 4 + 4), a(a) {}

	Node push_up(Node ls, Node rs) {
		// std::cerr << std::endl;
		// std::cerr << ls.l << ' ' << ls.r << ' ' << rs.l << ' ' << rs.r << std::endl;
		Node res(lcm(ls.val, rs.val), ls.l, rs.r);
		return res;
	}

	void build(int x, int l, int r) {
		p[x].l = l, p[x].r = r;
		if (l == r) {
			p[x].val = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(ls(x), l, mid);
		build(rs(x), mid + 1, r);
		p[x] = push_up(p[ls(x)], p[rs(x)]);
	}

	Node query(const int l, const int r, const int x = 1) {
		if (l <= p[x].l && p[x].r <= r) {
			return p[x];
		}
		int mid = (p[x].l + p[x].r) / 2;
		if (r <= mid) return query(l, r, ls(x));
		if (l > mid) return query(l, r, rs(x));
		return push_up(query(l, r, ls(x)), query(l, r, rs(x)));
	}
};

LL read() {
	LL x = 0;
	char ch;
	do {
		ch = _getchar_nolock();
	} while (!isdigit(ch));
	do {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = _getchar_nolock();
	} while (isdigit(ch));
	return x;
}

void print(LL x) {
	if (x < 0) _putchar_nolock('-'), x = -x;
	static int s[45], d = 0;
	do {
		s[++d] = x % 10;
		x /= 10;
	} while (x);
	do {
		_putchar_nolock(s[d--] + '0');
	} while (d);
}

void println(LL x) { print(x), _putchar_nolock('\n'); }

int main() {
	freopen("boring.in", "r", stdin);
	freopen("boring.out", "w", stdout);

	int n, q;
	n = read(), q = read();
	std::vector<LL> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	SegmentTreeLCM p(n, a);
	p.build(1, 1, n);

	while (q--) {
		int k;
		k = read();
		LL ans = 1;
		int l, r;
		for (int i = 1; i <= k; ++i) {
			l = read(), r = read();
			ans = lcm(ans, p.query(l, r).val);
		}
		print(ans);
		_putchar_nolock('\n');
	}
	return 0;
}
