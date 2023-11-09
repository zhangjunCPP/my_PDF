#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=1003;
const long long inf=1e17;
int n, l[N], r[N], c[N], vis[N], b[N];
long long val[N], ans, a[N];
vector<int> g[N];

long long fee(int p) {
	long long res=0;
	for (auto x:g[p]) res-=c[x];
	for (int j=l[p]; j<=r[p]; j++) 
		if (!vis[j]&&j!=p) res+=c[p];	
	return res;
}


long long calc() {
	for (int i=1; i<=n; i++) {
		val[i]=b[i]=0;
	}
	for (int i=1; i<=n; i++) {
		int p=a[i];
		b[p]=1;
		for (int j=l[p]; j<=r[p]; j++) if (!b[j]) {
			val[j]+=c[p];
		}
	}
	long long res=0;
	for (int i=1; i<=n; i++) res+=val[i];
	return res;
}
void dfs(int u) {
	if (u>n) {
/*		if (calc()>ans) {
			for (int i=1; i<=n; i++) cout<<a[i]<<" ";
			cout<<'\n';
		}*/
		ans=max(ans, calc());
		return;
	}
	for (int i=1; i<=n; i++) if (!vis[i]) {
		vis[i]=1, a[u]=i, dfs(u+1), vis[i]=0;
	}
}

int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	n=read();
	for (int i=1; i<=n; i++) {
		l[i]=read(), r[i]=read(), c[i]=read();
		for (int j=l[i]; j<=r[i]; j++) 
			if (j!=i) val[j]+=c[i], g[j].push_back(i);
		a[i]=(r[i]-l[i])*c[i];
	}
	if (n<=10) {
		dfs(1);
		cout<<ans;
		return 0;
	}
	int T=n;
	val[0]=-inf;
	while (T--) {
		int p=0;
		for (int i=1; i<=n; i++) if (!vis[i]) {
			if (a[i]-val[i]<a[p]-val[p]) p=i;
			else if (a[i]-val[i]==a[p]-val[p]) {
				if (fee(i)>fee(p)) p=i;
			}
			// == ?
		}
		ans+=val[p];
//		ans+=a[p];
		vis[p]=1;
		for (auto x:g[p]) a[x]-=c[x];
		for (int j=l[p]; j<=r[p]; j++) 
			if (!vis[j]) val[j]-=c[p];
	}
	cout<<ans;
	return 0;
}
/*
f[i][num][S] 表示序列填了 i 个数，第 num 块里面的状态为 S 

*/
