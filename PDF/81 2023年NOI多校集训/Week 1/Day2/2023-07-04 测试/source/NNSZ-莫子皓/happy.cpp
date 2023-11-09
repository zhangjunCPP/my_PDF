#include <bits/stdc++.h>
using namespace std;
int n,k,one,used=-1,c,l,p,tt,ch;
long long sum1,sum2; 
int t[100005];
struct ti{
	int time;
	int cost;
}ticket[505];
int main()
{
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>t[i];
	for(int i=0;i<k;i++) cin>>ticket[i].time>>ticket[i].cost;
	cin>>one;
	//if(k==0)
	//	for(int i=0;i<n;i++) cout<<one<<endl;
	for(int i=0;i<n;i++)
	{
		//cout<<i+1<<"|";
		sum2=one*(i+1);
		for(int j=0;j<k;j++)
		{
			ch=-1;
			if(ticket[j].time>=t[i] && ticket[j].cost<one*(i+1) && ticket[j].cost<sum2)
			{
				sum2=ticket[j].cost;
				//printf("(%d)(%lld)",j,sum2);
			}
			for(int q=i;q>=0;q--)
				if(ticket[j].time > t[i]-t[q] && ticket[j].cost+one*q<one*(i+1) &&  ticket[j].cost+one*q<sum2)
				{
					sum2=ticket[j].cost+one*(q);
					//printf("(%d)(%lld)",j,sum2);
				}
			for(int q=0;q<=i;q++)
			{
				tt=t[q]+ticket[j].time;
				for(int z=q;z<=i;z++)
					if(t[z]>=tt)
					{
						ch=z;
						break;
					}
				if(ch!=-1)
				{
					tt=one*(q+i+1-ch)+ticket[j].cost;
				}
				else
				{
					tt=ticket[j].cost+one*(q);
				}
				if(tt<sum2) sum2=tt;
				//printf("(%d)(%lld)(%d)",j,sum2,ch);
			}
		}
		cout<<sum2-sum1<<endl;
		sum1=sum2;
	}
	return 0;
} 
/*
先判断是否可以用比正常少的票
然后记录这张票的使用期限好让后面享福
如果用完了就加上票的期限减去 
如何特判用了普通票再用时限票？ 
*/ 
