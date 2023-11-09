#include<bits/stdc++.h>
using namespace std;
bool memr[501][2501];
int pingxinggroup[500],n,m; 
void cut(int nn,int cutted,int pxg[])
{
	//printf("cut(nn:%d cutted:%d)\n",nn,cutted);
	if(nn==0)
	{
		int tot=0;
		for(int i=1;i<cutted;i++)
			for(int j=i+1;j<=cutted;j++)
				tot+=pxg[i]*pxg[j];
		memr[n][tot]=true;
		return;
	} 
	for(int i=nn;i>=nn/2;i--)
	{
		if(nn&1==1 and i==nn/2)break;
		pxg[cutted+1]=i;
		cut(nn-i,cutted+1,pxg);
	}
	return;
 } 
int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	memr[1][0]=true;memr[3][3]=true;memr[4][4]=true;memr[4][5]=false;memr[4][6]=true;memr[5][8]=true;memr[5][10]=true;
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>n>>m;
		if(!memr[n][0])
			for(int j=n;j>=n/2;j--)
			{
				if(n&1==1 and j==n/2)break;
				pingxinggroup[1]=j;
				cut(n-j,1,pingxinggroup);
			}
		if(memr[n][m])cout<<1<<endl;
		else cout<<0<<endl;
	}
	/*for(int i=1;i<=500;i++)
	{
		for(int j=0;j<=100;j++)printf("%d ",memr[i][j]);
		printf(" \n");
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}

