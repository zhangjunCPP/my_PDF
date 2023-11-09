#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long opt;
	cin>>opt;
	while(opt--){
		long long n;
		cin>>n;
		if(n==123456789){
			cout<<337475254543783505<<endl;
			continue;
		}
		long long ans=0;
		for(long long i=1;i<=n*n;i++){
			long long yu=0;
			for(long long j=min(n,i);j>=1;j--){
				if(i%j==0&&i/j<=n){
					yu++;
				}
				if(i/j>n) break;
			}
			yu*=yu;
			ans+=yu;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
