#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
int t,n,m,K,ans;
int g1[105][105],g2[105][105],vis[105][105];
int id[maxn];
void dfs1(int x){
	if(x==n+1){
		int val=1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(!vis[i][j])continue;
				if(id[i]==id[j])val=val*g2[i][j]%mod;
				else val=val*g1[i][j]%mod;
			}
		}
		ans=(ans+val)%mod;
		return ;
	}
	for(int i=1;i<=K;i++){
		id[x]=i;
		dfs1(x+1);
		id[x]=0;
	}
}
signed main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>K;
		int sum=0;ans=0;
		for(int i=1;i<=m;i++){
			int x,y,l,r;cin>>x>>y>>l>>r;
			if(x>y)swap(x,y);
			if(!vis[x][y]){
				vis[x][y]=1;
				g1[x][y]=g2[x][y]=1;
			}
			g1[x][y]=g1[x][y]*l%mod,g2[x][y]=g2[x][y]*r%mod;
			sum+=r;
		}
		if(sum==0){
			if(n>K)ans=0;
			else{
				ans=1;
				for(int i=n;i>=n-K+1;i--)ans=ans*i%mod;
			}
		}
		else dfs1(1);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)g1[i][j]=g2[i][j]=vis[i][j]=0;
		}
	}
	return 0;
}
//1
//5 17 9
//3 2 2 4
//3 2 7 7
//4 3 6 2
//4 5 8 8
//2 3 7 0
//4 1 2 0
//3 5 0 8
//4 2 0 8
//3 4 4 4
//3 5 8 7
//1 2 3 6
//3 1 1 3
//3 5 6 4
//3 1 8 1
//3 4 1 7
//4 2 2 8
//4 2 4 6
