#include<stdio.h>

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
const int N=250005,dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1},Z=1000;
int n,m,q,ma[2005][2005];
struct dy{
	int x1,x2,y1,y2;
}a[N];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		for(int x=a[i].x1;x<=a[i].x2;x++) for(int y=a[i].y1;y<=a[i].y2;y++) ma[x+Z][y+Z]++;
	}
	while(m--)
	{
		int v,id,d;scanf("%d%d%d",&v,&id,&d);
		for(int c=1;c<=d;c++)
			for(int i=min(a[id].x1+c*dx[v],a[id].x2+c*dx[v]);i<=max(a[id].x1+c*dx[v],a[id].x2+c*dx[v]);i++)
				for(int j=min(a[id].y1+c*dy[v],a[id].y2+c*dy[v]);j<=max(a[id].y1+c*dy[v],a[id].y2+c*dy[v]);j++)
					ma[i+Z][j+Z]++;
		a[id].x1+=d*dx[v];a[id].y1+=d*dy[v];
		a[id].x2+=d*dx[v];a[id].y2+=d*dy[v];
	}
	while(q--)
	{
		int x,y;scanf("%d%d",&x,&y);
		printf("%d\n",ma[x+Z][y+Z]);
	}
	return 0;
}
