#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=2e3+10;
using namespace std;

ll n=1,m,k,tot;
bitset<N>vis[N];
vector<vector<ll>>ans;



void mian(){
	
	scanf("%lld%lld",&m,&k);
	For(i,1,k)n*=m;
	if(m==2){
		printf("%lld\n",n*(n-1)/2);
		For(i,1,n){
			For(j,i+1,n){
				printf("%lld %lld\n",i-1,j-1);
			}
		}
		return;
	}
	For(i,1,n)vis[i][i]=1;
	For(i,1,n){
		while(1){
			ll cnt=1;
			bitset<N>t,f;
			t[i]=1,f=vis[i];
			For(j,i+1,n){
				if(f[j])continue;
				++cnt;
				t[j]=1;
				f|=vis[j];
				if(cnt==m)break;
			}
			if(cnt<m)break;
			ans.pb({});
			bitset<N>tmp;
			For(j,1,n){
				if(t[j]){
					ans[tot].pb(j);
					tmp[j]=1;
				}
			}
			++tot;
			For(j,1,n)if(t[j])vis[j]|=tmp;
		}
	}
	printf("%lld\n",tot);
	For(i,0,tot-1){
		for(ll x:ans[i])printf("%lld ",x-1);
		printf("\n");
	}
	
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=1;
	while(T--)mian();
	return 0;
}
