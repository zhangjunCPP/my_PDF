#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int MAXN=1e6+10;
void Freopen(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
}
int T,n,m,k;
int ans=0,num[MAXN],u[MAXN],v[MAXN],diff[MAXN],same[MAXN];
vector<int> G[MAXN<<1];
map<pair<int,int> ,pair<int,int> > mp;
bitset<MAXN> vis;
void dfs(int last,int sum,int u){
	printf("u:%d\n",u);
	if(sum==0) return ;
	if(vis.count()==n){
		ans=(ans+sum)%mod;
		return ;
	}
	for(auto v:G[u]){//当前传输中心能到的下一个地方 
		if(vis[v]) continue;
		vis[v]=true;
		for(int i=1;i<=k;i++){//枚举下一个地方放哪个国家 
			if(last==i) dfs(i,sum*mp[{u,v}].second%mod,v);
			else dfs(i,sum*mp[{u,v}].first%mod,v);
		}
//		vis[v]=false;
	}
}
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		if(n==2){
			int ans1=1,ans2=1;
			for(int i=1;i<=m;i++){
				int u,v,diff,same; 
				scanf("%lld%lld%lld%lld",&u,&v,&diff,&same);
				ans1=ans1*same%mod; ans2=ans2*diff%mod; 
			} 
//			printf("%lld %lld\n",ans1,ans2);
			printf("%lld",(ans1*k%mod+ans2*k%mod*(k-1)%mod));
			continue;
		}
		ans=0;
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld%lld",&u[i],&v[i],&diff[i],&same[i]);
//			G[u[i]].push_back(v[i]); G[v[i]].push_back(u[i]);
			if(mp[{u[i],v[i]}].first==0 && mp[{v[i],u[i]}].first==0) {
				G[u[i]].push_back(v[i]); G[v[i]].push_back(u[i]);
				mp[{u[i],v[i]}]=mp[{v[i],u[i]}]={diff[i],same[i]};
			}
			else{
				mp[{u[i],v[i]}].first=mp[{u[i],v[i]}].first*diff[i]%mod; 
				mp[{v[i],u[i]}].first=mp[{u[i],v[i]}].first;
				mp[{u[i],v[i]}].second=mp[{u[i],v[i]}].second*same[i]%mod; 
				mp[{v[i],u[i]}].second=mp[{u[i],v[i]}].second;
			}
		}
//		printf("%d %d\n",mp[{1,4}].first,mp[{1,4}].second);
		vis[1]=true;//放第一个位置 
		for(int i=1;i<=k;i++) dfs(i,1,1);//枚举放什么 
		for(int i=1;i<=n;i++) vis[i]=false;
		for(int i=1;i<=m;i++){
			mp[{u[i],v[i]}].first=mp[{v[i],u[i]}].first=0;
			mp[{u[i],v[i]}].second=mp[{v[i],u[i]}].second=0; 
//			for(int j=0;j<(int)G[u[i]].size();j++) G[u[i]][j]=G[j][u[i]]=0;
		}
		printf("%lld\n",ans%mod);
	}
	return 0;
} 
