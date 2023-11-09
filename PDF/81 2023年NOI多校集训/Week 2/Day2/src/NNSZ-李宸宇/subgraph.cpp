#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,M=N*2;

int head[N],ver[M],nxt[M],tot=1;
void add(int x,int y){
	ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;
}

int a[N],deg[N],n,m,A,B,C,maxk=0x3f3f3f3f;

signed main(){
	freopen("subgraph.in","r",stdin);
	freopen("subgraph.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&A,&B,&C);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x),deg[x]++,deg[y]++;
	for(int i=1;i<=n;i++)maxk=min(maxk,deg[i]);
	printf("%d %d\n",maxk,A*m-B*n);
	return 0;
}
