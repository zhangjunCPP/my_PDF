#include<bits/stdc++.h>
using namespace std;
struct num{
	long long a;
	long long b;
};
long long n,t,ans;
vector<num> a[1000050];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(long long i=1;i<=min((long long)1000050,(long long)n*n);i++){
			a[i].clear();
		}
		for(long long i=1;i<=n*n;i++){
			for(long long j=1;j<=n;j++){
				if(i%j==0&&i/j<=n){
					a[i].push_back({i/j,j});
				}
			}
			for(long long j=0;j<a[i].size();j++){
				if(a[i][j].a==a[i][j].b){
					ans+=a[i].size();
				}
				else{
					ans+=a[i].size();
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
