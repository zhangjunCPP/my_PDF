#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;} 
/*None*/
const int N=2e5+5;
using ll=long long;
int n,q,a[N];
const ll mod=998244353;
ll cnt[N];
ll ksm(ll a,ll b){
	ll r=1;while(b){
		if(b&1)r=r*a%mod;
		a=a*a%mod;b>>=1;
	}return r;
}
void Freopen(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
}
void md(int&x){x>=mod?x-=mod:x;}
int to[505][505];
int main(){
	Freopen();
	n=rd(),q=rd();int v=0;
	for(int i=1;i<=n;i++){
		a[i]=rd(),v=max(v,a[i]);
	}
	for(int i=1;i<=500;i++)for(int j=1;j<=500;j++)to[i][j]=__gcd(i,j);
	while(q--){
		int l=rd(),r=rd();
		for(int i=1;i<=v;i++)cnt[i]=0;
		cnt[a[l]]=1;
		for(int i=l+1;i<=r;i++){
			for(int j=1;j<=v;j++)if(cnt[j]){
				int x=to[a[i]][j];
				cnt[x]+=cnt[j];
				if(cnt[x]>=mod)cnt[x]-=mod;
			}
			cnt[a[i]]++;
		}ll ans=1;
		for(int i=1;i<=v;i++)ans=ans*ksm(i,cnt[i])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
