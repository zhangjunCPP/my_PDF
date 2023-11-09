#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int lim=1e7, B=1e3;
long long f[lim+2];

int oth(int n) {
	int ans=0;
	for (int x=1; x<n; x++) {
		for (int a=x+1; a<n; a++) ans+=(x*n%a==0);
	}
	return ans*4;
}
void init() {
	f[1]=1;
	for (int i=2; i<=B; i++) {
		f[i]=f[i-1]+1+(i-1)*4+oth(i);
	}
	for (int i=1; i<=20; i++) cout<<f[i]<<" ";
	cout<<'\n';
}
int calc(int n) {
	int ans=0;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) 
			for (int p=1; p<=n; p++) 
				for (int q=1; q<=n; q++) 
					if (1ll*i*j==1ll*p*q) {
						ans++;
						cout<<i<<" "<<j<<" "<<p<<" "<<q<<'\n';
					}
	return ans;
}
long long ask(int x) {
	if (f[x]) return f[x];
	return f[x]=ask(x-1)+1+(x-1)*4+oth(x);
}

int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
//	init();
	f[1]=1;
	int T=read();
	while (T--) {
		printf("%lld\n", ask(read()));
	}
/*	cout<<calc(4)<<'\n';
	puts("");
	cout<<calc(3);*/
//	for (int i=1; i<=20; i++) cout<<calc(i)<<' ';
//	cout<<'\n';
	return 0;
}
/*
f[i]=f[i-1]+1+(n-1)*4;
*/
