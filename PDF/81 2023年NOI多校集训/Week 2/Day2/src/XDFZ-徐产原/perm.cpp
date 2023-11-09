#include<bits/stdc++.h>
using namespace std;
int n,p,ans,out;
int fac[10000005],dp[10000005],eq[10000005],inv[10000005],pinv[10000005];
int vis[15],c[15],q[15];
void dfs(int i){
	if(i==n+1){
		int flag=0;
		for(int j=1;j<=n;j++)q[c[j]]=j;
		for(int j=1;j<=n;j++)
			if(c[j]==q[j])continue;
			else if(c[j]>q[j])return;
			else{flag=1;break;}
		if(flag){++ans;}
		return;
	}
	for(int j=1;j<=n;j++)if(!vis[j]){
		vis[j]=1;
		c[i]=j;
		dfs(i+1);
		vis[j]=0;
	}
}
void Freopen(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&p);
	++n;
	while(--n){
		ans=0;
		dfs(1);
		out^=ans;
	}
	cout<<out;
}
/*
printf("%d\n",i);
for(int j=0;j<=i-2;j++){
	v=(v+1ll*(i-1-j)*(i-2-j)/2%p*fac[i-j-2]%p)%p;
	printf("%d %d %d\n",(i-1-j),(i-2-j),fac[i-j-2]);
}
*/