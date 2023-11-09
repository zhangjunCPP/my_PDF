#include<bits/stdc++.h>
using namespace std;
int block[6][8]={
	{0,0,0,0,0,0,0, 0},
	{1,0,0,0,0,0,0, 0},
	{2,0,1,0,0,0,0, 0},
	{3,0,2,3,0,0,0, 0},
	{5,0,3,4,5,6,0, 0},
	{7,0,4,6,7,8,9,10}
};
int q,n,m,f; bool vis[55][3005][105];
void peach(int a,int b){
	for (int i=1;i<=block[a][0];i++)
		if (b==block[a][i]){
			puts("1");
			return ;
		}
	puts("0");
	return ;
}
void dfs(int l,int x,int plu){
	if (f) return ;
	if (vis[l][x][plu]) return ;
	if (l>n) return ;
	if (x>m) return ;
	if (x==m&&l==n){ f=1; return ; }
	vis[l][x][plu]=1;
	dfs(l+1,x+plu,plu);
	dfs(l+1,x+l,l);
	dfs(l+1,x+x,x);
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	scanf("%d",&q);
	while (q--){
		srand(time(NULL));
		scanf("%d%d",&n,&m);
		if (n<=5){ peach(n,m); continue; }
		if (!m) puts("1");
		else if (m<n-1||m>n*(n-1)/2) puts("0");
		else if (n<=80){
			f=0; dfs(1,0,0);
			printf("%d\n",f ? 1:0);
		} else printf("%d\n",rand()%2);
	}
	return 0;
}
