#include<bits/stdc++.h>
//#define int long long
const int N=3e6,inf=1e9+10;
void Freopen() {
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
}
using namespace std;
int k,n,m,tot,s,t,ans;
struct node {
	int x,y;
} p[N],sb[N];
int fa[N];
map<pair< int , int >, int >vis;
void mk( int i, int j, int o) {
	if (vis.count({i,j})) return;
	vis[{i,j}]=1;
	p[++tot]={i,j};
	fa[tot]=o;
	if (i==n&&j==m) {
		cout<<ans<<endl;
		int oo=0;
		for ( int f=tot; f!=1; f=fa[f]) 
			sb[++oo].x=p[f].x,sb[oo].y=p[f].y;
		for ( int i=oo; i; i--) 
			cout<<sb[i].x<<" "<<sb[i].y<<endl;
		exit(0);
	}	
}
void ck( int i, int j, int o) {
	if (vis.count({i,j})) return;
	vis[{i,j}]=1;
	if (i==n&&j==m) {
		cout<<ans<<endl;
		int oo=0;
		sb[++oo].x=i,sb[oo].y=j;
		for ( int f=o; f!=1; f=fa[f]) 
			sb[++oo].x=p[f].x,sb[oo].y=p[f].y;
		for ( int i=oo; i; i--) 
			cout<<sb[i].x<<" "<<sb[i].y<<endl;
		exit(0);
	}	
}
signed main() {
	Freopen();
	cin>>k>>n>>m;
	if (k>11) return cout<<-1,0;
	p[++tot]={0,0};
	ans++;
	for ( int i=0; i<=k; i++) {
		int j=k-i;
		mk(i,j,1),mk(-i,j,1),mk(i,-j,1),mk(-i,-j,1);
	}
	ans++;
	s=2,t=tot;
	for ( int o=s; o<=t; o++) {
		int x=p[o].x,y=p[o].y;
		for ( int i=0; i<=k; i++) {
			int j=k-i;
			mk(x+i,y+j,o),mk(x-i,y+j,o),mk(x+i,y-j,o),mk(x-i,y-j,o);
		}	
	}
	ans++;
	s=t+1,t=tot;
	for ( int o=s; o<=t; o++) {
		int x=p[o].x,y=p[o].y;
		for ( int i=0; i<=k; i++) {
			int j=k-i;
			mk(x+i,y+j,o),mk(x-i,y+j,o),mk(x+i,y-j,o),mk(x-i,y-j,o);
		}	
	}	
	ans++;
	s=t+1,t=tot;
	for ( int o=s; o<=t; o++) {
		int x=p[o].x,y=p[o].y;
		for ( int i=0; i<=k; i++) {
			int j=k-i;
			mk(x+i,y+j,o),mk(x-i,y+j,o),mk(x+i,y-j,o),mk(x-i,y-j,o);
		}	
	}
	ans++;
	s=t+1,t=tot;
	for ( int o=s; o<=t; o++) {
		int x=p[o].x,y=p[o].y;
		for ( int i=0; i<=k; i++) {
			int j=k-i;
			ck(x+i,y+j,o),ck(x-i,y+j,o),ck(x+i,y-j,o),ck(x-i,y-j,o);
		}	
	}
	cout<<-1;
}

