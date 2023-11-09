#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e6+6;
int n,m;
int bit[51];
int k[52];
int ans=1e7;
int vis[53];
void dfs(int x,int sum){
	if(x==n+1){
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<(1<<m);i++){
		if(i<bit[x])continue;
		int f=1;
		for(int j=0;j<m;j++)if(vis[j]&&(i>>j)&1){
			f=0;
			break;
		}if(!f)continue;
		for(int j=0;j<m;j++)if((i>>j)&1){
			vis[j]=1;
		}dfs(x+1,sum|i);
		for(int j=0;j<m;j++)if((i>>j)&1){
			vis[j]=0;
		}
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++){
		k[i]=rd();for(int j=1;j<=k[i];j++)bit[i]|=(1<<(rd()-1));
	}
	if(n>10){
		puts("-1");
		return 0;
	}
	dfs(1,0);
	if(ans==1e7){
		puts("-1");
		return 0;
	}
	for(int i=m-1;~i;i--)cout<<((ans>>i)&1); 
	return 0;
}

