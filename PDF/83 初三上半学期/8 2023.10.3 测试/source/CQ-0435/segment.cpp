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
	return G(n)-mi;
}

int main() {
	freopen("segment.in", "r", stdin);
	freopen("segment.out", "w", stdout);
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
	if (n<=2000||1ll*n*m<=5e7||m<500) {
		for (int i=1; i<=m; i++) ans=min(ans, solve(b[i]));
		cout<<ans;
		//O(nV)
	}
	else {
//		cout<<m<<'\n';
		if (n&1) {
			int mi=inf, mx=0;
			for (int i=2; i<=n; i+=2) {
				mi=min(mi, a[i]+a[i-1]);
				mx=max(mx, a[i]+a[i-1]);
			}
			mi=min(mi, a[n]), mx=max(mx, a[n]);
			ans=min(ans, mx-mi);
			mi=inf, mx=0;
			for (int i=3; i<=n; i+=2) {
				mi=min(mi, a[i]+a[i-1]);
				mx=max(mx, a[i]+a[i-1]);
			}
			mi=min(mi, a[1]), mx=max(mx, a[1]);
			ans=min(ans, mx-mi);
		}
		srand(time(0));
		for (int i=1; i<=m; i++) c[i]=i;
		random_shuffle(c+1, c+1+m);
		for (int i=1; i<=500; i++) ans=min(ans, solve(b[c[i]]));
		ans=min(ans, solve(b[n/2]));
		cout<<ans;
	}
	return 0;
}
/*

*/
