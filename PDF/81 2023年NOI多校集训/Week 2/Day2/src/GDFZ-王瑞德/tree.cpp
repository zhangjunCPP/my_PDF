#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0){x=~(x-1);putchar('-');}if(x>9)write(x/10);putchar(x%10+'0');}
#define put() putchar(' ')
#define endl puts("")
const int mod = 1e9 + 7;
const int MAX = 1e6 + 10;
vector <int> g[MAX];
int siz[MAX], son[MAX], dep[MAX];
int clk, dfn[MAX], top[MAX];
int fa[MAX];

void dfs(int u, int p){
	// write(u), put(), write(p), endl;
	siz[u] = 1;
	for(int v: g[u]){
		if(v == p or v == fa[u])	continue;
		fa[v] = u,	dep[v] = dep[u] + 1;
		dfs(v, u);	
		siz[u] += siz[v];
		if(!son[u] ||siz[v] > siz[son[u]])	son[u] = v; 
	}
}

void build(int u, int t){
	dfn[u] = ++clk,	top[u] = t;
	if(son[u])	build(son[u], t);
	for(int v: g[u]){
		if(v == fa[u])	continue;
		if(v != son[u])	build(v, v);
	}
}

int lca(int u, int v){
	while(top[u] != top[v]){
		if(dep[top[u]] < dep[top[v]])	swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] <dep[v] ? u : v;
}

bool f[MAX];
int ansA;

int calc(int x, int y){
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

void work(int x, int n){
	if(x > n){
		int maxn = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(f[i] == f[j]){
					maxn = max(maxn, calc(i, j));
				}
			}
		}
		ansA += maxn;
		ansA %= mod;
		return ;
	}
	f[x] = 1;
	work(x + 1, n);
	f[x] = 0;
	work(x + 1, n);
}

int quickPower(int a, int b, int mod){
	if(b < 0)	return 0;
	int base = a;
	int ans = 1;
	while(b){
		if(b & 1){
			ans *= base;
			ans %= mod;
		}
		b >>= 1;
		base *= base;
		base %= mod;
	}
	return ans;
}

void solve1(int n){
	dfs(1, 1);
	build(1, 1);
	// write(dep[2]), endl;
	work(1, n);
	write(ansA), endl;
}

void solveA(int n){
	if(n == 2){
		puts("2");
		exit(0);
	}
	int ans = 0;
	int s = (n - 1) / 2;
	for(int i = s + 1; i <= n; i++){
		if(i == s + 1){
			ans += (i - 1) * 2;
			continue;
		}
		int len = i - 1 - (n - (i - 1) + 1) + 1;
		if(i != n)	ans += quickPower(2, len, mod) * (i - 1) * 2 % mod;
		else ans += quickPower(2, len, mod) * (i - 1) % mod;
		if(i != n){
			ans += quickPower(2, len, mod) * (i - 1);
			ans %= mod;
		}
		ans %= mod;
	}
	ans *= 2;
	if(n % 2 == 0){
		ans -= n - 2;
		ans += mod;
		ans %= mod;
	}
	write(ans), endl;
}

void solveB(int n){
	if(n == 2){
		puts("2");
		exit(0);
	}
	else if(n == 1){
		puts("0");
	}
	else if(n == 3){
		puts("12");
	}
	else{
		write(quickPower(2, n, mod) * 2 % mod), endl;
	}
}

void solveC(int n){
	dfs(1, 1);
	int maxn = 0;
	for(int i = 1; i <= n; i++){
		maxn = max(maxn, dep[i]);
	}
	write((maxn - dep[1]) * 2 % mod * quickPower(2, n, mod) % mod), endl;
}

int cntt[MAX];

void solve(){
	int n = read();
	bool flag1 = 1;
	for(int i = 1; i < n; i++){
		int u = read(), v = read();
		g[u].push_back(v), g[v].push_back(u);
		if(!((u == i and v == i + 1) or (u == i + 1 and v == i))){
			flag1 = 0;
		}
		cntt[u] ++ ,cntt[v] ++;
	}
	if(n <= 10){
		solve1(n);
		return ;
	}
	else if(flag1){
		solveA(n);
		return ;
	}
	else if(cntt[1] == n - 1){
		solveB(n);
		return ;
	}
	else{
		solveC(n);
		return ;
	}
}

signed main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int t = 1;
	while(t--)	solve();
	return 0;
}
