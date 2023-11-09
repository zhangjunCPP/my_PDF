#include<cstdio>
#include<iostream>
using namespace std;
const int Maxn=1e6+5;
int u[Maxn],v[Maxn];
int d[Maxn][2];
int deg[Maxn];
void solve(){
	int n,m;cin>>n>>m;
	int mxdeg=0;
	for(int i=1;i<=n;++i)d[i][0]=d[i][1]=deg[i]=0;
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i];
		mxdeg=max(mxdeg,++deg[u[i]]);
		mxdeg=max(mxdeg,++deg[v[i]]);
	}
	if(mxdeg!=2){cout<<mxdeg<<'\n';return ;}
	for(int i=1;i<=m;++i){
		d[u[i]][d[u[i]][0]!=0]=v[i];
		d[v[i]][d[v[i]][0]!=0]=u[i];
	}
	for(int i=1;i<=n;++i)if(d[i][1]){
		if(d[i][0]==d[d[i][1]][0]){cout<<3<<'\n';return ;}
		if(d[i][0]==d[d[i][1]][1]){cout<<3<<'\n';return ;}
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
