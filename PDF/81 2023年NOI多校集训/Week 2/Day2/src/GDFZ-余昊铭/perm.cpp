#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10000010;
inline int read(){
	int x=0,fl=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-1')fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fl;
}
int n,mod,mul=1;
int f[maxn];
signed main(){
	freopen("perm.in","r",stdin);
//	freopen("perm.out","w",stdout);
	n=read();mod=read();
	f[1]=0;f[2]=0;
	for(int i=3;i<=n;i++){
		f[i]=f[i-1];
		mul*=(i-2);mul%=mod;
		f[i]+=(i-1)*f[i-2]%mod;f[i]%=mod;
		f[i]+=((i-1)*(i-2)/2)%mod*mul%mod;f[i]%=mod;
	}
//	for(int i=1;i<=n;i++)cout<<f[i]<<" ";
//	cout<<"\n";
	for(int i=1;i<=n;i++)f[i]^=f[i-1];
	printf("%lld\n",f[n]);
}
