#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
int n,ans,tot;
struct edge{
	int l,r,val;
}b[maxn];
vector<int>g[maxn];
bool cmp(edge x,edge y){
	return x.val>y.val;
}
int vis[maxn];
void dfs(int x){
	vis[x]=1;
	for(auto k:g[x]){
		if(vis[k])continue;
		dfs(k);
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int l,r,val;cin>>l>>r>>val;
		for(int x=l;x<=r;x++){
			if(x==i)continue;
			b[++tot]={i,x,val};
		}
	}
	sort(b+1,b+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		int x=b[i].l,y=b[i].r;
		for(int j=1;j<=n;j++)vis[j]=0;
		dfs(y);
		if(!vis[x])g[x].push_back(y),ans+=b[i].val;
	}
	cout<<ans;
	return 0;
}
//知道我盾狗的神力么？
//
//构造最大边权DAG图？什么东西
//原来可以暴力判断 大意了 
