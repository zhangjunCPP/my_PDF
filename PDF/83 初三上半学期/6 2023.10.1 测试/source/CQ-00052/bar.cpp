#include<bits/stdc++.h>
using namespace std;
const int maxn=54;
int n,m,k,vis[maxn][maxn];
struct node{
	int val;
	vector<int>a;
	bool friend operator<(const node x,const node y){
		if(x.val==y.val)return x.a<y.a;
		return x.val<y.val;
	}
}dick[maxn*maxn*maxn];int tot_dick;
int E[maxn],cnt;
bool vv[maxn];
void dfs(int x,int op){
	if(x>op){
		E[++cnt]=n;
		int flag=1,tot=0;
		for(int i=1;i<cnt;++i){
			if(!vis[E[i]][E[i+1]])
				flag=0;
			tot+=vis[E[i]][E[i+1]];
		}
		if(flag){
			vector<int>gh;
			for(int i=1;i<=cnt;++i)gh.emplace_back(E[i]);
			dick[++tot_dick]={tot,gh};
		}
		cnt--;
		return;
	}
	for(int i=2;i<n;++i)
		if(!vv[i]){
			vv[i]=1;
			E[++cnt]=i;
			dfs(x+1,op);
			--cnt;
			vv[i]=0;
		}
}
signed main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		int x,y,val;scanf("%d%d%d",&x,&y,&val);
		vis[x][y]=val;
	}
	for(int lp=0;lp<=n-2;++lp){
		memset(vv,0,sizeof(vv));
		cnt=0;
		E[++cnt]=1;
		dfs(1,lp);
	}
	sort(dick+1,dick+tot_dick+1);
	if(tot_dick<k)return printf("-1"),0;
	printf("%d\n",(int)dick[k].a.size());
	for(int v:dick[k].a)
		printf("%d ",v);
	return 0;
}
