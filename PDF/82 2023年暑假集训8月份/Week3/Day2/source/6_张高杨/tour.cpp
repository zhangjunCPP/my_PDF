/*
C tour
暴力的话，做法很多 
*/
#include<bits/stdc++.h>
using namespace std;
inline void r(int &x)
{
	char c;
	x=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9')x*=10,x+=c-'0',c=getchar();
	return;
}
const int N=500010,M=500010;
struct edge{
	int v,nex,w;
}e[M*2];
int fir[N],ent;
inline void add(int u,int v,int w)
{
	e[++ent]={v,fir[u],w};
	fir[u]=ent;
	return;
}
int n,m,q;
int s,t,ans;
void DFS(int u,int val)
{
	if(u==t)ans=max(ans,val);
	for(int i=fir[u];i&&e[i].w*val<=m;i=e[i].nex)
	{
		int v=e[i].v;
		DFS(v,e[i].w*val);
	}
	return;
}
pair<int,int>P[M];
int main()
{
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	r(n),r(m),r(q);
	ent=m*2-1;
	for(int i=1;i<m;i++)r(P[i].first),r(P[i].second);
	for(int i=m-1;i;i--)add(P[i].first,P[i].second,i+1),add(P[i].second,P[i].first,i+1);
	for(int i=1;i<=q;i++)
	{
		r(s),r(t);
		ans=-1;
		DFS(s,1);
		printf("%d\n",ans);
	}
	return 0;
}
