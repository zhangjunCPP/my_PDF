#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n;
ll a[N];
namespace sol1{
	ll oa[N];
	bool ins[N];
	vector<ll> box;
	bool check(ll flr,ll lim){
		for(ll i=1;i<=n;i++){
			if(ins[i]) continue;
			bool pl=(i>1&&(!ins[i-1])&&a[i]+a[i-1]>=flr&&a[i]+a[i-1]<=lim);
			bool pr=(i<n&&(!ins[i+1])&&a[i]+a[i+1]>=flr&&a[i]+a[i+1]<=lim);
			if(a[i]<flr){
				ll p;
				if(pl&&pr) continue;
				else if(pl) p=i-1;
				else if(pr) p=i+1;
				else return false;
				ll s=a[i]+a[p];
				a[i]=a[p]=s;
				ins[i]=ins[p]=true;
			}
		}
		return true;
	}
	void solve(){
		ll mxp=-1;
		for(ll i=1;i<=n;i++)
			mxp=max(mxp,a[i]);
		box.push_back(mxp);
		for(ll i=2;i<=n;i++)
			if(a[i]+a[i-1]>mxp) box.push_back(a[i]+a[i-1]);
		sort(box.begin(),box.end());
		box.resize(unique(box.begin(),box.end())-box.begin());
		for(ll i=1;i<=n;i++)
			oa[i]=a[i];
		ll ans=2e9;
		for(ll u:box){
//			cout<<u.w<<' '<<u.i<<' '<<u.j<<" :\n";
			ll l=0,r=u,res=2e9;
			while(l<=r){
				ll mid=(l+r)>>1ll;
				for(ll i=1;i<=n;i++)
					ins[i]=false,a[i]=oa[i];
				if(check(u-mid,u)) res=mid,r=mid-1;
				else l=mid+1;
			}
//			cout<<res<<'\n';
			ans=min(ans,res);
		}
		cout<<ans;
		return ;
	}
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=1;i<=n;i++) 
		cin>>a[i];
	sol1::solve();
	return 0;
}
/*
5
2 2 3 5 2

3
2 2 4

5
9 9 9 10 4
*/
