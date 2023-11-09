#include<bits/stdc++.h>
using namespace std;
struct Node{int x,y,r,c,v,d;};
struct Mat{int x,y,r,c;};
int n,m,q;
int go[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
Mat a[250005];
Node b[250005];
pair<int,int> MAKE(int x,int y){return {min(x,y),max(x,y)};}
int LEN(pair<int,int> x){return max(0,x.second-x.first+1);}
pair<int,int> J(pair<int,int> x,pair<int,int> y){return {max(x.first,y.first),min(x.second,y.second)};}
pair<int,int> GET(int a,int l,int r,int c){
	if(a<l){
		if(c<=0)return {0,-1};
		else return {l-a,r-a};
	}
	else if(l<=a&&a<=r){
		if(c==0)return {-0x3f3f3f3f,0x3f3f3f3f};
		else if(c<0)return {0,a-l};
		else return {0,r-a};
	}
	else{
		if(c>=0)return {0,-1};
		else return {a-r,a-l};
	}
}
void Freopen(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
}
void solve1(){
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].r,&a[i].c);
		a[i].r=a[i].r-a[i].x+1;
		a[i].c=a[i].c-a[i].y+1;
	}
	for(int i=1;i<=m;i++){
		int v,r,d;
		scanf("%d%d%d",&v,&r,&d);
		b[i]={a[r].x,a[r].y,a[r].r,a[r].c,v,d-1};
		a[r].x+=go[v][0]*d;
		a[r].y+=go[v][1]*d;
	}
	while(q--){
		int x,y,ans=0;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++)if(a[i].x<=x&&x<=a[i].x+a[i].r-1&&a[i].y<=y&&y<=a[i].y+a[i].c-1)++ans;
		for(int i=1;i<=m;i++){
			ans+=
			LEN(
			J(
			J(
			GET(b[i].x,x-b[i].r+1,x,go[b[i].v][0]),
			GET(b[i].y,y-b[i].c+1,y,go[b[i].v][1])
			),
			MAKE(0,b[i].d)
			)
			);
		}
		printf("%d\n",ans);
	}
}
int main(){
	Freopen();
	scanf("%d%d%d",&n,&m,&q);
	solve1();
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
