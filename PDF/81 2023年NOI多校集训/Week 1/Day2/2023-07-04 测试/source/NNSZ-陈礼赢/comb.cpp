#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10;
int n;
int a[MAXN];
int tot[MAXN];
long long sum=0;

int main()
{
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		++tot[a[i]];
	}
	for(int i=1;i<=MAXN-3;++i)
	{
		sum+=tot[a[i]]/2;
	}
	cout<<sum-sum%4<<endl;
	return 0;
}
