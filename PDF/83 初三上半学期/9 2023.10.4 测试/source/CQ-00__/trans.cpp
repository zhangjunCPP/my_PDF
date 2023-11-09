#include<bits/stdc++.h>
#define ppc(x) (__builtin_popcount(x))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int mod = 1e9 + 7;
const int N = 105;
const int M = 1 << 17 | 5;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w; 
} 
void file() {
	freopen("trans.in", "r", stdin);
	freopen("trans.out", "w", stdout);
}

template <typename A> int mul(A x) { return x; }
template <typename A, typename ...B> int mul(A x, B ... args) { return 1ll * x * mul(args...) % mod; }
void inc(int &a, int b) { a = a >= mod - b ? a - mod + b : a + b; }
int ksm(int a, int b) {
	int res = 1;
	while(b > 0) {
		if(b & 1) res = mul(res, a);
		a = mul(a, a), b >>= 1;
	} 
	return res;
}

struct Edge {
	int nex, to, df, sm;
} edge[N << 1];
int head[N], X[N], Y[N], D[N], S[N];
int fac[N], ifac[N];
int F[M], G[M], H[M];
map<pii, int> df, sm, id;
int _, n, m, k, elen = 1;
bool vis[N], pas[N];

int C(int n, int m) {
	if(n < m || m < 0) return 0;
	return mul(fac[n], ifac[m], ifac[n - m]);
}
void addedge(int u, int v, int d, int s) {
	edge[++ elen] = (Edge) {head[u], v, d, s}, head[u] = elen;
	edge[++ elen] = (Edge) {head[v], u, d, s}, head[v] = elen; 
}

int f[N][N], g[N][N], siz[N];
void dp(int u, int fath) {
	f[u][1] = 1, siz[u] = 1;
	for(int e = head[u], v; v = edge[e].to, e; e = edge[e].nex)
		if(v ^ fath) {
			dp(v, u);
			for(int i = 1; i <= siz[u]; ++ i) g[u][i] = f[u][i];
			for(int i = 1; i <= siz[u] + siz[v]; ++ i) f[u][i] = 0;
			for(int i = 1; i <= siz[u]; ++ i)
				for(int j = 1; j <= siz[v]; ++ j)
					inc(f[u][i + j], mul(g[u][i], f[v][j], edge[e].df)),
					inc(f[u][i + j - 1], mul(g[u][i], f[v][j], edge[e].sm));
			siz[u] += siz[v];
		}
} 
int DP() {
	memset(f, 0, sizeof(f));
	dp(1, 0);
	int ans = 0;
	for(int i = 1, coef = k; i <= n; ++ i)
		inc(ans, mul(f[1][i], coef)), coef = mul(coef, k - 1);
	return ans;
}

vector<int> vec, T[N];
int son[N], top[N], dep[N], fa[N];
int getid(int u, int v) {
	if(u > v) swap(u, v);
	return id[pii(u, v)];
}
void findtree(int u, int fath) {
	pas[u] = true;
	for(int e = head[u], v; v = edge[e].to, e; e = edge[e].nex)
		if(v ^ fath && !pas[v]) T[u].push_back(v), vis[getid(u, v)] = true, findtree(v, u);
}
void dfs(int u) {
	for(auto v : T[u])
		dep[v] = dep[fa[v] = u] + (siz[v] = 1), dfs(v),
		(siz[v] > siz[son[u]] && (son[u] = v, 1)), siz[u] += siz[v];
}
void dfs(int u, int tp) {
	top[u] = tp;
	if(son[u]) dfs(son[u], tp);
	for(auto v : T[u]) if(v ^ son[u]) dfs(v, v);
}
int getlca(int u, int v) { 
	while(top[u] ^ top[v])
		dep[top[u]] < dep[top[v]] ? v = fa[top[v]] : u = fa[top[u]];
	return dep[u] < dep[v] ? u : v; 
}
 
int un[N];
int find(int u) { return un[u] == u ? u : un[u] = find(un[u]); }
void merge(int u, int v) { u = find(u), v = find(v), un[u] = v; }
void work(int u, int v) {
	int lca = getlca(u, v), cur;
	lca = find(lca);
	
	cur = find(u);
	while(cur != lca) merge(cur, fa[cur]), cur = find(cur);
	
	cur = find(v);
	while(cur != lca) merge(cur, fa[cur]), cur = find(cur);
}


int col[N], answer;
int calc() {
	int res = 1;
	for(int i = 1; i <= m; ++ i) 
		if(col[X[i]] != col[Y[i]]) res = mul(res, D[i]);
		else res = mul(res, S[i]);
//	if(col[2] != col[3]) res = 0;
//	for(int i = 1; i <= n; ++ i)
//		cout << col[i] << " "; cout << "-->" << res << endl;
	return res;
}
void bf(int cur) {
	if(cur == n + 1) return inc(answer, calc()), void();
	for(int i = 1; i <= k; ++ i) col[cur] = i, bf(cur + 1);
}
void BF() {
	bf(1);
	printf("%d\n", answer);
}

