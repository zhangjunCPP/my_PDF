#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ll n,ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				for(ll k=1;k<=n;k++)
					if((i*j)%k==0&&(i*j)/k<=n) ans++;
		cout<<ans<<endl;
	}
	return 0;
} 
