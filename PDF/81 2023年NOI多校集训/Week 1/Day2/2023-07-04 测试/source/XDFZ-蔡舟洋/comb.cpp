#include<bits/stdc++.h>
int pmax(int a,int b){return a>b?a:b;}
using namespace std;
int n;
int a[3002],dp[3002],tmu[3002][3002];
int to[3002][3002],cnt[3002];
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i-1;j++)if(a[j]==a[i])to[i][++cnt[i]]=j;
		for(int j=1;j<=n;j++)tmu[i][j]=lower_bound(to[i]+1,to[i]+cnt[i]+1,j)-to[i];
	}
	int ans=0;
	for(int i=4;i<=n;i++){
		for(int j=0;j<=i-4;j++){
			int f=0;
			for(int K=1;K<=cnt[i];K++){
				int k=to[i][K];
				for(int q=k+1;q<i;q++){
					if(cnt[q]==0)continue;
					int tmp=tmu[q][j+1];
					if(to[q][tmp]>j&&to[q][tmp]<k){
						f=1; 
						dp[i]=max(dp[i],dp[j]+4);
						break;
					}
				}
				if(f)break;
			}
		}
		ans=max(ans,dp[i]); 
	}
	printf("%d",ans);
	return 0;; 
}

