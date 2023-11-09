#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod=998244353;
int a[100001],n,m,l,r,ans,f;
map<pair<int,int>,int>mp;
vector<int>v;
void dfs(int x,int y){
	if(x>y){
		int g=v[0];
		for(int i=1;i<v.size();i++){
			g=__gcd(g,v[i]);
		}
		if(g==a[y]&&v.size()==1&&f) return;
		if(g==a[y]&&v.size()==1&&!f) f=1;
		ans=(ans*g)%mod;
		return;
	}
	v.push_back(a[x]);
	dfs(x+1,y);
	v.erase(v.end()-1);
	dfs(x+1,y);
}
signed main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>l>>r;
		if(mp[{l,r}]) cout<<mp[{l,r}];
		else{
			ans=1;
			f=0;
			dfs(l,r);
			cout<<ans<<endl;
			mp[{l,r}]=ans;
		}
	}
	return 0;
}

