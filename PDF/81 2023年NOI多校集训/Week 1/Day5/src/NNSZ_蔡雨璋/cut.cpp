#include<bits/stdc++.h>
using namespace std;
int n,a[100010]={},ans=1,cut[100010]={},situ[100010]={},dp[100010]={},tot=0;

int check(int si)
{
	for(int i=0;i<=20;i++)
		if(((1<<(i))&si)==0)
		{
//			cout<<bitset<5> (si)<<' '<<i<<endl;
			return i;
		}
	return 20;
}


int main()
{
	freopen("cut.in","r",stdin); 
	freopen("cut.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cut[1]=1;
	for(int i=1;i<=n;i++)
	{
		if( !(situ[ans]&(1<<a[i])) )
			situ[ans]+=(1<<a[i]);
		else
		{
			dp[ans]=check(situ[ans]);
			cut[++ans]=i;situ[ans]+=(1<<a[i]); 
		}
	}
	dp[ans]=check(situ[ans]);
	for(int i=1;i<=ans;i++)
	{
//		printf("dp[%d]:%d\nsitu[%d]:",i,dp[i],i);cout<<bitset<5> (situ[i])<<endl;
		tot+=dp[i];
//		printf("tot+=dp[%d],tot=%d\n",i,tot);
	}
	printf("%d %d\n",tot,ans);
	for(int i=1;i<=ans;i++)printf("%d ",cut[i]);
	return 0;
}
/*
��һ�۵�ʱ��ȷʵ����ס��...
������ϸһ����������ģ��һ�£��ͻᷢ��
ֱ�Ӵӵ�һ������ʼö�٣����������뵱ǰ��ѡ���е�Ԫ���Ƿ��ظ�������ظ��˾�cut�������¼�¼ 
�ȵȣ�����û��ô�� 
����� 1 0 2 5 3 4 0 6 7��
�����Դ���8�����������������뷨�Ļ����ڵڶ���0��cut�����ó�����7
��
�ȵȣ���״ѹdp�� 
dp[i][j]����i״̬��ѡ��j����(k)��mex�����ֵ 
ת��ʽ����dp[i][j]=max(dp[i-(1<<(k-1)][j-1],dp[1<<(k-1)][j]); 
����Ҳ����......һ���� 1,048,575 ��״̬���ռ临�Ӷ�һ���ᱬը 
�ټ�һ�� 
mad���ɴ�ֱ��
for(int i=1;i<n;i++)ö���м��� 
	int cut=i;
	for(int j=1;j<=n;j++)//�����ĸ�λ���� 
		Ȼ��ֱ�ӱ������ 
		...
�ļļļ� 
�ȵ�
�����������
�Ȱ���һ��˼·Ԥ����Ȼ����������for�������������ƴ������ֵ��ԭ�����󣬾��ȼ�¼���� 
��������ô��.. 
mad���о�֮ǰ��״ѹ��ħ���ˣ�����������ȫ��״ѹ 
�Ǿ���״ѹ���ԣ���situ[]��Ԥ�����ÿ�ε���ɫ״̬�������ƣ��ϲ����� | ����λ��
�ð�...������ʱ��д����ֻ�ܰ���һ�ַ���д��... 
*/
