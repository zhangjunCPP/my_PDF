#include<bits/stdc++.h>
using namespace std;
int t,k,x,y,n,c[256],vis[256];
long long ans;
const int mod=65535;
void dfs(int pos,int sum){
	if(pos==n+1){
		ans=ans*sum%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(pos+1,(sum*256+c[i])%mod);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		ans=1,n=0;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d%d",&x,&y);
			for(int j=1;j<=y;j++) c[++n]=x;
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
