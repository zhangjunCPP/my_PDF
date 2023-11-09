#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e6+10;
using namespace std;

ll n,ans;
ll a[N];

void f(vector<ll>a){
	if(a.size()<=1)return;
	ll mid=a[(a.size()-1)/2];
	vector<ll>t1,t2;
	for(ll x:a){
		++ans;
		if(x<mid)t1.pb(x);
		if(x>mid)t2.pb(x);
	}
	f(t1),f(t2);
}

void mian(){
	
	vector<ll>t;
	scanf("%lld",&n);
	For(i,1,n){
		scanf("%lld",&a[i]);
		t.pb(a[i]);
	}
	f(t);
	printf("%lld",ans);
	
}

int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int T=1;
	while(T--)mian();
	return 0;
}
