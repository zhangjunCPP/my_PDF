#include<bits/stdc++.h>
#define N 2000005
using namespace std;
struct A{
	int ne,v;
}a[N<<1];
int T,n,m,cnt,head[N],vis[N],num[N],nxt,ans;
void add(int u,int v){
	cnt++;
	a[cnt].v=v;
	a[cnt].ne=head[u];
	head[u]=cnt;
}
void find(int x,int from){
	for(int i=head[x];i;i=a[i].ne){
		int v=a[i].v;
		if(vis[v]&&v!=from)nxt++;
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	cnt=ans=0;
	for(int i=1;i<=n;i++)head[i]=num[i]=0;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		num[x]++;
		num[y]++;
	}
	for(int x=1;x<=n;x++){
		ans=max(ans,num[x]);
		for(int i=head[x];i;i=a[i].ne)vis[a[i].v]=1;
		for(int i=head[x];i;i=a[i].ne){
			nxt=0;
			find(a[i].v,x);
			ans=max(ans,nxt*2+1);
		}
		for(int i=head[x];i;i=a[i].ne)vis[a[i].v]=0;
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
/*
3
4 1
2 3
1 0
5 4
3 2
5 3
5 1
4 5
*/
