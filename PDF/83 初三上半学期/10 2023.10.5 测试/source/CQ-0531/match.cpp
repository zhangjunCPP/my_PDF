#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,m;
int d[N];
vector<int> g[N];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		g[i].clear();
		d[i]=0;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		d[x]++;d[y]++;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,d[i]);
	if(ans==2){
		for(int x=1;x<=n;x++){
			if(d[x]==2){
				int t1=g[x][0],t2=g[x][1];
				for(int v:g[t1]){
					if(v==t2){
						printf("3\n");
						return;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
