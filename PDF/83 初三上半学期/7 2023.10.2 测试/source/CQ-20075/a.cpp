#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=2.5e5+5;
int n,m,q;
struct qr{
	int x,y;
	int kx,ky;
}p[N];
struct mv{
	int x,y,kx,ky;
	int fl,d;
}t[N];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=rd(),m=rd(),q=rd();
	for(int i=1;i<=n;i++){
		p[i].x=rd(),p[i].y=rd();
		p[i].kx=rd()-p[i].x,p[i].ky=rd()-p[i].y;
	}
	for(int i=1;i<=m;i++){
		int v=rd(),r=rd(),d=rd();
		t[i]={p[r].x,p[r].y,p[r].kx,p[r].ky,v,d-1};
		p[r].x+=dx[v]*d,p[r].y+=dy[v]*d;
	}while(q--){
		int x=rd(),y=rd();
		int cnt=0;
		for(int i=1;i<=n;i++)
		if(p[i].x<=x&&p[i].y<=y&&p[i].x+p[i].kx>=x&&p[i].y+p[i].ky>=y)cnt++;
		for(int i=1;i<=m;i++){
			for(int j=0;j<=t[i].d;j++){
				int xx=t[i].x+j*dx[t[i].fl],yy=t[i].y+j*dy[t[i].fl];
				if(xx<=x&&xx+t[i].kx>=x&&yy<=y&&yy+t[i].kx>=y)cnt++;
			}
		}cout<<cnt<<endl;
	}
	return 0;
}
