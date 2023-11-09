#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int n,m,q,ans,num,cnt[30],vis[30],u[30],v[30],pw[200],nxt[200],siz[200];
void dfs(int x,int now){
	if(now==num)return ans=(ans+pw[siz[x]])%p,void();
	if(x==m+1)return;
	//²»²Ù×÷
	dfs(nxt[x],now);
	//²Ù×÷
	now+=(++cnt[u[x]]==2);
	now+=(++cnt[v[x]]==2);
	dfs(nxt[x],now);
	now+=(cnt[u[x]]--==2);
	now+=(cnt[v[x]]--==2);
}
void Freopen(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&m);
	pw[0]=1;
	for(int i=1;i<=m;i++)pw[i]=1ll*pw[i-1]*2%p;
	for(int i=1;i<=m;i++)scanf("%d%d",&u[i],&v[i]);
	scanf("%d",&q);getchar();
	while(q--){
		ans=num=0;
		for(int i=1;i<=n;i++)vis[i]=getchar()-'0',num+=vis[i];
		for(int i=m+1;i!=-1;i--){
			nxt[i]=m+1;siz[i]=0;
			for(int j=m;j>i;j--)if(vis[u[j]]&&vis[v[j]])
				nxt[i]=j,siz[i]++;
			siz[i]+=(vis[u[i]]&&vis[v[i]]);
		}
		dfs(nxt[0],0);
		printf("%d\n",ans);
		getchar();
	}
}
/*
5 8
1 2
2 3
3 4
4 1
1 5
2 5
3 5
4 5
3
11111
01111
11110

5 8
1 2
2 3
3 4
4 1
1 5
2 5
3 5
4 5
1
01111
11110

*/
