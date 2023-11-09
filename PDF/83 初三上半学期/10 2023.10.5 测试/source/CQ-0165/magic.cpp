#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,mx,cnt;
ll dp[5050][1005], v1[5050][10][10], v2[5050][10][10];
int vis[1005], p[1005], l[1005], r[1005], c[1005];
int nxt[5050][10];
vector<int> vec[5050];

map<vector<int>,int> id;

void dfs(int x) {
	if(x==mx+1) {
		++cnt;
		vec[cnt].resize(mx+2);
		for(int i=1;i<=mx;i++) vec[cnt][i]=p[i];
		id[vec[cnt]]=cnt;
		return ;
	}
	for(int i=1;i<=mx;i++) {
		if(!vis[i]) {
			vis[i]=1, p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return ;
}

int main() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>l[i]>>r[i]>>c[i];
		mx=max(mx,max(i-l[i],r[i]-i));
	}
	dfs(1);
	for(int i=1;i<=cnt;i++) {
		for(int j=1;j<=mx;j++) {
			for(int k=l[j];k<j;k++) {
				if(vec[i][k]>vec[i][j]) dp[i][mx]+=c[j];
			}
		}
	}
	for(int i=1;i<=cnt;i++) {
		for(int j=1;j<=mx+1;j++) {
			vector<int> ve=vec[i];
			ve[mx+1]=j;
			for(int k=1;k<=mx;k++) if(ve[k]>=ve[mx+1]) ve[k]++;
			for(int k=1;k<=mx;k++) {
				v1[i][j][k]=v1[i][j][k-1];
				v2[i][j][k]=v2[i][j][k-1];
				if(ve[k]>ve[mx+1]) v1[i][j][k]++;
				if(ve[k+1]>ve[1]) v2[i][j][k]++;
			}
			int tmp=ve[1];
			for(int k=1;k<=mx;k++) {
				ve[k]=ve[k+1];
				if(ve[k]>=tmp) ve[k]--;
			}
			ve[mx+1]=0;
			nxt[i][j]=id[ve];
		}
	}
	for(int i=mx;i<n;i++) {
		for(int j=1;j<=cnt;j++) {
			for(int k=1;k<=mx+1;k++) {
				dp[nxt[j][k]][i+1]=max(dp[nxt[j][k]][i+1],dp[j][i]+c[i-mx+1]*v2[j][k][r[i-mx+1]-(i-mx+1)]+c[i+1]*(v1[j][k][mx]-v1[j][k][l[i+1]-(i-mx+1)]));
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=cnt;i++) {
		int st=n-mx;
		for(int j=st+1;j<n;j++) {
			for(int k=j+1;k<=r[j];k++) {
				if(vec[i][j-st]<vec[i][k-st]) dp[i][n]+=c[j];
			}
		}
		ans=max(ans,dp[i][n]);
	}
	cout<<ans<<'\n';
	return 0;
}
