#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
inline void Freopen(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}
int n,m,k;
char s[MAXN];
int main(){
	Freopen();
 	int T; scanf("%d",&T);
 	while(T--){
 		int n,m,k; scanf("%d%d%d",&n,&m,&k);
 		scanf("%s",s+1); 
 		for(int i=1;i<=m;i++){
 			int u,v; 
			scanf("%d%d",&u,&v);
 		}
 		int num=m-(n-1);
 		num=(num+1)%k; if(num==0) num=k; 
 		if(s[num]=='P') puts("G");
 		else puts("P");
 	}
	return 0;
}

