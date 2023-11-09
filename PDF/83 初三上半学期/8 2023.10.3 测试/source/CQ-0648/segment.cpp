#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=2e9+1;
int n,a[N],dp[N][2],ans=INF,now;
void up(int x,int y,int &dp,int a){
	if(x==-1){
		if(y==-1) dp=-1;
		else dp=min(y,a);
	}else{
		if(y==-1) dp=min(x,a);
		else dp=min(max(x,y),a);
	}
}
bool check(int lim){
	dp[1][0]=a[1],dp[1][1]=-1;
	dp[2][0]=min(a[1],a[2]);
	if(a[1]+a[2]<=lim) dp[2][1]=a[1]+a[2];
	else dp[2][1]=-1;
	for(int i=3;i<=n;++i){
		up(dp[i-1][0],dp[i-1][1],dp[i][0],a[i]);
		if(a[i]+a[i-1]<=lim) up(dp[i-2][0],dp[i-2][1],dp[i][1],a[i]+a[i-1]);
		else dp[i][1]=-1;
	}
	int t; up(dp[n][0],dp[n][1],t,INF);
	if(t==-1) return false;
	now=lim-t;
	return now<=ans;
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%d",&n);
	int l=0,r=INF,mid;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),l=max(l,a[i]);
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) ans=now,r=mid;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
