#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],n; 
int book[maxn<<1],tot;
int dp[maxn][3]; 
const int INF=2e9;
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		book[++tot]=a[i];
	}
	if(n==1){
		printf("%d",a[1]);
		return 0;
	}
	if(n==2){
		printf("%d",abs(a[1]-a[2]));
		return 0;
	}
	for(int i=1;i<n;i++) book[++tot]=a[i]+a[i+1];
	sort(book+1,book+tot+1);
	tot=unique(book+1,book+tot+1)-(book+1);
	int ans=INF;
	for(int i=1;i<=tot;i++){
		int val=book[i];
//		cout<<val<<endl; 
		dp[1][0]=INF;
		if(a[1]>=val) dp[1][1]=max(a[1],a[2]);
		else dp[1][1]=INF;
		if(a[1]+a[2]>=val) dp[1][2]=a[1]+a[2];
		else dp[1][2]=INF;
		for(int j=3;j<=n;j+=2){
			dp[j][0]=dp[j][1]=dp[j][2]=INF;
			if(a[j-1]+a[j]>=val) dp[j][0]=max({a[j-1]+a[j],a[j+1],min(dp[j-2][1],dp[j-2][0])});
			if(a[j]>=val) dp[j][1]=max({a[j],a[j+1],dp[j-2][2]});
			if(a[j-1]>=val && a[j]>=val) dp[j][1]=min(dp[j][1],max({a[j-1],a[j],a[j+1],min(dp[j-2][1],dp[j-2][0])}));
			if(j<n && a[j]+a[j+1]>=val) dp[j][2]=max(a[j]+a[j+1],dp[j-2][2]); 
			if(j<n && a[j]+a[j+1]>=val && a[j-1]>=val) dp[j][2]=min(dp[j][2],max({a[j]+a[j+1],a[j-1],min(dp[j-2][1],dp[j-2][0])}));
//			cout<<dp[j][0]<<" "<<dp[j][1]<<" "<<dp[j][2]<<endl;
		}
//		cout<<dp[1][0]<<" "<<dp[1][1]<<" "<<dp[1][2]<<" "<<dp[3][0]<<" "<<dp[3][1]<<" "<<dp[3][2]<<endl;
		int p=INF; 
		if(n%2==1 || a[n]>=val){
			p=min({dp[n%2?n:n-1][0],dp[n%2?n:n-1][1],dp[n%2?n:n-1][2]});
		}
		else{
			p=dp[n-1][2];
		}
//		cout<<val<<" "<<p<<endl; 
		ans=min(ans,p-val);
		if(p==INF) break;
	}
	printf("%d",ans);
	return 0;
}
/*
不用dp感觉有了。
还是n^2，唯一进步了就是没用dp。 
先打暴力再说吧。。。 
方法假了，乐。
还是只有dp,这种题目真的恶心。 

18
4 4 11 17 4 17 2 12 9 13 15 1 5 3 4 3 6 16

5
10000 1 2 1 2
*/
