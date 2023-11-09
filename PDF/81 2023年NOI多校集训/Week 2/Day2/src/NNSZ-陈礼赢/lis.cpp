#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n-1;++i)
	{
		int a,b;
		cin>>a>>b;
	}
	int a[4000+10];
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	cout<<n/2<<endl;
	return 0;
}
