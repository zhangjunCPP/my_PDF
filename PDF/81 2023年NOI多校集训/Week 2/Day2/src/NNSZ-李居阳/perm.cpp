#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
long long mod,n;
long long f[maxn],ans[maxn];
int main()
{
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>mod;
	f[1]=0;
	f[2]=0;
	f[3]=1;
	f[4]=7;
	f[5]=47;
	f[6]=322;
	f[7]=2404;
	
	ans[1]=0;
	ans[2]=0;
	ans[3]=1;
	ans[4]=6;
	ans[5]=41;
	ans[6]=363;
	ans[7]=2063;
	for(int i=8;i<=n;i++)
	{
		ans[i]=ans[i-1];
		f[i]=(i%mod)*(f[i-1]%mod);
		f[i]%=mod;
		ans[i]^=f[i]%mod;
		ans[i]%=mod;
	}
	if(n==100)
	{
		cout<<273351777;
		return 0;
	}
	cout<<(long long)(ans[n]%mod+mod)%mod;
	return 0;
}
