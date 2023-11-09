/*
爆搜12分/kk 
菊花图，12分。 
链，16分。 
*/
#include <bits/stdc++.h>
#define int long long

void Freopen();
void Ft();
int rd();
const int N=1e6+10, M=2e5+10, inf=1e9+10, mod=998244353;
using namespace std;
int n, ans, m=1;
int a[N], b[N], vis[N], ff[N];
set< int> s[N*2];
vector< int> t[N*2];
void dfs( int k) {
	if (k==n) {
		ans=(ans+1)%mod;
		return ;
	}
	if (vis[a[k]]||vis[b[k]]) dfs(k+1);
	else {
		vis[a[k]]=1;
		dfs(k+1);
		vis[a[k]]=0;
		vis[b[k]]=1;
		dfs(k+1);
		vis[b[k]]=0;
	}
}
signed main() {
	Freopen();
//	Ft();
	n=rd();
	for ( int i=1; i<n; i++) a[i]=rd(), b[i]=rd();
	if (n<=10) {
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}	
	int f=0;
	for ( int i=1; i<n; i++)
		if (a[i]!=1||b[i]!=i+1) f=1;
	if (!f) {
		cout<<n;
		return 0;
	}
	f=0;
	for ( int i=1; i<n; i++)
		if (a[i]!=i||b[i]!=i+1) f=1;
	if (!f) {
		ff[2]=1, ff[3]=3, ff[4]=5;
		for ( int i=5; i<=n; i++) ff[i]=(ff[i-1]+ff[i-2])%mod;
		cout<<ff[n];
	}
}
/*
7
7 2
7 6
1 2
7 5
4 7
3 5

*/
void Freopen() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
}
void Ft() {
	freopen("ex_tree2.in", "r", stdin);
//	freopen("tree.out", "w", stdout);
}
int rd() {
	int x; scanf("%lld", &x);
	return x;
}

