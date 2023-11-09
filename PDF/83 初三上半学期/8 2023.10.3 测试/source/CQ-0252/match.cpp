#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
#define i64 __int128
const int N = 1e6+7;
int n,m,k,p[N],val[N],vis[5][N],ans[N];
vector<int> b[N];
int comp(int st){
	for(int i=st;i>=0;i--){
		if(vis[1][i]!=vis[2][i]){
			if(vis[1][i]) return 2;
			else return 1;
		}
	}
	return 2;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1,x,k;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> x;
			b[i].pb(x);
		}
	}
    if(n<=2 && m<=1000000){
		if(n==1){
			for(int x:b[1]) vis[1][x] = 1;
			for(int i=0;i<m;i--) cout << vis[1][i];
		}else{
			for(int i=1;i<=2;i++){
				for(int x:b[i]) vis[i][x] = 1;
			}
			int las = m; 
			for(int i=m-1;i>=0;i--){
				int typ = vis[1][i]+vis[2][i];
				if(typ==2){
					if(las==m){
						cout << -1;
						return 0;
					}else{
						ans[las] = 1;
						if(comp(las-1)==1){
							for(int j=las-1;j>=0;j--) ans[j] = vis[1][j];
						}else{
							for(int j=las-1;j>=0;j--) ans[j] = vis[2][j];
						}
						break;
					}
				}else if(typ==1){
					ans[i] = 1;
				}else if(typ==0){
					las = i;
				}
			}
			for(int i=0;i<m;i++) cout << ans[i];
		}
		
	}else cout << -1;
	return 0;
}

