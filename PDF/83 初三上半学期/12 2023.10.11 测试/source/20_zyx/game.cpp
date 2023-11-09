#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,u,v;
char s[100001];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%s",&n,&m,&k,s);
		for(int i=1;i<=m;i++) scanf("%d%d",&u,&v);
		if(s[(m-n+1)%k]=='P') printf("G\n");
		else printf("P\n");
	}
	return 0;
}
