/*
C ccfc
呵，这种题，我真的
没得说，从头恶心到脚趾
过会儿考虑一下暴力怎么打就好了
肯定选择40pts的暴力，我们暴力枚举 $i$，然后暴力枚举 $A$，然后暴力判断 $A$ 就可以了
*/
#include<bits/stdc++.h>
using namespace std;
char s[114514];
int ans[114514];
int main()
{
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=n;i;i--)
	{
		for(int j=n;j>n-(n-i)/3;j--)
		{
			int len=n-j+1;
			bool ad=true;
			for(int k=1;k<=2*len;k++)if(s[i+k-1]!=s[j+(k-1)%len])ad=false;
			ans[i]+=ad;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
