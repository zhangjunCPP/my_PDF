#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+16;
const int mod=1e9+7;
int n,dc;
vector<int> eg[N];
int ksm(int x,int y) {
	int ans=1;
	while(y) {
		if(y&1) ans=( ans*x )%mod;
		x=( x*x )%mod; y>>=1;
	}
	return ans;
}
int d[N],fa[N][30];
void init(int u,int dad) {
	d[u]=d[dad]+1;
	fa[u][0]=dad;
	for(int i=0;i<=20;i++) fa[u][i+1]=fa[ fa[u][i] ][i];
	for(int i=0;i<(int)eg[u].size();i++) {
		int v=eg[u][i];
		if(v==dad) continue;
		init(v,u);
	}
}
int LCA(int u,int v) {
	if(d[u]<d[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(d[ fa[u][i] ]>=d[v]) u=fa[u][i];
	if(u==v) return v;
	for(int i=20;i>=0;i--) if( fa[u][i] != fa[v][i] ) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int col[N],asn,toto;
void dfs2(int k) {
	if(k>n) {
		toto++; //cout<<toto<<" ";
		int mx=0;
		//for(int i=1;i<=n;i++) cout<<col[i]<<" "; puts("");
		for(int i=1;i<=n;i++) {
			//cout<<col[i]<<" ";
			for(int j=1;j<=n;j++) {
				if(col[i]!=col[j]||i==j) continue;
				int lca=LCA(i,j);
				int lent=d[i]+d[j]-2*d[lca];
				//cout<<lent<<" ";
				mx=max(mx,lent);
			}
		}
		//puts("");
		asn+=mx;
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!col[i]) {
			
			col[i]=1;
			dfs2(k+1);
			col[i]=0;
			
			//cout<<i<<"  1@ \n";
			
			col[i]=2;
			dfs2(k+1);
			col[i]=0; 
			
			//cout<<i<<"  2@ \n";
			break;
		}
	}
}
signed main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	bool fl=true;
	for(int i=1;i<n;i++) {
		int u,v; scanf("%lld%lld",&u,&v);
		eg[u].push_back(v);
		eg[v].push_back(u);
		if(u==1||v==1) dc++;
		if( u!=i||v!=i+1 ) fl=false;
	}
	if(fl) {
		int ans=0;
		for(int k=1;k<=n;k++) {
			int sm=0;
			if(2*k>n) sm=( sm+( (k-1)*ksm( 2ll,2*k-n-2+1 ) )%mod )%mod;
			if(k!=n) sm=( sm*2ll )%mod;
			//cout<<sm<<"    ";
			int l=max(0ll,n-2*k),r=min(k,n-k);
			l++; r--;
			int si=r-l+1;
			if(si<0) si=0;
			//cout<<l<<" "<<r<<" "<<si<<endl;
			sm=( sm+(k-1)*( si*2ll %mod )%mod )%mod;
			ans=( ans+sm )%mod;
			//cout<<ans<<" \n";
		}
		printf("%lld",ans);
		return 0;
	}
	if(dc==n-1) {
		if(n==3) { puts("6"); return 0; }
		int ans=ksm(2ll,n+1);
		printf("%lld\n",ans);
		return 0;
	}
	init(1,0);
	//for(int i=1;i<=n;i++) cout<<d[i]<<" "; puts("");
	dfs2(1);
	printf("%d",asn);
	return 0;
}
/*
2
1 2

6
1 2
2 3
3 4
4 5
3 6



*/
