#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1000006];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,ans=0,cnt=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,(int)vec[i].size());
			if(vec[i].size()==2) cnt++;
			vec[i].erase(vec[i].begin(),vec[i].end());
		}
		if(m!=3||cnt!=3) cout<<ans<<endl;
		else cout<<3<<endl;
	}
	return 0;
} 
