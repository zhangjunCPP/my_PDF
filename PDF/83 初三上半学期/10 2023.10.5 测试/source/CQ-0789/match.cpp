#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,m;
int deg[N];
bool ins[N];
vector<int> e[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			ins[i]=deg[i]=0,e[i].clear();
		for(int i=1,u,v;i<=m;i++)
			cin>>u>>v,
			deg[u]++,deg[v]++,
			e[u].push_back(v),
			e[v].push_back(u);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,deg[i]);
		for(int k=1;k<=n;k++){
			for(int to:e[k])
				ins[to]=true;
			bool fl=false;
			for(int v:e[k]){
				for(int to:e[v])
					if(ins[to])
						{ans=max(ans,3),fl=true;break;}
				if(fl) break;
			}
			for(int to:e[k])
				ins[to]=false;
			if(fl) break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
