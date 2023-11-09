#include<bits/stdc++.h>
#define ll long long
#define m_p make_pair
using namespace std;
const int N=200000+10,mod=998244353;
int n,q;
ll a[N];
ll ans=0;
ll f[1009][1009];
int l,r;
void dfs(int x,ll sum){
	if(x>r){
		if(sum!=0)ans=(ans*sum)%mod;
		return;
	}
	if(sum==0){
		dfs(x+1,a[x]);
	}
	else dfs(x+1,__gcd(sum,a[x]));
	dfs(x+1,sum);
}

int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	if(n>1000) return 0;
	memset(f,-1,sizeof(f));
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		ans=1;
		if(f[l][r]!=-1) ans=f[l][r];
		else dfs(l,0);
		f[l][r]=ans;
		printf("%lld\n",ans);
	}
	return 0;
}

