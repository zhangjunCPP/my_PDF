#include<stdio.h>
#include<algorithm>

#define int long long 
template<typename dy> dy max(dy x,dy y){return x>y?x:y;}
template<typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=1e5+5,inf=1e18;
int n,k,one,num[505],co[505],a[N],dp[N];
int dfs(int p,int r){
	if(p>r) return 0;
	int ans=one+dfs(p+1,r);
	for(int j=1;j<=k;j++)
	{
		int t=std::upper_bound(a+p,a+r+1,a[p]+num[j]-1)-a;
		ans=min(co[j]+dfs(t,r),ans);
	}
	return ans;
}
#undef int
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	#define int long long 
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) {scanf("%lld",&a[i]);}
	for(int i=1;i<=k;i++) scanf("%lld%lld",&num[i],&co[i]);
	scanf("%lld",&one);
	if(k==0) for(int i=1;i<=n;i++) printf("%lld\n",one);
	else for(int i=1;i<=n;i++) {dp[i]=dfs(1,i);printf("%lld\n",dp[i]-dp[i-1]);}
    return 0;
}