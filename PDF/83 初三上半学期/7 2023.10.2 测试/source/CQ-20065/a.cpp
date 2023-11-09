#include<bits/stdc++.h>
#define int long long
#define y1 sbs
#define y2 sbsb

const int N=1e6+10,M=1e5+10,inf=1e9;
void Freopen();
using namespace std;
int n,m,q;
int ans[2000][2000];
void solve1();
int fx[8]={1,1,0,-1,-1,-1,0,1};
int fy[8]={0,1,1,1,0,-1,-1,-1};
struct node {
	int x1,y1,x2,y2;	
} p[N];
signed main() {
	Freopen();
	cin>>n>>m>>q;
	return solve1(),0;
	
}
void solve1() {
	for ( int i=1; i<=n; i++) {
		cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
		for ( int l=p[i].x1; l<=p[i].x2; l++)
			for ( int r=p[i].y1; r<=p[i].y2; r++)
				ans[l][r]++;
	}
	for ( int i=1; i<=m; i++) {
		int op,id,d;
		cin>>op>>id>>d;
		int dx=fx[op],dy=fy[op];
		int x1=p[id].x1,y1=p[id].y1,x2=p[id].x2,y2=p[id].y2;
		cout<<p[1].x1<<" "<<p[1].y1<<" "<<p[1].x2<<" "<<p[1].y2<<endl;
		p[id]={x1+d*dx,y1+d*dy,x2+d*dx,y2+d*dy};
		for ( int j=1; j<=d; j++) {
			int x=j*dx,y=j*dy;
			for ( int l=x1+x; l<=x2+x; l++)
				for ( int r=y1+y; r<=y2+y; r++)
					ans[l][r]++;
		}
	}
	while (q--) {
		int x,y;
		cin>>x>>y;
		cout<<ans[x][y]<<endl;
	}
}
void Freopen() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
}
