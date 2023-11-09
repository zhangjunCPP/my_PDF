#include <bits/stdc++.h>
using namespace std;
int n,a[600000],sum;
bool b[600000]={0};
int main()
{
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+2]&&a[i+1]==a[i+3])
		{
			i+=3;
			sum+=4;
		}
	}
	cout<<sum;
	return 0;
 } 
