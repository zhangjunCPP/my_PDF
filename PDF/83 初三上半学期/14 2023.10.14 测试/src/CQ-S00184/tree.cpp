#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
const ll mod=998244353;
int n;
int e[N][2];
bool pd_flower(){
	for(int i=1;i<n;i++)
		if(e[i][0]!=1||e[i][1]!=i+1)
			return false;
	return true;
}
bool pd_chain(){
	for(int i=1;i<n;i++)
		if(e[i][0]!=i||e[i][1]!=i+1)
			return false;
	return true;
}
namespace sol1{// 10pts
	const ll P=13;
	ll ans;
	unordered_map<ll,bool> vis;
	bool ins[N];
	void dfs(int k,ll val){
		if(k>n){
			if(!vis[val])
				vis[val]=true,ans++;
			return ;
		}
		if(!ins[e[k][0]]&&!ins[e[k][1]]){
			ins[e[k][0]]=true;
			dfs(k+1,val*P+e[k][0]);
			ins[e[k][0]]=false;
			ins[e[k][1]]=true;
			dfs(k+1,val*P+e[k][1]);
			ins[e[k][1]]=false;
		}
		else dfs(k+1,val*P);
		return ;
	}
	void solve(){
		dfs(1,0);
		cout<<ans;
		return ;
	}
}
namespace sol2{// 12pts
	void solve(){
		cout<<n;
		return ;
	}
}
namespace sol3{// 16pts
	ll f[N][3];
	void solve(){
		f[1][1]=f[1][2]=1;
		for(int i=2;i<n;i++)
			(f[i][0]+=f[i-1][2])%=mod,
			(f[i][1]+=f[i-1][0]+f[i-1][1])%=mod,
			(f[i][2]+=f[i-1][0]+f[i-1][1])%=mod;
		cout<<(f[n-1][0]+f[n-1][1]+f[n-1][2])%mod;
		return ;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>e[i][0]>>e[i][1];
	if(n<=10) sol1::solve();
	else if(pd_flower()) sol2::solve();
	else if(pd_chain()) sol3::solve();
	return 0;
}

