#include<bits/stdc++.h>
#define int long long
using namespace std;
int head[100001],cnt,n,m,t,ans,x,y;
struct dcz{
	int x,y;
}a[100001];
vector<int> v[1001];
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		if(n<=20&&m<=20){
			for(int i=1;i<=m;i++){
				cin>>a[i].x>>a[i].y;
				v[i].push_back(i);
			}
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(i==j) continue;
					bool f=1;
					for(int k=0;k<v[j].size();k++){
						if(a[v[j][k]].x==a[i].x||a[v[j][k]].x==a[i].y||a[v[j][k]].y==a[i].x||a[v[j][k]].y==a[i].y) continue;
						f=0;
						break;
					}
					if(f) v[j].push_back(i);
				}
			}
			for(int i=1;i<=m;i++){
				int x=v[i].size();
				ans=max(ans,x);
			}
			cout<<ans<<endl;
			continue;
		}
		if(m==n-1){
			for(int i=1;i<=m;i++){
				cin>>x>>y;
				if(x==y-1){
					cout<<min(2ll,m)<<endl;
				}
				else{
					cout<<m<<endl;
				}
			}
		}
		else if(m==n){
			for(int i=1;i<=m;i++){
				cin>>x>>y;
			}
			if(m==3) cout<<3<<endl;
			else cout<<2<<endl;
		}
	}
	return 0;
}
