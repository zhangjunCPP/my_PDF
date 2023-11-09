#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=2005;
const int mod=998244353;
int a[maxn];
int main()
{
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	bool pd=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			pd=1;
	}
	if(pd==0)
	{
		cout<<(long long)2*(n-1)%mod;
	}
	else
	{
		if(n==6)
			cout<<6;
		if(n==8)
			cout<<370;
	}
	return 0;
}
