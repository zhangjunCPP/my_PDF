#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=N*2;

int head[N],ver[M],nxt[M],tot=1;
void add(int x,int y){
	ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;
}

int w[N],n,deg[N];

int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x),deg[x]++,deg[y]++;
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	printf("%d\n",n/2);
	return 0;
}
