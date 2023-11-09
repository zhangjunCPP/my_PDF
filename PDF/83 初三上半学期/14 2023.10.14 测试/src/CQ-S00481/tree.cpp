#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define i64 __int128
#define lowbit(i) i&(-i)
const int N = 1e6,P = 131;
int vis[N],n;
struct G{
	int u,v;
}g[N];
map<ll,int> cnt;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	int typ = 1;
	for(int i=1;i<n;i++){
		cin >> g[i].u >> g[i].v;
		if(g[i].u!=1 && g[i].v!=1) typ = 0;
	}
	if(n<=10){
		for(int s=0;s<(1<<(n-1));s++){
			for(int i=1;i<=n;i++) vis[i] = 0;
			vector<int> x;
			for(int i=1;i<n;i++){
				int opt = s&(1<<(i-1));
				if(vis[g[i].v]+vis[g[i].u]) continue;
				if(opt){
					vis[g[i].v] = 1;
					x.pb(g[i].v);
				}else{
					vis[g[i].u] = 1;
					x.pb(g[i].u);
				}
			}
			ll val = 0;
			for(int y:x) val *= P,val += y;
			cnt[val] = 1;
		}
		cout << cnt.size() << '\n'; 
	}else if(typ){
		cout << n << '\n';
	}
	return 0;
}
