#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int n,Mod,ans,a[N],b[N],c[N];
signed main()
{
	freopen("perm.in","r",stdin),freopen("perm.out","w",stdout);
	scanf("%lld%lld",&n,&Mod),ans=c[3]=a[4]=a[5]=1,a[6]=2;for(int i=7;i<=n;i++) a[i]=(a[i-1]+a[i-2]*(i-4)%Mod)%Mod;for(int i=5;i<=n;i++) a[i]=a[i]*(i-2)%Mod;
	for(int i=4;i<=n;i++) b[i]=(a[i]+c[i-1])%Mod*(i-1)%Mod,c[i]=(c[i-1]+b[i])%Mod,ans^=c[i];printf("%lld",ans);
}
