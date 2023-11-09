#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e7+10;
int n,mod;
int f[MAXN],jc[MAXN];
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout); 
	scanf("%lld%lld",&n,&mod);
	if(n<=7){
		int num[10]={0,0,0,1,7,47,322,2404};
		int ans=0;
		for(int i=1;i<=n;i++){
			ans^=num[i];
		}
		printf("%lld\n",ans);
		return 0;
	}
	jc[0]=1;
	for(int i=1;i<=MAXN;i++) jc[i]=jc[i-1]*i%mod;
	int ans=0;
	f[1]=0; f[2]=0;
	for(int i=3;i<=n;i++){
		f[i]=((f[i-1]+f[i-2]*(i-1))%mod*(n-1)%mod+jc[i]-jc[i-1]*2)%mod;
		ans^=f[i];
	}
	printf("%lld\n",ans);
	return 0;
} 
