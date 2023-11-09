#include<bits/stdc++.h>
using namespace std;
int a[60],b[60];
inline int calc(int tot)
{
//	for(int i=1;i<=tot;i++)printf("%d ",b[i]);
//	putchar(10);
	if(tot%4)return 0;
	for(int i=1;i<=tot/4;i++)if(b[i*4-3]!=b[i*4-1]||b[i*4-2]!=b[i*4])return 0;
//	puts("OK");
	return tot;
}
int ans,n;
void DFS(int i,int tot)
{
	if(i>n)
	{
		ans=max(ans,calc(tot));
		return;
	}
	DFS(i+1,tot);
	b[++tot]=a[i];
	DFS(i+1,tot);
	return;
}
int main()
{
	freopen("comb.in","r",stdin);
	freopen("comb.bf","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	DFS(1,0);
	printf("%d",ans);
	return 0;
}
