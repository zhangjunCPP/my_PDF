#include<bits/stdc++.h>
using namespace std;
int t,n,m,u,v,ans;
vector<int> mp[1000050];
map<pair<int,int>,bool> mp1;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t;
	while(t--){
		mp1.clear();
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++){
			mp[i].clear();
		}
		for(int i=1;i<=m;i++){
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
			mp1[{v,u}]=1;
			mp1[{u,v}]=1;
		}
		for(int i=1;i<=n;i++){
			int s=mp[i].size();
			ans=max(ans,s);
		}
		if(ans<3&&m>=3){
			int f=0;
			for(int i=1;i<=n;i++){
				for(int j:mp[i]){
					for(int k:mp[i]){
						if(j!=k&&mp1[{j,k}]){
							ans=3;
							f=1;
							break;
						}
					}
					if(f==1){
						break;
					}
				}
				if(f==1){
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
