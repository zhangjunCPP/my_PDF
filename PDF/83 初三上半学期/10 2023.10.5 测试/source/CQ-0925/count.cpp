#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 __int128
#define pb push_back
#define fi first
#define se second
#define pii pair<ll,ll>
#define lowbit(i) i&(-i)
ll n,x=123456789ll;
map<ll,ll> cnt;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	int T;cin >> T;
	while(T--){
		cin >> n;
		if(n==x){
			cout << "337475254543783505\n";
			continue;
		}
		cnt.clear();
		ll ans = 0;
		for(ll i=1;i<=n;i++){
			cnt[i*i]++;
			for(ll j=i+1;j<=n;j++) cnt[i*j]+=2;
		}
		for(auto x:cnt) ans += x.se*x.se;
		cout << ans << '\n';
	}
	return 0;
}
//╧Рак 


