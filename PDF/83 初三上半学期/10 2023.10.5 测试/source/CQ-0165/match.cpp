#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;

vector<int> g[maxn];
int d[maxn];

int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin>>t;
	while(t--) {
		int n,m; cin>>n>>m;
		for(int i=1;i<=n;i++) d[i]=0, g[i].clear();
		for(int i=1;i<=m;i++) {
			int u,v; cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u); 
			d[u]++, d[v]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,d[i]);
		if(ans>=3) cout<<ans<<'\n';
		else {
			for(int i=1;i<=n;i++) {
				for(int j:g[i]) {
					for(int k:g[j]) {
						if(k==i) continue;
						for(int d:g[k]) {
							if(d==i) ans=3;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
