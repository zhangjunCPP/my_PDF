#include<bits/stdc++.h>
#define int long long
#define N 10005
using namespace std;
int T,n,mod,p[N],vis[N],s1[N],t1,s2[N],t2,b[N],top,ans;
void dfs(int x){
	if(x==n+1){
		if(rand()&1)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
void solve(){
	scanf("%lld%lld",&n,&mod);
	ans=t1=t2=top=0;
	dfs(1);
	printf("%lld\n",ans);
}
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
/*
3
4 998244353
5 998244353
12 998244353
*/
