#include<bits/stdc++.h>
#define int long long
using namespace std;
int pre[10000005];
int f[10000005];
int n,ans=1,mod;
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>n>>mod;
	f[3]=1;
	pre[0]=1;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]*i%mod;
	for(int i=4;i<=n;i++){
		f[i]=f[i-1];
		f[i]=(f[i]+(i-1)*f[i-2])%mod;
		int tmp=pre[i-2]*((i-2)*(i-1)/2)%mod;
		f[i]=(f[i]+tmp)%mod;
		ans^=f[i];
	}
	cout<<ans;
} 
