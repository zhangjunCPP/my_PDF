#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=2e5+10;
using namespace std;

ll n,k;
ll a[N],b[N];
ll m,num[N*2];
vector<ll>dp[N];



void mian(){
	
	scanf("%lld",&n);
	For(i,1,n){
		scanf("%lld",&a[i]);
		b[i]=a[i]+a[i-1];
	}
	
	For(i,1,n)num[++m]=a[i],num[++m]=b[i];
	sort(num+1,num+m+1);
	m=unique(num+1,num+m+1)-num-1;
	For(i,1,n){
		a[i]=lower_bound(num+1,num+m+1,a[i])-num;
		b[i]=lower_bound(num+1,num+m+1,b[i])-num;
	}
	
	For(i,1,n+1){
		dp[i].resize(m+1);
		For(j,1,m)dp[i][j]=1e18;
	}
	dp[1][a[1]]=dp[2][b[2]]=0;
	For(i,1,n-1){
		For(j,1,m){
			if(dp[i][j]==1e18)continue;
			
			ll mn=min(num[j]-dp[i][j],num[a[i+1]]);
			ll mx=num[j],pos=j;
			if(num[a[i+1]]>mx)mx=num[a[i+1]],pos=a[i+1];
			dp[i+1][pos]=min(dp[i+1][pos],mx-mn);
			
			mn=min(num[j]-dp[i][j],num[b[i+2]]);
			mx=num[j],pos=j;
			if(num[b[i+2]]>mx)mx=num[b[i+2]],pos=b[i+2];
			dp[i+2][pos]=min(dp[i+2][pos],mx-mn);
		}
	}
	ll ans=1e18;
	For(i,1,m)ans=min(ans,dp[n][i]);
	printf("%lld",ans);
	
}

int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	int T=1;
	while(T--)mian();
	return 0;
}
