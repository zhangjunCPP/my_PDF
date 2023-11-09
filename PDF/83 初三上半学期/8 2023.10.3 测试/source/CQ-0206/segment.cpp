#include<bits/stdc++.h>
#define rep(i,x,y) for (int i = (x); i <= (y); ++i)
#define drep(i,x,y) for (int i = (x); i >= (y); --i)
#define go(i,u) for (int i = head[u]; i; i = edge[i].next)
#define MP make_pair
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 2e5 + 2, M = 2e3 + 2, INF = 2e9 + 2;
int n, a[N], b[N * 2];
int bc;
unordered_map<int, int> mp;
int revmp[N * 2];
namespace Solve1 {
	int f[M][M * 2][2];
}
inline void solve1 () {
	using namespace Solve1;
	rep (i, 0, M - 1) rep (j, 0, (M << 1) - 1) rep (k, 0, 1) f[i][j][k] = -INF;
	f[1][mp[a[1]]][0] = mp[a[1]];
	f[2][mp[a[1] + a[2]]][0] = mp[a[1] + a[2]], f[2][mp[a[1]]][1] = mp[a[1]]; 
	rep (i, 2, n - 1) rep (j, 0, bc) rep (k, 0, 1) {
		int mpi = mp[a[i]], mpi1 = mp[a[i + 1]], mpii1 = mp[a[i] + a[i + 1]];
		if (!k) {
			f[i + 1][max(j, mpi1)][0] = max(f[i + 1][max(j, mpi1)][0], min(f[i][j][0], mpi1));
			f[i + 1][j][1] = max(f[i + 1][j][1], f[i][j][0]);
		}
		if (k) {
			f[i + 1][max({j, mpi, mpi1})][0] = max(f[i + 1][max({j, mpi, mpi1})][0], min({f[i][j][1], mpi, mpi1}));
			f[i + 1][max(j, mpii1)][0] = max(f[i + 1][max(j, mpii1)][0], min(f[i][j][1], mpii1));
			f[i + 1][max(j, mpi)][1] = max(f[i + 1][max(j, mpi)][1], min(f[i][j][1], mpi));
		}
		//cout << i << " " << j << " " << k << '\n';
		//cout << f[i][j][k] << '\n';
	}
	int ans = INF;
	rep (j, 0, bc) if (f[n][j][1] != -INF) {
		ans = min(ans, revmp[max(j, mp[a[n]])] - revmp[min(f[n][j][1], mp[a[n]])]);
		//cout << max(j, mp[a[n]]) << " " << min(f[n][j][1], mp[a[n]]) << '\n';
	}
	rep (j, 0, bc) if (f[n][j][0] != -INF) {
		ans = min(ans, revmp[j] - revmp[f[n][j][0]]);
		//cout << j << " " << f[n][j][0] << '\n';
	}
	printf("%d\n", ans);
}
namespace Solve2 {
	int f[N][22][2];
}
inline void solve2 () {
	using namespace Solve2;
	rep (i, 0, N - 1) rep (j, 0, 21) rep (k, 0, 1) f[i][j][k] = -INF;
	f[1][a[1]][0] = a[1];
	f[2][a[1] + a[2]][0] = a[1] + a[2], f[2][a[1]][1] = a[1]; 
	rep (i, 2, n - 1) rep (j, 0, bc) rep (k, 0, 1) {
		int mpi = a[i], mpi1 = a[i + 1], mpii1 = a[i] + a[i + 1];
		if (!k) {
			f[i + 1][max(j, mpi1)][0] = max(f[i + 1][max(j, mpi1)][0], min(f[i][j][0], mpi1));
			f[i + 1][j][1] = max(f[i + 1][j][1], f[i][j][0]);
		}
		if (k) {
			f[i + 1][max({j, mpi, mpi1})][0] = max(f[i + 1][max({j, mpi, mpi1})][0], min({f[i][j][1], mpi, mpi1}));
			f[i + 1][max(j, mpii1)][0] = max(f[i + 1][max(j, mpii1)][0], min(f[i][j][1], mpii1));
			f[i + 1][max(j, mpi)][1] = max(f[i + 1][max(j, mpi)][1], min(f[i][j][1], mpi));
		}
	}
	int ans = INF;
	rep (j, 0, bc) if (f[n][j][1] != -INF) {
		ans = min(ans, max(j, a[n]) - min(f[n][j][1], a[n]));
	}
	rep (j, 0, bc) if (f[n][j][0] != -INF) {
		ans = min(ans, j - f[n][j][0]);
	}
	printf("%d\n", ans);
}
inline void freo () {
	freopen("segment.in", "r", stdin), freopen("segment.out", "w", stdout); }
signed main () {
	freo();
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d", &a[i]), b[++bc] = a[i];
	rep (i, 1, n) b[++bc] = a[i] + a[i - 1];
	sort(b + 1, b + bc + 1);
	bc = unique(b + 1, b + bc + 1) - b - 1;
	rep (i, 1, bc) mp[b[i]] = i, revmp[i] = b[i];
	/*cout << b[i] << " ";
	cout << '\n';*/
	if (n <= 2000) return solve1(), 0;
	else return solve2(), 0;
return 0; 
}
/*
5
2 2 3 5 2
*/
