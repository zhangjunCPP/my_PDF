/*
D match
��ʵ����2���ĺ�����ֱ�Ӿ�˵����ÿ����ֻ��ѡ��һ��������λ
��Ϊ������������ѡ����ͬһ��������λ�������ζ��һ�������AND!=0�����
����ʵ�����ǹ��������м���ѭ
ע��OR����������ԣ�$s$ ������С�ڸ����� $b$ ȫ����������ֵ
�����Ȱ� $b$ ��ȫ�����ã�Ȼ������ô��ÿ�� $1$ ֻ��һ����ռ��
�Ȳ����Ǹ�
$\sum p_k \le 10^6$ �������������ô�����Ǻܹؼ���
��������д����
������
$n=2$ �������ô�����
����ֻ��Ҫ�ҵ���ͻ�����λ��Ȼ��ѽϴ���Ǹ��ĳ�ͻ��ȡ�����ͺ��� 
*/
#include<bits/stdc++.h>
using namespace std;
bitset<1919810>ans;
int p[1919810],q[1919810];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,m,k[2];
	scanf("%d%d",&n,&m);
	if(n>2){for(int i=1;i<=m;i++)putchar('1');return 0;}//��
	if(n==1)
	{
		scanf("%d",k);
		for(int i=1;i<=k[0];i++)
		{
			scanf("%d",p+i);
			ans[p[i]-1]=1;
		}
		for(int i=m-1;i>=0;i--)printf("%d",(int)ans[i]);
		return 0;
	}
	int ptr[2];
	scanf("%d",k);for(int j=1;j<=k[0];j++)scanf("%d",p+j);ptr[0]=k[0];
	scanf("%d",k+1);for(int j=1;j<=k[1];j++)scanf("%d",q+j);ptr[1]=k[1];
	while(ptr[0]&&ptr[1])
	{
		while(p[ptr[0]]>q[ptr[1]])ans[p[ptr[0]--]]=1;
		if(p[ptr[0]]==q[ptr[1]])break;
		ans[q[ptr[1]--]]=1;
	}
	if(!ptr[0]||!ptr[1])
	{
		while(ptr[0])ans[p[ptr[0]--]]=1;
		while(ptr[1])ans[p[ptr[1]--]]=1;
		for(int i=m;i;i--)printf("%d",(int)ans[i]);
		return 0;
	}
	int x=p[ptr[0]];
	ans[x]=1;
	while(ans[x])ans[x]=0,x++;
	ans[x]=1;
	while(p[ptr[0]]==q[ptr[1]]&&ptr[0]&&ptr[1])ans[p[ptr[0]]]=1,ptr[0]--,ptr[1]--;
	if(p[ptr[0]]>q[ptr[1]])while(ptr[1])ans[q[ptr[1]]]=1,ptr[1]--;
	else while(ptr[0])ans[p[ptr[0]]]=1,ptr[0]--;
	for(int i=m;i;i--)printf("%d",(int)ans[i]);
	return 0;
}
