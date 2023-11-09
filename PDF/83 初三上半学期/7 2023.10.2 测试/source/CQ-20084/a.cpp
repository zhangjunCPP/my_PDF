#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,q;
const int maxn=250005;
int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
struct node{
	int x,y,x2,y2;
	int op;
}a[maxn];
struct Cl{
	int v,r,d;
}c[maxn];
struct Mg{
	int x,y,ans;
}qq[maxn];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].x2,&a[i].y2);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&c[i].v,&c[i].r,&c[i].d);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qq[i].x,&qq[i].y);
		qq[i].ans=0;
	}
	for(int i=1;i<=m;i++){
		int j=c[i].r;
		for(int k=1;k<=c[i].d;k++){
			for(int g=1;g<=q;g++){
				if(a[j].x<=qq[g].x && a[j].y<=qq[g].y && a[j].x2>=qq[g].x && a[j].y2>=qq[g].y){
					qq[g].ans++;
				}
			}
			a[j].x+=dx[c[i].v];
			a[j].y+=dy[c[i].v];
			a[j].x2+=dx[c[i].v];
			a[j].y2+=dy[c[i].v];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q;j++){
			if(a[i].x<=qq[j].x && a[i].y<=qq[j].y && a[i].x2>=qq[j].x && a[i].y2>=qq[j].y){
				qq[j].ans++;
			}
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",qq[i].ans);
	}
	return 0;
}
