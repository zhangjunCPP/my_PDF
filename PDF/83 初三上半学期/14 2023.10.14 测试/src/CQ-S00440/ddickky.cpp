#include<bits/stdc++.h>
#define N 1005
#define int long long
#define mod 998244353
using namespace std;
int n,q,a[N],b[N],l,r,ans,vis[N][N];
int pw(int x,int cnt){
	int res=1;
	while(cnt){
		if(cnt&1)res=res*x%mod;
		x=x*x%mod;
		cnt>>=1;
	}
	return res;
}
int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y);
}
void dfs(int x,int w){
	if(x==r+1){
		if(w>1)ans=ans*w%mod;
		return ;
	}
	if(w==1)return ;
	dfs(x+1,(w==-1)?a[x]:gcd(w,a[x]));
	dfs(x+1,w);
}
signed main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	b[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=b[i-1]*a[i]%mod;
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&l,&r);
		if(vis[l][r]){
			printf("%lld\n",vis[l][r]);
			continue;
		}
		ans=1;
		dfs(l,-1);
		vis[l][r]=ans;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 1
2 4 3
1 3
*/

/*
5 2
8 2 8 8 9
1 5
2 4
*/
