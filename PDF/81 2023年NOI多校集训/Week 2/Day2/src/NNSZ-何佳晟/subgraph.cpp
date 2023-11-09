#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005,INF=0x3f3f3f3f;
int _;
int n,m,dfncnt,root,tag;
int M,N,B;
int in[maxn],dfn[maxn],low[maxn],scc[maxn],b;
bool vis[maxn];
vector<int>g[maxn];

struct a{
	int k;
	ll as;
};

void dfs(int x,int fath){
	dfn[x]=++dfncnt;
	low[x]=dfn[x];
	vis[x]=1;
	scc[x]=tag;
	for(int to:g[x]){
		if(to==fath)continue;
		if(vis[to]){
			low[x]=min(low[x],dfn[to]);
		}
		else {
			dfs(to,x);
			low[x]=min(low[x],low[to]);
		}
	}
	if(low[x]==dfn[x] and x!=root){
		b++;
	}
}

int main(){
    ios::sync_with_stdio(0);
    freopen("subgraph.in","r",stdin);
    freopen("subgraph.out","w",stdout);
    cin>>n>>m;
    cin>>M>>N>>B;
	
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
		in[x]+=2;
		in[y]+=2;
	} 
	a ans={0,0};
	for(int i=1;i<=n;i++) {
		if(!vis[i]){
			root=i;
			tag++;
			dfncnt=0;
			b=0;
			dfs(i,0);
			int sum1=0,sum2=0;
			int mxin=0;
			for(int j=1;j<=n;j++){
				if(scc[j]==tag){
					sum1++;
					sum2+=g[j].size();
					mxin=in[j]/2;
				}
			}
			sum2>>=1;
			ll res=1ll*M*sum2-1ll*N*sum1+1ll*b*B;
			if((res>ans.as) or (res==ans.as and mxin>ans.k)){
				ans={mxin,res};
			}
		}
	}
	
	cout<<ans.k<<" "<<ans.as<<endl;
	

    return 0;
}
