#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=102;
int n,q,op;using ll=long long;
int fa[N];ll dis[N],se[N];vector<pair<int,int> > E[N];
int dep[N];
void dfs(int u){
	for(auto V:E[u]){
		int v=V.first;
		if(v==fa[u])continue;
		se[v]=V.second;fa[v]=u;
		dis[v]=dis[u]+se[v];
		dep[v]=dep[u]+1;
		dfs(v);
	}
}ll lstans;
void decode(int&l,int&r,int&k,ll lastans){
	if(!op)return;
	lastans%=19260817;
	l^=lastans,l=(l%n+n)%n+1;
	r^=lastans,r=(r%n+n)%n+1;
	if(l>r)swap(l,r);
	k^=lastans;k=(k%min(r-l+1,100))+1; 
}
int a[N],vis[N];
vector<int> pos;
int p[N];
void dfs(int x,int cnt,int k){
	if(cnt==k){
		vector<int> s;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=0;i<pos.size();i++)if(p[i])s.push_back(pos[i]);
		int lca=s[0];ll sum=0;
		for(int i=1;i<k;i++){
			while(lca!=s[i]){
				if(dep[lca]<dep[s[i]]){
					sum+=(!vis[s[i]])*se[s[i]];
					vis[s[i]]=1;
					s[i]=fa[s[i]];
				}else{
					sum+=(!vis[lca])*se[lca];
					vis[lca]=1;
					lca=fa[lca];
				}
			}
		}
		lstans=max(lstans,sum);
		return; 
	}if(x==pos.size())return;
	p[x]=1;dfs(x+1,cnt+1,k);
	p[x]=0;dfs(x+1,cnt,k); 
}
int main(){
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout);
	int id=rd();
	op=rd(),n=rd();
	for(int i=1;i<n;i++){
		int u=rd(),v=rd(),w=rd();
		E[u].push_back({v,w});
		E[v].push_back({u,w});
	}dfs(1);for(int i=1;i<=n;i++)a[i]=rd();
	q=rd();while(q--){
		int l=rd(),r=rd(),k=rd();
		decode(l,r,k,lstans);
		pos.clear();
		for(int i=l;i<=r;i++)pos.push_back(a[i]);
		lstans=0;dfs(0,0,k);
		printf("%lld\n",lstans);
	}
	return 0;
}
