#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> tp;
const int N=1e8+5;
const int M=1e6+5;
namespace sol1{
	const int CEIL=1e8;
	int n;
	bool ins[N];
	int lst=2,f[N];
	vector<int> prime;
	tp q[M];
	ll ans[M];
	void got(int lim){
		for(int i=lst;i<=lim;i++){
			if(!ins[i]) prime.push_back(i),f[i]=1;
			for(int u:prime){
				if(i*u>CEIL) break;
				ins[i*u]=true;
				f[i*u]=f[i]+1;
				if(i%u==0) break;
			}
		}
		lst=lim+1;
		return ;
	}
	void solve(){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>q[i].first,q[i].second=i;
		sort(q+1,q+n+1);
		for(int i=1;i<=n;i++){
			got(q[i].first);
			ll rs=1;
			
			for(int j=1;j<=q[i].first;j++)
				if(f[j]) rs+=(1ll<<(f[j]+f[j]));
			cout<<rs<<'\n';
			for(int j=q[i].first+1;j<=q[i].first*q[i].first;j++){
				if(f[j]) rs+=(1<<(f[j]+f[j]));
				for(int k=j;k<=q[i].first*q[i].first;k+=j)
					if(f[k]) rs--;
			}
			ans[q[i].second]=rs;
		}
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<'\n';
	}
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	sol1::solve();
	return 0;
}
/*
4
1 2 7 35

3
1 2 7
*/
