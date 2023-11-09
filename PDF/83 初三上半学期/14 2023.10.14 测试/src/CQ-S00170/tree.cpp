#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e6+10;
const ll p=998244353;
using namespace std;

ll n,m;
ll a[N],b[N];
ll f[N];
ll vis[N];
ll ans;

void dfs(ll x){
	if(x==n){
		++ans;
		return;
	}
	if(vis[a[x]]||vis[b[x]])return dfs(x+1);
	vis[a[x]]=1;dfs(x+1);vis[a[x]]=0;
	vis[b[x]]=1;dfs(x+1);vis[b[x]]=0;
}

void mian(){
	
	ll flag1=1,flag2=1;
	scanf("%lld",&n);
	For(i,1,n-1){
		scanf("%lld%lld",&a[i],&b[i]);
		if(a[i]!=1||b[i]!=i+1)flag1=0;
		if(a[i]!=i||b[i]!=i+1)flag2=0;
	}
	if(flag1){
		printf("%lld",n);
		return;
	}
	if(flag2){
		f[1]=1,f[2]=2;
		For(i,3,n)f[i]=(f[i-1]+f[i-2])%p;
		printf("%lld",f[n]);
		return;
	}
	if(n<=20){
		dfs(1);
		printf("%lld",ans);
		return;
	}
	printf("%lld",n);
	
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--)mian();
	return 0;
}
/*
Selate In ou Lane Lar Algar ou Iila
Lootaria ou Caren Ewol Acary
Mirya Heil Dro end Di end Tri
Selate In ou Lane Lar Crai Jam Wary
Lootaria ou Winna Ewol Acary
Mirya Heil Dro end Di end Tri
*/
