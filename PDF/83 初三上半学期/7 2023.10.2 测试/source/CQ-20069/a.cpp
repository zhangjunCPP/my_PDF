#include<bits/stdc++.h>
using namespace std;
int n,m,q,x[104],y[104],xx[104],yy[104];
int cnt[104][104];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%d%d%d%d",&x[i],&y[i],&xx[i],&yy[i]);
	for(int i=1;i<=m;++i){
		int v,r,d;scanf("%d%d%d",&v,&r,&d);
		for(int j=0;j<=d-1;++j){
			for(int X=x[r]+j*dx[v];X<=xx[r]+j*dx[v];++X)
				for(int Y=y[r]+j*dy[v];Y<=yy[r]+j*dy[v];++Y)
					cnt[X][Y]++;
		}
		x[r]=x[r]+d*dx[v];
		xx[r]=xx[r]+d*dx[v];
		y[r]=y[r]+d*dy[v];
		yy[r]=yy[r]+d*dy[v];
	}
	for(int i=1;i<=n;++i){
		for(int X=x[i];X<=xx[i];++X)
			for(int Y=y[i];Y<=yy[i];++Y)
				cnt[X][Y]++;		
	}
	for(;q--;){
		int px,py;scanf("%d%d",&px,&py);
		printf("%d\n",cnt[px][py]);
	}
	return 0;
}
