#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int Maxn=1e6+5;
vector<int>tr[Maxn];
int  deg[Maxn];
bool vis[Maxn];
void solve(){
	int n,m;cin>>n>>m;
	int mxdeg=0;
	for(int i=1;i<=n;++i)tr[i].resize(0),deg[i]=0,vis[i]=0;
	for(int i=1;i<=m;++i){
		int x,y;cin>>x>>y;
		mxdeg=max(mxdeg,++deg[x]);
		mxdeg=max(mxdeg,++deg[y]);
		tr[x].emplace_back(y);
		tr[y].emplace_back(x);
	}
	if(mxdeg!=2){cout<<mxdeg<<'\n';return ;}
	for(int x=1;x<=n;++x){
		for(auto y:tr[x])vis[y]=1;
		for(auto y:tr[x])for(auto z:tr[y])
			if(z!=x&&vis[z]){cout<<3<<'\n';return ;}
		for(auto y:tr[x])vis[y]=0;
	}
	cout<<2<<'\n';
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
