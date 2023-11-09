#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=5e5+5;
vector<int> G[maxn];
int w[maxn];
int dp1[maxn],dp2[maxn];
struct node{
	int w,v,b;
};
node czc1[maxn],czc2[maxn];
int tot1,tot2;
inline void dfs2(int x,int fa,int vv){
	czc1[++tot1]=node{w[x],dp1[x],vv};
	czc2[++tot2]=node{w[x],dp2[x],vv};
	for(auto v:G[x]){
		if(v!=fa) dfs2(v,x,vv);
	}
}
int ANS=0;
inline void dfs(int x,int fa){
	for(auto v:G[x]){
		if(v!=fa){
			dfs(v,x);
		}
	}
	tot1=0,tot2=0;
	for(auto v:G[x]){
		if(v!=fa){
			dfs2(v,x,v);
		}
	}
	dp1[x]=dp2[x]=1;
	for(int i=1;i<=tot1;i++){
		for(int j=1;j<=tot1;j++){
			if(czc1[i].b!=czc2[j].b && czc1[i].w<czc2[j].w){
				ANS=max(ANS,czc1[i].v+czc2[i].v);
			}
		}
	}
	for(int i=1;i<=tot1;i++){
		if(czc1[i].w<w[x]) dp1[x]=max(dp1[x],czc1[i].v+1);
	}
	for(int i=1;i<=tot2;i++){
		if(czc2[i].w>=w[x]) dp2[x]=max(dp2[x],czc2[i].v+1);
	}
	ANS=max(ANS,dp1[x]);
	ANS=max(ANS,dp2[x]);
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++) cin>>w[i];
	//lz ∞⁄¿√¡À°£ 
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		ANS=0;
		for(auto v:G[i]) dfs(v,i);
		ans=min(ans,ANS);
	} 
	cout<<ans;
	return 0;
} 
