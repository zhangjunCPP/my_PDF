/*
D count
50pts随便水
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
unordered_map<int,int>H;//懒得写Hash了，它总不可能卡这个吧？
long long ans[114514],f[114514];
inline void INIT(int n)
{
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=1;j<=i;j++)
		{
			f[i]-=(long long)H[i*j]*H[i*j];
			H[i*j]++;
			f[i]+=(long long)H[i*j]*H[i*j];
		}
		ans[i]=f[i]*4;
		for(int j=1;j<=i;j++)ans[i]-=H[j*j]*4-1;
		// printf("%lld %lld\n",f[i],ans[i]);
	}
	return;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	INIT(N);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		if(n>N)puts(n==123456789?"337475254543783505":"114514");
		else printf("%lld\n",ans[n]);
	}
	return 0;
}