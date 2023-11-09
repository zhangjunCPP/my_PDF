#include<bits/stdc++.h>
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 1e5 + 2;
int n;
char s[N];
#define base 19260817
unsigned int hash_[N], pow_[N];
inline unsigned int get_hash (int l, int r) {
	return hash_[r] - hash_[l - 1] * pow_[r - l + 1]; }
inline void freo () {
	freopen("ccfc.in", "r", stdin), freopen("ccfc.out", "w", stdout); }
signed main () {
	freo();
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep (i, 1, n) hash_[i] = hash_[i - 1] * base + s[i];
	pow_[0] = 1;
	rep (i, 1, N - 1) pow_[i] = pow_[i - 1] * base;
	//rep (i, 1, n) cout << get_hash(i, i) << '\n';
	rep (i, 1, n) {
		int ans = 0;
		rep (len, 1, n) {
			if (3 * len >= n - i + 1) break;
			unsigned int val1 = get_hash(i, i + len - 1), val2 = get_hash(i + len, i + (len << 1) - 1), val3 = get_hash(n - len + 1, n);
			if (val1 == val2 && val2 == val3) ++ans;
			//cout << i << " " << len << '\n';
			//cout << val1 << " " << val2 << " " << val3 << '\n';
		}
		printf("%d ", ans);
	}
	printf("\n");
return 0; 
}
