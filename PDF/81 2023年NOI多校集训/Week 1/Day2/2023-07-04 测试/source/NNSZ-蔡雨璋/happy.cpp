#include<bits/stdc++.h>
using namespace std;//dp[i][j]表示在第i次进入游乐园时选择j种票的最大值 
int n,k;
int t[10010],num[510],cost[510];
long long sum,minn[505],dp[505][100005];
bool loc[505][100005];//true表示此时为时限票生效期间，不可更改 
int main()
{
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	
	//输入 
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
		//预处理 
		dp[1][i]=cost[i],loc[1][i]=true;
		for(int j=2;j<=num[i];j++) //在j时刻 
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
	
	for(int i=1;i<=n;i++)//在i时刻 
	{
		for(int j=1;j<=k+1;j++)//选择第j种票 
		{
			if(!loc[i][j])//当前格未上锁 
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
				for(int y=len;y<=i-1;y++)//dp找在i时刻买第j种票时的最小花费 
					if(dp[i][j]>minn[y]+cost[j])
					{
						dp[i][j]=minn[y]+cost[j];
						yy=y;
					}
				
				if(j!=k+1)
					for(int z=yy;z<=yy+num[i]-1;z++) //如果为时限票，则进行上锁操作 
					{
						if(t[z]<=num[j]+t[yy]-1 and (t[z]!=0 or z==1))//处于时限票时限内，则上锁 
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
