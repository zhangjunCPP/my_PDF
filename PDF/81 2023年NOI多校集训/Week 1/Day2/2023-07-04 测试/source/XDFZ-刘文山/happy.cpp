#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
const int maxn=1e5+5;
int T[maxn];
ll dp[maxn],one;
struct node{
	int b;
	ll c;
}a[505],A[505];
int tot;
inline bool cmp(node x,node y){
	if(x.b!=y.b) return x.b>y.b;
	return x.c<y.c;
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout); 
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&T[i]);
	for(int i=1;i<=k;i++) scanf("%d%lld",&a[i].b,&a[i].c);
	sort(a+1,a+k+1,cmp);
	int mi=0x3f3f3f3f;
	for(int i=1;i<=k;i++){
		if(mi>a[i].c){
			mi=a[i].c;
			A[++tot]=a[i];
		}
	}
	scanf("%lld",&one);
	memset(dp,0x3f,sizeof dp);
	dp[0]=0ll;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+one;
		int x=1;
		for(int j=1;j<=tot;j++){
			int y=x;
			x=lower_bound(T+y,T+i+1,T[i]-A[j].b+1)-T;
			dp[i]=min(dp[i],dp[x-1]+A[j].c);
			if(dp[i]==dp[i-1]) break;
		}
		printf("%lld\n",dp[i]-dp[i-1]);
	}
	return 0;
} 
