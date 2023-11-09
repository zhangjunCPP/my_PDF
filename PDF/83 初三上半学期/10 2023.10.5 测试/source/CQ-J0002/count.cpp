#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[100001],cnt,n,m,t,ans,x,y;
struct dcz{
	int x,y;
}a[100001];
vector<int> v;
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						if(i*j==k*l) ans++;
					}
				}
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
