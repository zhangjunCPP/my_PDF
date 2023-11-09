#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,tot;
long long len[500001];
vector <pair<int,int> > G[51];
vector <int> st,ans[500001];
void dfs(int x,long long vis,long long sum,vector <int> now){
	if(x==n){
		ans[++tot]=now;
		len[tot]=sum;
		return;
	}
	for(auto i:G[x]){
		if(vis>>(i.first-1)&1ll) continue;
		now.push_back(i.first);
		dfs(i.first,vis|(1ll<<(i.first-1)),sum+i.second,now);
		now.pop_back();
	}
}
bool check(int i,int j){
	if(len[i]>len[j]) return true;
	if(len[i]<len[j]) return false;
	for(int l=0;l<(int)min(ans[i].size(),ans[j].size());l++){
		if(ans[i][l]>ans[j][l]) return true;
		if(ans[i][l]<ans[j][l]) return false;
	}
	if(ans[i].size()<ans[j].size()) return false;
	else return true;
}
int main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
	}
	st.push_back(1);
	dfs(1,1,0,st);
	if(tot<k){
		printf("-1");
		return 0;
	}
	for(int i=1;i<tot;i++) for(int j=1;j<tot;j++) if(check(j,j+1)) swap(ans[j],ans[j+1]),swap(len[j],len[j+1]);
	printf("%d\n",(int)ans[k].size());
	for(auto i:ans[k]) printf("%d ",i);
	return 0;
}
