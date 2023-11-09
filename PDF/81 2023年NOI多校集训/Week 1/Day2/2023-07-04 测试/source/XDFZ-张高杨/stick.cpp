/*
T2 木棍
重想的思路见.md文件 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=510,M=114514,Q=114514;
struct Query{
	int id,n,m;
	bool operator < (const Query oth) {return n<oth.n;}
}q[Q];
bool ans[Q];
int way[2][N*N][N];//方案哥 
int num[2][N*N];
int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int T,ptr=1;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)scanf("%d%d",&q[i].n,&q[i].m),q[i].id=i;
	sort(q+1,q+T+1);
	way[0][1][1]=1;
	for(int i=2,tot=0,last_tot=1,p=1;i<=q[T].n;i++,last_tot=tot,tot=0,p^=1)//n
	{
		memset(way[p],0,sizeof way[p]);
		for(int j=1;j<=last_tot;j++)//n^2
		{
			for(int k=0;k<i;k++)//n
			{
				if(!way[p^1][j][k]&&k!=0)continue;
				way[p][++tot][k+1]++;
				way[p^1][j][k]--;
				for(int fk=1;fk<i;fk++)way[p][tot][fk]+=way[p^1][j][fk];//n
				way[p^1][j][k]++;
				num[p][tot]=num[p^1][j]+i-1-k;
			}
		}
//		printf("%d All ways:%d\n",i,tot);
		while(q[ptr].n==i){for(int j=1;j<=tot;j++)if(num[p][j]==q[ptr].m)ans[q[ptr].id]=true;ptr++;}
	}
	for(int i=1;i<=T;i++)printf("%d\n",(int)ans[i]);
	return 0;
}
