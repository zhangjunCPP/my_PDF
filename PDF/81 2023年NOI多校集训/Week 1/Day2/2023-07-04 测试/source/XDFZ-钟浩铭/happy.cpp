#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,k;
int t[MAXN],num[MAXN],cost[MAXN],One,tt;
long long sum[MAXN][3],spend=INT_MAX;//0买单次票，1买时限票1,2买时限票2 
void solve1(){
	spend=INT_MAX;
	for(int i=1;i<=n;i++){
		if(tt>=t[i]){
			sum[i][0]=sum[i][1]=sum[i][2]=0;
		}
		else{
			int minn=min({sum[i-1][0]+One,sum[i-1][1]+cost[1],sum[i-1][2]+cost[2]});
			if(sum[i-1][1]+cost[1]==minn) tt=t[i]+num[1];
			if(sum[i-1][2]+cost[2]==minn) tt=t[i]+num[2];
			sum[i][0]=minn; sum[i][1]=minn; sum[i][2]=minn;
		}
		for(int j=0;j<3;j++) spend=min(spend,sum[i][j]-sum[i-1][j]);
		printf("%lld\n",spend);
	}
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&num[i],&cost[i]);
	}
	scanf("%d",&One);
	if(k==0){
		printf("%lld",1ll*n*One);
		return 0;
	} 
	if(k<=2){
		solve1();	
	}
	return 0;
} 
