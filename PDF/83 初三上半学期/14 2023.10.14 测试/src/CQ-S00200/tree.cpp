#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int mod=998244353, N=1e6+5;

int n, f[N];

int solve1() {
	cout<<n<<'\n';
	return 0;
}
int solve2() {
	f[1]=f[2]=1;
	for (int i=1; i<n; i++) {
		f[i+1]=(f[i+1]+f[i])%mod;
		f[i+2]=(f[i+2]+f[i])%mod;
	}
	cout<<f[n];
	return 0;
}

struct edge {
	int u, v;
} g[N];
int co[N], ans;

void dfs(int i) {
	if (i==n) {
		ans++; return;
	}
	if (co[g[i].u]||co[g[i].v]) return dfs(i+1);
	co[g[i].u]=1, dfs(i+1), co[g[i].u]=0;
	co[g[i].v]=1, dfs(i+1), co[g[i].v]=0;
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n=read();
	int flag1=1, flag2=1;
	for (int i=1; i<n; i++) {
		int u=read(), v=read();
		if (u!=1||v!=i+1) flag1=0;
		if (u!=i||v!=i+1) flag2=0;
		g[i]={u, v};
	}
	if (flag1) return solve1();
	if (flag2) return solve2();
	dfs(1);
	cout<<ans;
	return 0;
}
// 40 pts
