#include<bits/stdc++.h>
using namespace std;//dp[i][j]��ʾ�ڵ�i�ν�������԰ʱѡ��j��Ʊ�����ֵ 
int n,k;
int t[10010],num[510],cost[510];
long long sum,minn[505],dp[505][100005];
bool loc[505][100005];//true��ʾ��ʱΪʱ��Ʊ��Ч�ڼ䣬���ɸ��� 
int main()
{
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	
	//���� 
	cin>>n>>k>>t[1];
	for(int i=2;i<=n;i++)
	{
		cin>>t[i];
		t[i]-=t[1];
	}
	t[1]=0;
	for(int i=1;i<=k;i++)
	{
		cin>>num[i]>>cost[i];
		//Ԥ���� 
		dp[1][i]=cost[i],loc[1][i]=true;
		for(int j=2;j<=num[i];j++) //��jʱ�� 
		{
			if(t[j]<=num[i] and t[j]!=0)
			{
				dp[j][i]=cost[i];
				loc[j][i]=true;
			}
			else 
			{
				break;
			}
		}
	}
	cin>>cost[k+1];
	num[k+1]=0;
	dp[1][k+1]=cost[k+1];
	
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			cout<<cost[1]<<endl;
		return 0;
	}
	
	for(int i=1;i<=n;i++)//��iʱ�� 
	{
		for(int j=1;j<=k+1;j++)//ѡ���j��Ʊ 
		{
			if(!loc[i][j])//��ǰ��δ���� 
			{
				if(j==k+1 and i!=1)dp[i][j]=dp[i-1][j]+cost[j];
			
				int len;
				for(int y=i;y>=1;y--)
					if(t[y]<t[i]-num[j]+1)
					{
						len=y+1;
						break;
					}
				int yy=len;dp[i][j]=dp[i-1][j]+cost[j]; 
				for(int y=len;y<=i-1;y++)//dp����iʱ�����j��Ʊʱ����С���� 
					if(dp[i][j]>minn[y]+cost[j])
					{
						dp[i][j]=minn[y]+cost[j];
						yy=y;
					}
				
				if(j!=k+1)
					for(int z=yy;z<=yy+num[i]-1;z++) //���Ϊʱ��Ʊ��������������� 
					{
						if(t[z]<=num[j]+t[yy]-1 and (t[z]!=0 or z==1))//����ʱ��Ʊʱ���ڣ������� 
							loc[i][j]=true;
						else 
							break;
					}
			}
			if(j==1)
				minn[i]=dp[i][j];
			else
				minn[i]=min(minn[i],dp[i][j]);
//			cout<<minn<<endl;
		}
		cout<<minn[i]-minn[i-1]<<endl;
	}
	/*
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=10;j++)printf("%d ",dp[i][j]);
		printf("\n");
	}
	printf("\n");
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=10;j++)printf("%d ",loc[i][j]);
		printf("\n");
	}
	*/
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
 /*
3 2
10 20 30
90 50
1440 120
20


10 2
13 45 46 60 103 115 126 150 256 516
90 45
450 100
20
 */ 
