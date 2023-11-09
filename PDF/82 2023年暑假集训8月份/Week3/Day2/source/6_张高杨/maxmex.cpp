/*
B maxmex
ÍæÄãÂè 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int a[N],cnt[N];
int main()
{
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int k,mex=0,f=0;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)cnt[a[i]]++;
		while(cnt[mex])mex++;
		for(int i=k+1;i<=n;i++)
		{
			if(a[i]<mex&&!cnt[a[i]])f--;
			cnt[a[i]]++;
			cnt[a[i-k]]--;
			if(a[i-k]<mex&&!cnt[a[i-k]])f++;
			if(!f)while(cnt[mex])mex++;
		}
		for(int i=1;i<=k;i++)cnt[a[n-i+1]]--;
		printf("%d\n",mex);
	}
	return 0;
}
