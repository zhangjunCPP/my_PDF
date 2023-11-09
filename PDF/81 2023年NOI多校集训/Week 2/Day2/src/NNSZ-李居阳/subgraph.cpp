#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1e6+5;
int head[maxn],cnt;
struct edge{int to,pre;}line[maxn*2];
void addline(int u,int v)
{
	cnt++;
	line[cnt].to=v;
	line[cnt].pre=head[u];
	head[u]=cnt;
}
int M,N,B;
int k;
int d[maxn];
int main()
{
	freopen("subgraph.in","r",stdin);
	freopen("subgraph.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>M>>N>>B;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		addline(u,v);
		addline(v,u);
		d[u]++;
		d[v]++;
	}
	return 0;
}
