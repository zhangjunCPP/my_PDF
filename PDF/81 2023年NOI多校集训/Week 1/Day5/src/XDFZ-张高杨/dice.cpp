/*
T1 dice
ע�⵽k��ʵ��С
���Ƿ���k�Ķ�����λ�϶���6λ���ڵģ����ǵ�����ȴ�����нӽ�20λ
����˵�������ÿ��������ͬ�����ǿ϶��ܹ������������ܼ�
Ŀǰ������������û��ban����һ��������������Ǿ���һ�԰�
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
