#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 1000010
#define ll long long
#define pb push_back
int n,m;
vector<int>e[N];
void solve(){
	cin>>n>>m;
	For(i,1,n)e[i].clear();
	For(i,1,m){
		int x,y;
		cin>>x>>y;
		e[x].pb(y);
		e[y].pb(x);
	};
	int ans=0;
	For(i,1,n){
		ans=max(ans,(int)e[i].size());
	}
	if(ans<3){
		For(i,1,n){
			sort(e[i].begin(),e[i].end());
		};
		For(i,1,n){
			for(int j:e[i]){
				for(int k:e[i]){
					for(int l:e[j]){
						if(k==l){
							cout<<"3\n";
							return;
						}
					}
				}
			}
		};
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
