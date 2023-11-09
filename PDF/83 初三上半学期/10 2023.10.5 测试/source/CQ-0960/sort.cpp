#include <bits/stdc++.h> 


using namespace std;
typedef long long ll;
const int N = 7e5 + 5, M = 2e7 + 5;
int n, tot;
ll ans;
int a[N], ab[N]/*离散化用*/, b[N];
int rt[N], tr[M], ls[M], rs[M];
void insert(int pre, int &id, int l, int r, int x) {
	tr[id = ++tot] = tr[pre] + 1;
	ls[id] = ls[pre], rs[id] = rs[pre];
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (x <= mid) insert(ls[pre], ls[id], l, mid, x);
	else insert(rs[pre], rs[id], mid + 1, r, x);
}
int query(int x, int y, int k, int l, int r) {
	if (l == r) return l;
	int val = tr[ls[y]] - tr[ls[x]], mid = (l + r) >> 1;
//	printf("	k = %d, l = %d, r = %d, val = %d\n"
//	, k, l, r, val);
	if (val >= k) return query(ls[x], ls[y], k, l, mid);
	return query(rs[x], rs[y], k - val, mid + 1, r);
}
void solve(int l, int r) {
	// 是值域的 [l, r] 
	if (l >= r) return;
	
	int len = r - l + 1, k = (len + 1) >> 1;
	ans += len;
	int zhong = query(rt[l - 1], rt[r], k, 1, n);
//	printf("l = %d, r = %d, len = %d, k = %d, zhong = %d\n"
//	, l, r, len, k, zhong);
	solve(l, a[zhong] - 1);
	solve(a[zhong] + 1, r);
}
int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]), ab[i] = a[i];
	}
	sort(ab + 1, ab + 1 + n);
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(ab + 1, ab + 1 + n, a[i]) - ab;
		b[a[i]] = i;
	}
	
//	printf("\ndsfd\n");
	for (int i = 1; i <= n; i++) {
//		printf("%d ", b[i]);
		insert(rt[i - 1], rt[i], 1, n, b[i]);
	}
//	printf("\n\n");
	solve(1, n);
	printf("%lld", ans);
	return 0;
}
