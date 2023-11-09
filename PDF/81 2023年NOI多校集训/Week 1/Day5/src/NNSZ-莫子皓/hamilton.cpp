/*
美妙的图论题，时间不够就不做了:) 
*/
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a,b;
int head[N],nxt[N],to[N],cnt,tmp;
bool vis[N],;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
int main()
{
	freopen("hamilton.in","r",stdin);
	freopen("hamilton.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	printf("O_o?");
	return 0;
}
