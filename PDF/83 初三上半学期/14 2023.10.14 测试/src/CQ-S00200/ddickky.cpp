#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int mod=998244353;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

const int N=503;
int n, Q, a[N], f[N][N];

int main() {
	freopen("ddickky.in", "r", stdin);
	freopen("ddickky.out", "w", stdout); 
	n=read(), Q=read();
	for (int i=1; i<=n; i++) {
		a[i]=read();
	}
	for (int l=n; l>=1; l--) {
		f[l][l]=a[l];
		for (int r=l+1; r<=n; r++) {
			f[l][r]=gcd(f[l][r-1], a[r]);
		}
	}
	while (Q--) {
		int x=read(), y=read();
		long long res=1;
		for (int l=x; l<=y; l++) {
			for (int r=l; r<=y; r++) {
//				cout<<l<<" "<<r<<" "<<f[l][r]<<'\n';
				res=res*f[l][r]%mod;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
