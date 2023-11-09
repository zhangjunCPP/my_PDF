#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==1)
	{
		printf("Yes\n");
		printf("%d %d %d %d %d %d",k,k*2,k*3,k*4,k*5);
		return 0;
	 } 
	else if(k==2)
	{
		printf("Yes\n");
		if(n%2)
		{
			for(int i=1;i<n;i++)printf("%d %d %d %d %d %d",k-1,k*2-1,k*3-1,k*4-1,k*5-1);
			printf("%d %d %d %d %d %d",k,k*2,k*3,k*4,k*5);
		}
		else
		{
			for(int i=1;i<=n;i++)printf("%d %d %d %d %d %d",k-1,k*2-1,k*3-1,k*4-1,k*5-1);
		}
	}
	else
		printf("No");
	return 0;
}
/*
异或和是什么...
没看懂，懵了好久... 
第一问干脆拿30分就够了... 
*/ 
