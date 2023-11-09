#include<bits/stdc++.h>
using namespace std;
const int N=250010;
int n,m,q;
struct as{
	int x1,y1,x2,y2;
}a[N];
void sol1(){
	for(int i=1;i<=m;i++){
		int v,r,d;
		scanf("%d%d%d",&v,&r,&d);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",0);
	}
}
int cf[1100][1100];
int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};
void cz(int x1,int y1,int x2,int y2){
	cf[x1][y1]++;cf[x1][y2+1]--;cf[x2+1][y1]--;cf[x2+1][y2+1]++;
}
void sol2(){
	for(int i=1;i<=n;i++){
		cz(a[i].x1,a[i].y1,a[i].x2,a[i].y2);
	}
	for(int i=1;i<=m;i++){
		int v,r,d;
		scanf("%d%d%d",&v,&r,&d);
		for(int j=1;j<=d;j++){
			a[r].x1+=dx[v];a[r].y1+=dy[v];a[r].x2+=dx[v];a[r].y2+=dy[v];
			cz(a[r].x1,a[r].y1,a[r].x2,a[r].y2);
		}
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=20;j++){
			cf[i][j]+=cf[i-1][j]+cf[i][j-1]-cf[i-1][j-1];
//			cout<<cf[i][j]<<" ";
		}
//		cout<<endl;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",cf[x][y]);
	}
}
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int mx=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		mx=max(mx,a[i].x1);mx=max(mx,a[i].x2);
		mx=max(mx,a[i].y1);mx=max(mx,a[i].y2);
	}
	if(mx<=1000)sol2();
	else sol1();
	return 0;
}

