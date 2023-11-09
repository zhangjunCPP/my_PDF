#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=250010;
int n,m,q,x1[N],x2[N],yy1[N],y2[N],v[N],r[N],d[N],sum[110][110];
int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};
bool check(int x,int y,int x2,int y2,int x3,int y3,int x4,int y4,int cx,int cy){
	int x5=x3-x+x2,y5=y3-y+y2,x6=x4-x+x2,y6=y4-y+y2;
	if(cx<min(x,x2)||cx>max(x,x2)||cy<min(y,y2)||cy>max(y,y2))return false;
	if(cy<min(y3-cx+x3,y4-cx+x3)||cy>max(y3-cx+x3,y4-cx+x3))return false;
	return true;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;++i){
		x1[i]=read(),yy1[i]=read(),x2[i]=read(),y2[i]=read();
		for(int x=x2[i];x<=x1[i];++x)
			for(int y=yy1[i];y<=y2[i];++y)++sum[x][y];
	}
	if(n<=100&&m<=100&&q<=100){
		for(int i=1;i<=m;++i){
			int v=read(),r=read(),d=read(),nx1,ny1,nx2,ny2;
			for(int j=1;j<=d;++j){
				nx1=x1[r]+j*dx[v],nx2=x2[r]+j*dx[v],ny1=yy1[r]+j*dy[v],ny2=y2[r]+j*dy[v];
				for(int x=nx2;x<=nx1;++x)
					for(int y=ny1;y<=ny2;++y)++sum[x][y];
			}
			x1[r]+=d*dx[v],x2[r]+=d*dx[v],yy1[r]+=d*dy[v],y2[r]+=d*dy[v];
		}
		while(q--){
			int px=read(),py=read();
			printf("%d\n",sum[px][py]);
		}
	}else if(n<=1000&&m<=1000&&q<=1000){
		for(int i=1;i<=m;++i)v[i]=read(),r[i]=read(),d[i]=read();
		while(q--){
			int px=read(),py=read();
			for(int i=1;i<=m;++i){
				if(check(x1[r[i]],yy1[r[i]],x2[r[i]]+d[i]*dx[v[i]],y2[r[i]]+d[i]*dy[v[i]],x2[r[i]],yy1[r[i]],x1[r[i]],y2[r[i]],px,py)){
					
				}
				x1[r[i]]+=d[i]*dx[v[i]],x2[r[i]]+=d[i]*dx[v[i]],yy1[r[i]]+=d[i]*dy[v[i]],y2[r[i]]+=d[i]*dy[v[i]];
			}
		}
	}else if(m==0){
		
	}
	return 0;
}
/*
1 8 3
2 1 2 1
0 1 1
1 1 1
2 1 1
3 1 1
4 1 1
5 1 1
6 1 1
7 1 1
1 1
2 1
4 2
*/
