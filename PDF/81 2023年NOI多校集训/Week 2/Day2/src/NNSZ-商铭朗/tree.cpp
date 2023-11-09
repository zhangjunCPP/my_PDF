#include <bits/stdc++.h>

using namespace std;
#define speedup() {ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);}
#define int long long
constexpr int MAXN=1e6+10, MAXM=2e6+10, p=1e9+7;

struct {
	int nxt, to;
} e[MAXN]; int head[MAXN], tot;

inline void add(int u, int v) {
	e[++tot].to=v, e[tot].nxt=head[u], head[u]=tot;
}

int n;
int f[MAXN], pow2[MAXN], col[MAXN], type[3], ans;

inline int qpow(int a, int n, int p){
	a%=p;
	int res=1;
	while (n) {
		if (n&1) res=res*a%p;
		a=a*a%p;
		n>>=1;
	}
	return res;
}

int dep[MAXN], deg[MAXN]; 

inline int bfs(int s) {
	memset(dep,0,sizeof dep);
	queue<int> q; q.push(s);
	dep[s]=1; int maxdep=1;
	while (q.size()) {
		int u=q.front(); q.pop();
		for (int i=head[u]; i; i=e[i].nxt) {
			int v=e[i].to;
			if (dep[v]) continue;
			dep[v]=dep[u]+1;
			if (col[v]==col[s])
				maxdep=max(dep[v],maxdep);
			q.push(v);
		}
	}
	return maxdep-1;
}

inline int calc() {
	int maxw=0, maxb=0;
	for (int i=1; i<=n; ++i) {
		if (col[i])
			maxb=max(maxb, bfs(i));
		else
			maxw=max(maxw, bfs(i));
	}
	return max(maxw,maxb);
}

inline void dfs(int step) {
	if (step>n) {
		int c=calc();
//		for (int i=1; i<=n; ++i)
//			cout<<col[i]<<' ';
//		cout<<endl;
//		cout<<"calc()="<<c<<'\n';
		ans=(ans+c)%p; 
		return;
	}
	for (int i=0; i<=1; ++i) {
		col[step]=i;
		dfs(step+1);
	}
}


signed main() {
	#ifndef DEBUG
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	#endif
	speedup();
	cin>>n; int x, y;
	for (int i=1; i<=n-1; ++i) {
		cin>>x>>y; add(x,y), add(y,x);
		deg[x]++, deg[y]++;
	}
	if (n<=10) { // Testpoint 1
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
	else if (deg[1]==(n-1)) { // 性质B,Testpoint 5
		cout<<qpow(2,n,p)*2%p<<endl;
		return 0;
	}
	else { // 性质A，Testpoing 2~4
		f[2]=2; pow2[0]=1, pow2[1]=2, pow2[2]=4, pow2[3]=8;
		for (int i=3; i<=n; ++i) {
			pow2[i+1]=pow2[i]*2%p;
			f[i]=(2*f[i-1]%p+pow2[i])%p;
			if (i%2==0)
				f[i]-=2;
		}
		cout<<f[n]<<endl;
		return 0;
	}
	return 0;
}