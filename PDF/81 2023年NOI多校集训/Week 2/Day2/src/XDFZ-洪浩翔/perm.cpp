#include<bits/stdc++.h>
#define int long long
const int QWQ=1e7+5;
using namespace std;
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
	while ('0'<=ch&&ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
int n,mod,fac[QWQ],res,f[QWQ];
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	n=read(),mod=read();
	fac[1]=1;
	for (int i=2;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	for (int i=3;i<=n;i++){
		f[i]=fac[i-2]*((i-1)*(i-2)/2%mod)%mod;
		f[i]=(f[i]+((i-1)*f[i-2]%mod+f[i-1])%mod)%mod;
		res^=f[i];
	} printf("%lld",res);
	return 0;
}
