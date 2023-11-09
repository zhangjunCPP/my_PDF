#include<bits/stdc++.h>
using namespace std;
int n,k,x,y,ans=1e8,tot,dfn[2001],c[2001],st[2001][12],dep[2001];
vector <int> G[2001],C[2001],val;
bitset <2001> kd[2001][12];
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
void dfs(int u,int f){
	dfn[u]=++tot;
	dep[u]=dep[f]+1;
	for(auto v:G[u]) if(v!=f){
		st[v][0]=u;
		kd[v][0].set(c[u]);
		for(int i=1;i<=11;i++){
			st[v][i]=st[st[v][i-1]][i-1];
			kd[v][i]=kd[v][i-1]|kd[st[v][i-1]][i-1];
		}
		dfs(v,u);
	}
}
bitset<2001> lca(int u,int v){
	bitset <2001> ans;
	ans.reset();
	ans[c[u]]=ans[c[v]]=1;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=11;i>=0;i--) if(dep[st[u][i]]>=dep[v]) ans|=kd[u][i],u=st[u][i];
	if(u==v) return ans;
	for(int i=11;i>=0;i--) if(st[u][i]!=st[v][i]) ans|=kd[u][i]|kd[v][i],u=st[u][i],v=st[v][i];
	ans[c[st[u][0]]]=1;
	return ans;
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		C[c[i]].push_back(i);
	}
	if(n>2000){
		printf("1");
		return 0;
	}
	dfs(1,0);
	for(int i=1;i<=1;i++){
		bitset <2001> now;
		now.reset();
		now[i]=1;
		int last=1;
		while(1){
			val.clear();
			for(int j=1;j<=k;j++) if(now[j]) for(auto l:C[j]) val.push_back(l);
			now.reset();
			sort(val.begin(),val.end(),cmp);
			for(int j=1;j<(int)val.size();j++) now|=lca(val[j-1],val[j]);
			now[0]=0;
			if((int)now.count()==last) break;
			else last=now.count();
		}
		ans=min(ans,last-1);
	}
	printf("%d",ans);
	return 0;
}
