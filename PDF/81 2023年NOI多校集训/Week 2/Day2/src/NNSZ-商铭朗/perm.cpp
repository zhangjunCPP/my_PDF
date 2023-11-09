#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define int long long

#define speedup() {ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);}

int n, p, ans, v; 

const int MAXN=1e7+10;

int a[MAXN], b[MAXN],cnt[MAXN];
int f[MAXN], fact[MAXN];

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

#define inv(a) qpow(a,p-2,p)

signed main() {
	#ifndef DEBUG
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	#endif
	speedup();
	cin>>n>>p;
	f[3]=1, f[4]=7;
	fact[1]=1, fact[2]=2, fact[3]=6, fact[4]=24;
//	for (int i=1; i<=n; ++i) a[i]=i;
//	for (int i=1; i<=n; ++i) {	
//		b[a[i]]=i;
//	}
//	while (next_permutation(a+1,a+1+n)) {
//		for (int i=1; i<=n; ++i) {
//			b[a[i]]=i;
//		}
////		for (int i=1; i<=n; ++i) cout<<a[i]<<' ';
////		putchar('\n');
////		for (int i=1; i<=n; ++i) cout<<b[i]<<' ';
////		putchar('\n');
//		if (check(n))
////			cout<<"OK\n",
//			ans++,cnt[a[1]]++;
//		//putchar('\n');
//	}
	int ans=0;
	int i2=inv(2);
	for(int i=5; i<=n; ++i) {
		fact[i]=fact[i-1]*i%p;
		f[i]=(f[i-1]+(2*f[i-2]%p+(i-2)*fact[i-2]%p)*(i-1)%p*i2%p)%p;
	}
	
//	for (int i=3; i<=n; ++i) {
//		cout<<f[i]<<' ';
//	}
//	cout<<endl;
	for (int i=3; i<=n; ++i) ans^=(f[i]%p);
	cout<<ans<<endl;
	return 0;
}

