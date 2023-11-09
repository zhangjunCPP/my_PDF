#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll M=1e9+7;
const int N=13;
//const int M=117;
const int K=1000;
int t[N],x[117],y[117],same[117],diff[117];
ll jc[K+17],ny[K+17],ans;
int n,lim,k,m,tt;
ll vis[K+17];
ll ppow(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b&1){
			ans*=a;
			ans%=M;
		}
		a*=a;
		a%=M;
		b>>=1;
	}
	return ans;
}
ll c(ll n,ll m){
	if(n<0||m<0||n-m<0)return 0;
	return jc[n]*ny[m]%M*ny[n-m]%M;
}
void dfs(int pos){
	if(pos==n+1){
		ll xs=1;
//		for(int i=1;i<=lim;i++){
//			xs+=vis[i];
//		}
//		xs=c(k,xs);
		for(int i=1;i<=m;i++){
			if(t[x[i]]==t[y[i]])xs*=same[i];
			else xs*=diff[i];
			if(xs==0)return;
			xs%=M;
		}
		ans+=xs;
		ans%=M;
		return;
	}
	for(int i=1;i<=lim;i++){
		t[pos]=i;
		dfs(pos+1);
	}
}
signed main(){
//	freopen("D:\\down\\trans\\ex_trans2.in","r",stdin);
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	scanf("%d",&tt);
	jc[0]=ny[0]=1;
	for(int i=1;i<=K;i++){
		jc[i]=jc[i-1]*i%M;
	}
	ny[K]=ppow(jc[K],M-2);
	for(int i=K-1;i>=1;i--){
		ny[i]=ny[i+1]*(i+1)%M;
	}
	while(tt--){
		ans=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&x[i],&y[i],&diff[i],&same[i]);
		}
		lim=k;
//		lim=min(n,k);
		dfs(1);
		printf("%lld\n",ans);
	}
}
/*
1
2 4 3
2 1 1 1
2 1 2 2
2 1 2 0
1 2 1 1

*/
