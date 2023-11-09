#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
int ans;
signed main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if((i*j)%k==0&&i*j/k>=1&&i*j/k<=n) ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
