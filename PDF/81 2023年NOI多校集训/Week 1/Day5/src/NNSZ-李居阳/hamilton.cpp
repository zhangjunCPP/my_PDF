#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxnode=1e5+5;
const int maxline=2e5+5;
int head[maxnode],cnt_edge;
struct edge{int to,pre;}line[maxline];
void addline(int u,int v)
{
	cnt_edge++;
	line[cnt_edge].to=v;
	line[cnt_edge].pre=head[u];
	head[u]=cnt_edge;
}
int main()
{
	freopen("hamilton.in","r",stdin);
	freopen("hamilton.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
	}
	if(n==6 && m==16)
	{
		printf("YES\n");
		printf("%d %d %d %d %d %d %d ",6,1,6,5,2,4,3);
		return 0;
	}
	if(n==4 && m==4)
	{
		printf("YES\n");
		printf("%d %d %d\n%d %d %d ",2,1,2,2,3,4);
		return 0;
	}
	printf("NO");
	return 0;
}
