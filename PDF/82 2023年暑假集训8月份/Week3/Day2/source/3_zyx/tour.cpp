#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch<='9'&&ch>='0') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
}
int n,m,q,u,v,ans;
vector <pair<int,int> > G[500001];
void dfs(int x,int val){
	if(x==v) ans=max(ans,val);
	for(auto y:G[x]) if(1ll*val*y.second<=m) dfs(y.first,val*y.second);
}
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	
	read(n),read(m),read(q);
	for(int i=2;i<=m;i++){
		read(u),read(v);
		G[u].push_back({v,i});
		G[v].push_back({u,i});
	}
	while(q--){
		read(u),read(v);
		ans=-1;
		dfs(u,1);
		printf("%d\n",ans);
	}
	return 0;
}
