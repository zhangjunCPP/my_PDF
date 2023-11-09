#include <bits/stdc++.h> 


using namespace std;
typedef double dl;
const int K = 44, N = 100004;
int n, k, m;
int lf, rt;
struct node {
	int d, b;
} L[N], R[N];
int ed[K], ted[K];
dl ans[K], c[K][K], tmp[K][K];
bool cmp(node x, node y) {
	return x.d < y.d;
}
void print() {
	for (int i = 0; i < k; i++) {
		printf("	%d: (%d):: ", i, ed[i]);
		for (int j = 0; j < k; j++) printf("%.1lf ", c[i][j]);
		printf("\n");
	}
	printf("\n");
}
void pans() {
	printf("//	");
	for (int i = 0; i < k; i++) printf("%.1lf ", ans[i]);
	printf("\n");
}
int main() {
	freopen("chameleon.in", "r", stdin);
	freopen("chameleon.out", "w", stdout);
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; i++) {
		char der[20];
		int b, d;
		scanf("%d%d%s", &d, &b, der);
		if (der[0] == 'D') R[++rt] = {d, b};
		else L[++lf] = {d, b};
	}
	sort(L + 1, L + 1 + lf, cmp);
	sort(R + 1, R + 1 + rt, cmp);
	int j = 1;
	R[rt + 1].d = m + 1;
	for (j = 1; j <= lf && L[j].d < R[1].d; j++) {
		ans[L[j].b] += L[j].d;
	}
	for (int i = 0; i <= k; i++) {
		c[i][(R[1].b + i) % k] += R[1].d;
		ed[i] = (R[1].b + i) % k;
	}
	ans[R[1].b] += m - R[1].d;
//	print();
//	printf("j = %d\n", j);
	for (int i = 2; i <= rt + 1; i++) {
		
//		pans();
		for (; j <= lf && L[j].d < R[i].d; j++) {
			for (int l = 0; l < k; l++) {
				ans[l] += c[L[j].b][l];
			}
			ans[ed[L[j].b]] += (L[j].d - R[1].d) / 2.0;
			ans[L[j].b] += (L[j].d - R[i - 1].d) / 2.0;
		}
//		printf("i = %d, j = %d\n", i, j);
		if (i <= rt) {
			ans[R[i].b] += m - R[i].d;
			for (int l = 0; l < k; l++) {
				int turns = (l + R[i].b) % k;
				swap(tmp[l], c[turns]);
				tmp[l][turns] += (R[i].d - R[i - 1].d) / 2.0;
				ted[l] = ed[turns];
			}
			for (int l = 0; l < k; l++) swap(tmp[l], c[l]), ed[l] = ted[l];
//			print();
		}
	}
//	pans();
	for (int i = 0; i < k; i++) {
		printf("%.1lf\n", ans[i]);
	}
	return 0;
}
