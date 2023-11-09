#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1000+10;
using namespace std;

ll n;
ll l[N],r[N],c[N];
ll dp[N][33000],f[N][33000],g[N][33000];

ll calc(ll l,ll r,ll x){
	ll cnt=0;
	For(i,l,r)if((x>>i)&1)++cnt;
	return cnt;
}

void print(ll x){
	Rep(i,14,0)printf("%lld",x>>i&1);
}

void mian(){
	
	scanf("%lld",&n);
	For(i,1,n){
		scanf("%lld%lld%lld",&l[i],&r[i],&c[i]);
	}
	For(i,1,n){
		For(s,0,32767){
			ll flag=!((s>>7)&1);
			For(j,-7,7){
				if(((s>>7-j)&1)&&(i+j<1||i+j>n)){
					flag=0;
					break;
				}
			}
			if(!flag)continue;
			ll t=s>>1&32639,opt=(s>>8)&1;
			if(opt==0)dp[i][s]=g[i-1][t|64]+calc(7+i-r[i],7+i-l[i],s)*c[i];
			if(opt==1)dp[i][s]=f[i-1][t&29|32703]+calc(7+i-r[i],7+i-l[i],s)*c[i];
//			print(s);
//			cout<<" "<<dp[i][s]<<"|";
		}
		For(s,0,32767)f[i][s]=g[i][s]=dp[i][s];
		For(s,0,32767){
			For(j,0,14){
				if((s>>j)&1){
					ll t=s^(1<<j);
					f[i][s]=max(f[i][s],f[i][t]);
				}
			}
		}
		Rep(s,32767,0){
			For(j,0,14){
				if((s>>j)&1){
					ll t=s^(1<<j);
					g[i][t]=max(g[i][t],g[i][s]);
				}
			}
		}
//		cout<<endl;
	}
	ll ans=0;
	For(i,0,32767)ans=max(ans,dp[n][i]);
	printf("%lld",ans);
	
}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int T=1;
	while(T--)mian();
	return 0;
}
