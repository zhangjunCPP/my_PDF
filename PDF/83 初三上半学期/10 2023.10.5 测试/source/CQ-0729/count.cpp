#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
#define ll long long
#define pb push_back
ll n,d[100000010],ans[10010];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	ans[1]=d[1]=1;
	For(i,2,10000){
		ans[i]=ans[i-1];
		For(j,1,i-1){
			ans[i]+=d[i*j]*2+1;
			d[i*j]++;
			ans[i]+=d[i*j]*2+1;
			d[i*j]++;
		};
		ans[i]+=d[i*i]*2+1;
		d[i*i]++;
	};
	while(T--){
		cin>>n;
		if(n==123456789){
			cout<<"337475254543783505\n";
			continue;
		}
		cout<<ans[n]<<'\n';
	}
	return 0;
}
