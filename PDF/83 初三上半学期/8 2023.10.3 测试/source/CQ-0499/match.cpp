#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e6+10;
using namespace std;

ll n,m,k;
vector<ll>a[N];
ll vis[N];

bool pd(ll i,ll x){
	ll l=0,r=a[i].size()-1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(a[i][mid]==x)return true;
		if(a[i][mid]>x)r=mid-1;
		else l=mid+1;
	}
	return false;
}

void solve(ll l,ll r,ll x){
	while(!vis[x]&&x)--x;
	if(r<=l||x==0)return;
	vector<vector<ll>>t1,t2;
	For(i,l,r){
		if(pd(i,x))t2.pb(a[i]);
		else t1.pb(a[i]);
	}
	For(i,0,(ll)t1.size()-1)a[l+i]=t1[i];
	For(i,0,(ll)t2.size()-1)a[l+t1.size()+i]=t2[i];
	solve(l,l+t1.size()-1,x-1);
	solve(l+t1.size(),r,x-1);
}

void mian(){
	
	scanf("%lld%lld",&n,&m);
	For(i,1,n){
		scanf("%lld",&k);
		For(j,1,k){
			ll x;
			scanf("%lld",&x);
			vis[x]=1;
			a[i].pb(x);
		}
	}
	solve(1,n,m);
	For(i,1,m)vis[i]=0;
	For(i,1,n){
		Rep(j,(ll)a[i].size()-1,0){
			if(!vis[a[i][j]])vis[a[i][j]]=2;
			else{
				ll pos=a[i][j];
				while(vis[pos]&&pos<=m){
					if(vis[pos]==2)vis[pos]=0;
					++pos;
				}
				if(pos>m){
					printf("-1");
					return;
				}
				vis[pos]=1;
				break;
			}
		}
		Rep(j,(ll)a[i].size()-1,0){
			if(vis[a[i][j]]==2)vis[a[i][j]]=1;
			else break;
		}
	}
	Rep(i,m,1){
		printf("%lld",vis[i]);
	}
	
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=1;
	while(T--)mian();
	return 0;
}
