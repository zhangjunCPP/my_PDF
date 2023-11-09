#include<bits/stdc++.h>
using namespace std;
const int N=2e6+2;
int n,m,t,d[N],low[N],dfn[N],tot,sum,top,st[N];
int b[N],c[N];
vector<int>e[N];
void tarjan(int x,int fa){
	low[x]=dfn[x]=++tot;
	st[++top]=x;
	for(int y:e[x]){
		if(!dfn[y]){
			tarjan(y,x);
			dfn[x]=min(dfn[y],dfn[x]);
		}else if(!b[y]&&y!=fa){
			dfn[x]=min(dfn[x],low[y]);
		}
	}
	if(low[x]==dfn[x]){
		int y=-1;
		sum++;
		while(y!=x){
			y=st[top--];
			b[y]=sum;
			c[sum]++;
		}
	}
}
int main(){//100£¿ 
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&t); 
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			d[i]=0;
			low[i]=dfn[i]=0;
			b[i]=0,c[i]=0;
			st[i]=0;
			e[i].clear();
		}
		top=0;sum=0;tot=0;
		for(int i=1,x,y;i<=m;i++){
			scanf("%d%d",&x,&y);
			d[x]++,d[y]++;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			if(!low[i])tarjan(i,0);
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(d[i],mx);
			if(c[b[i]]==3)mx=max(c[b[i]],mx);
		}
		printf("%d\n",mx);
	}
	return 0;
}

