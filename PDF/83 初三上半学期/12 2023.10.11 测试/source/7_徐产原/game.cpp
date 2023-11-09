#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
char a[100005];
void Freopen(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%s",&n,&m,&k,a+1);
		for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v);
		puts(a[(m-n+1)%k+1]=='G'?"P":"G");
	}
}
