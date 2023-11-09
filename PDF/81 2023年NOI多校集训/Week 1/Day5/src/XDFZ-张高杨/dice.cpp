/*
T1 dice
注意到k其实很小
我们发现k的二进制位肯定是6位以内的，我们的骰子却可以有接近20位
所以说如果允许每个骰子相同，我们肯定能够构造出来，这很简单
目前就题意来看，没有ban掉这一种情况，于是我们就试一试吧
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%d %d %d %d %d %d\n",k,(k<<6),(k<<12),k|(k<<6),k|(k<<12),k|(k<<6)|(k<<12));
	return 0;
}
