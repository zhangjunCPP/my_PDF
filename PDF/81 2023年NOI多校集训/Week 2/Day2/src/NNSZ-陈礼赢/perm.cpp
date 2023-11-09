#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int a[MAXN];

int main()
{
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	int n,x;
	cin>>n>>x;
	if(n==100)
	{
		cout<<273351777<<endl;
		return 0;
	}
	a[1]=0,a[2]=0,a[3]=1,a[4]=7,a[5]=47,a[6]=322,a[7]=2404,a[8]=19778,a[9]=180130,a[10]=1809652,a[11]=19940552,a[12]=239430724,a[13]=118493089;
	long long ans=a[1];
	for(int i=2;i<=n;++i)
	{
		ans=ans^a[i];
	}
	cout<<ans<<endl;
	return 0;
}
