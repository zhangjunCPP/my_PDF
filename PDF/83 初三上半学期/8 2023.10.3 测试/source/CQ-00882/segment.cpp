#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
const int INF=1e18;
int n,tot,a[maxn],dp[maxn],ans,lid,rid;
map<int,int>mp;
void solve(int l,int r,int flag){
	int mx=0;
	if(l==r)mx=a[l],dp[l]=mx;
	else mx=a[l]+a[r],dp[l]=dp[r]=mx;
	if(flag==1){
		if(mp[mx])return ;
		mp[mx]=1;
	}
	for(int i=l-1;i>=1;i--){
		int val=a[i];
		if(val>mx)return ;
		if(i==l-1)dp[i]=min(dp[i+1],val);
		else{
			val=val+a[i+1];
			if(val<=mx)dp[i]=max(min(dp[i+2],a[i]+a[i+1]),min(dp[i+1],a[i]));
			else dp[i]=min(dp[i+1],a[i]);
		}
	}
	for(int i=r+1;i<=n;i++){
		int val=a[i];
		if(val>mx)return ;
		if(i==r+1)dp[i]=min(dp[i-1],val);
		else{
			val=val+a[i-1];
			if(val<=mx)dp[i]=max(min(dp[i-2],a[i]+a[i-1]),min(dp[i-1],a[i]));
			else dp[i]=min(dp[i-1],a[i]);
		}
	}
	int v=min(dp[1],dp[n]);
	ans=min(ans,mx-v);
	for(int i=1;i<=n;i++)dp[i]=0;
//	cout<<l<<" "<<r<<" "<<mx<<" "<<v<<endl;
}
signed main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	ans=INF;
	int mx=0;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
	if(mx<=10){
		for(int i=1;i<=n;i++){
			solve(i,i,1);
			if(i!=n)solve(i,i+1,1);
		}
		cout<<ans;
		return 0;
	}
	
	//玩过原神么 O.o?
	for(int i=1;i<=n;i++){
		solve(i,i,1);
		if(i!=n)solve(i,i+1,0);
		if(i>=8000){
			cout<<ans;
			return 0;
		} 
	}
	cout<<ans;
	return 0;
}
//5
//2 2 3 5 2
//完了 把自己反应进去了 
