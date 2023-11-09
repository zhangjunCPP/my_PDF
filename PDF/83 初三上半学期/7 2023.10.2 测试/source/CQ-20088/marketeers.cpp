#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10,MAXM=1e3+10;
const int mod=998244353;
int n;
int k[MAXN],s[MAXM][MAXM];
bool vis[MAXM][MAXM];
int res[MAXN],len,ans[MAXN],tot,maxn=0;
inline void work(){
	int cnt=0; int B[25];
	for(int i=1;i<=len;i++){
		for(int j=i+1;j<=len;j++)
			if(res[j]<res[i]) cnt++;
		B[i]=cnt;
	}
	ans[++tot]=cnt; maxn=max(maxn,cnt);
}
void dfs(int dep){
	if(dep==n+1){
		work();
		return ;
	}
	for(int j=1;j<=k[dep];j++){
		if(vis[dep][j]) continue;
		vis[dep][j]=true;
		res[++len]=s[dep][j]; 
		dfs(dep+1);
		vis[dep][j]=false;
		len--;
	}
}
int main(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d",&s[i][j]);
	}
	dfs(1);
	int Ans=0;
 	for(int i=1;i<=tot;i++) if(ans[i]==maxn) Ans++,Ans%=mod;
 	printf("%d",Ans%mod);
	return 0;
}
/*
4
5
7 11 3 10 1 3
8 6 4 1
15
3
1 5 9
9

4
2
2 1 
3
5 1 6 
1
3
3
6 5 7
*/
