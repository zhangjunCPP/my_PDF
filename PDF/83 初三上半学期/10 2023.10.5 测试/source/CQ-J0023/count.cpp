#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10000+5;
ll n;
int vis[N*N];

void solve(){
	memset(vis,0,sizeof(vis));
	ll ans=0,ans1=0,ans2=0;
	ll tad;
	ll maxx=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			tad=i*j;
			ans2++;
			ans1+=vis[tad];
			vis[tad]++;
		}
	}
	cout<<ans1*2+ans2<<endl;
}

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		if(n<=10000){
			solve();
		}
	}
	return 0;
} 