void solve() {
	int coef = 1;
	n = read(), m = read(), k = read();
	
	memset(head, 0, sizeof(head)), elen = 1;
	df.clear(), sm.clear(), id.clear(), vec.clear();
	for(int i = 1; i <= n; ++ i) T[i].clear(), pas[i] = false;
	for(int i = 1; i <= m; ++ i) vis[i] = false;

	for(int i = 1, x, y, d, s; i <= m; ++ i) {
		x = read(), y = read(), d = read(), s = read();
		if(x == y) {
			coef = mul(coef, s);
			continue;
		}
		if(x > y) swap(x, y);
		if(df.find(pii(x, y)) == df.end())
			df[pii(x, y)] = sm[pii(x, y)] = 1;
		df[pii(x, y)] = mul(df[pii(x, y)], d);
		sm[pii(x, y)] = mul(sm[pii(x, y)], s);
	}
	m = 0;
	for(auto e : df) {
		int u = e.fi.fi, v = e.fi.se;
		++ m, X[m] = u, Y[m] = v;
		D[m] = df[pii(u, v)], S[m] = sm[pii(u, v)];
		id[pii(u, v)] = m;
	}
	
	if(n == 2) {
		int ans = mul(S[1], k);
		inc(ans, mul(D[1], k, k - 1));
		printf("%d\n", mul(ans, coef));
		return ;
	} 
	
	if(m == n - 1) {
		for(int i = 1; i <= m; ++ i)
			addedge(X[i], Y[i], D[i], S[i]);
			
		printf("%d\n", mul(DP(), coef));
		return ;
	}
	
//	BF();
	
	int rst = m - (n - 1);
	if(rst <= 16) {
		for(int i = 1; i <= m; ++ i)
			addedge(X[i], Y[i], D[i], S[i]);
			
		findtree(1, 0);
		dfs(siz[1] = dep[1] = 1), dfs(1, 1);	
		for(int i = 1; i <= m; ++ i)
			if(!vis[i]) vec.push_back(i);
			
		assert(vec.size() == rst);
		
		int ans = 0;
		for(int s = 0; s < (1 << rst); ++ s) {
			H[s] = 1;
			int coef = 1;
			for(int i = 1; i <= n; ++ i) un[i] = i;
			for(int i = 0; i < rst; ++ i) 
				if((s >> i) & 1) 
					coef = mul(coef, S[vec[i]]),
					work(X[vec[i]], Y[vec[i]]);
				else H[s] = mul(H[s], D[vec[i]]);
			
			memset(head, 0, sizeof(head)), elen = 1;
				
			for(int i = 1; i <= m; ++ i) if(vis[i]) {
				int u = find(X[i]), v = find(Y[i]);
				if(u == v) coef = mul(coef, S[i]);
				else addedge(u, v, D[i], S[i]);
			}
		
			int res = DP();	
			G[s] = mul(res, coef);
			
			if(ppc(s) & 1) F[s] = (mod - G[s]) % mod;
			else F[s] = G[s];
//			cout << res << " " << coef << endl;
//			printf("G[%d]=%d\n", s, G[s]);
		}
		
		for(int i = 2; i <= (1 << rst); i <<= 1)
			for(int j = 0, p = i >> 1; j < (1 << rst); j += i)
				for(int k = 0; k < p; ++ k) 
					inc(F[j + k], F[j + k + p]);
		for(int s = 0; s < (1 << rst); ++ s) {
			if(ppc(s) & 1) F[s] = (mod - F[s]) % mod;
			
//			cout << mul(F[s], H[s]) << endl;
			inc(ans, mul(F[s], H[s]));
		}
		printf("%d\n", mul(ans, coef));
	}
	
}

signed main() {
//	freopen("ex_trans1.in", "r", stdin); 
//	freopen("data.in", "r", stdin); 
	file();
	for(int i = fac[0] = 1; i < N; ++ i) fac[i] = mul(fac[i - 1], i);
	ifac[N - 1] = ksm(fac[N - 1], mod - 2);
	for(int i = N - 2; i >= 0; -- i) ifac[i] = mul(ifac[i + 1], i + 1);
	
	_ = read();
	while(_ --) solve();
	return 0; 
}
/*
16:20 no focus, fk!
16:50 GG!
17:50 GGG~!
18:10 joker.
*/ 
/*
1
4 4 5
1 2 1 3
2 3 5 7 
3 4 2 1
2 4 1 1
*/
