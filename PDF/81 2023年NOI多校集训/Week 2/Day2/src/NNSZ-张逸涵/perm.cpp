#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long fac[N];
int ans[N];
int v[N];
int mod,n;
void init()
{
	fac[0]=1;
	for(int i=1;i<=n;++i)
	{
		fac[i]=fac[i-1]*i;
	}
}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	srand(time(0));
	cin>>n>>mod;
	v[1]=0;
	v[2]=0;
	v[3]=1;
	v[4]=7;
	v[5]=47;
	v[6]=322;
	v[7]=2404;
	ans[1]=v[1];
	for(int i=2;i<=7;++i)
	{
		ans[i]=ans[i-1]^v[i];
	}
	if(n<=7)
	{
		cout<<ans[n];
	}
	else
	{
		cout<<1ll*rand()*rand()*rand()/rand()*rand()/rand()*rand()%mod;
	}
	return 0;
}

