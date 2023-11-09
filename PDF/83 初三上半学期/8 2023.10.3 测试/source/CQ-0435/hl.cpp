#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=2e5+3, inf=2e9+114;
int n, a[N], b[N], c[N], ty[N], f[N][3];
// 0 left 1 right 2 mid
int G(int i) {
	if (ty[i]) return f[i][0];
	return min(f[i][0], f[i][2]);
}
int solve(int mi) {
	for (int i=1; i<=n; i++) {
		ty[i]=(a[i]<mi);
		f[i][0]=f[i][1]=f[i][2]=inf;
	} 
	for (int i=1; i<=n; i++) {
		if (i>1&&a[i]+a[i-1]>=mi) {
			f[i][0]=max(G(i-2), a[i]+a[i-1]);
		}
		if (i<n&&a[i]+a[i+1]>=mi) {
			f[i][1]=max(G(i-1), a[i]+a[i+1]);
		}
		if (!ty[i]) f[i][2]=max(G(i-1), a[i]);
	}
//	cout<<"((  "<<G(n)<<" "<<mi<<'\n';
	if (G(n)==inf) return inf;
	return G(n)-mi;
}

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("segment4.in", "r", stdin);
	n=read();
	for (int i=1; i<=n; i++) {
		a[i]=b[i]=read();
	}
	sort(b+1, b+1+n);
	int m=unique(b+1, b+1+n)-b-1, ans=inf;
	if (n%2==0) {
		int mi=inf, mx=0;
		for (int i=2; i<=n; i+=2) {
			mi=min(mi, a[i]+a[i-1]);
			mx=max(mx, a[i]+a[i-1]);
		}
		ans=mx-mi;
	}
		for (int i=1; i<=m; i++) 
			cout<<solve(b[i])<<" ";
		cout<<ans;
	return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int inf=2e9+114;

const int N=2e5+3;
int n, a[N], b[N], ans=inf, c[N], o;

int calc() {
	o=0;
	int mx=0, mi=inf;
	for (int i=n; i>=1; i=i-1-b[i]) {
		int w=a[i]+a[i-1];
		if (b[i]) mx=max(mx, w), mi=min(mi, w), c[++o]=w;
		else mx=max(mx, a[i]), mi=min(mi, a[i]), c[++o]=a[i];
	}
//	cout<<mx<<" "<<mi<<'\n';
	return mx-mi;
}

void dfs(int x) {
	if (x>n) {
		int tmp=calc();
		if (tmp<ans) {
			ans=tmp;
			cout<<ans<<'\n';
			reverse(c+1, c+1+o);
			for (int i=1; i<=o; i++) {
				cout<<c[i]<<" ";
			}
			cout<<'\n';
		}
		return;
	}
	if (b[x-1]) return b[x]=0, dfs(x+1);
	b[x]=0, dfs(x+1);
	b[x]=1, dfs(x+1);
}

int main() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	dfs(2);
	return 0;
}

6
9 4 4 10 10 6
3
3 1 3

*/
