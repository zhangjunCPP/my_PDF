#include<bits/stdc++.h>
using namespace std;
#define f first 
#define s second
int n,m,len,path[100005];
int in[100005],out[100005];
int vi[100005],vo[100005];
pair<int,int> e[200005];int vis[200005];
int go[100005];
void Freopen(){
	freopen("hamilton.in","r",stdin);
	freopen("hamilton.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&e[i].f,&e[i].s);
		++out[e[i].f];++in[e[i].s];
	}
	for(int i=1;i<=m;i++)
		if(in[e[i].s]==1||out[e[i].f]==1){
			if(vi[e[i].s]||vo[e[i].f])return puts("NO"),0;
			vi[e[i].s]=1;
			vo[e[i].f]=1;
			vis[i]=1;
			go[e[i].f]=e[i].s;
		}
	for(int i=1;i<=m;i++)if(!vis[i])
		if(!vi[e[i].s]&&!vo[e[i].f]){
			go[e[i].f]=e[i].s;
			vi[e[i].s]=vo[e[i].f]=1;
		}
	for(int i=1;i<=n;i++)if(!vi[i]||!vo[i])return puts("NO"),0;
	puts("YES");
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)if(!vis[i]){
		int j=i;len=0;
		do{
			j=go[j];
			path[++len]=j;
			vis[j]=1;
		}while(j!=i);
		printf("%d ",len);
		for(int j=1;j<=len;j++)printf("%d ",path[j]);
		puts("");
	}
}