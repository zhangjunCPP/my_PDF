#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000+10;
int n;
int l[N],r[N];
ll c[N];
bool vis[N];
ll ans=0;
void dfs(int now,ll sum){
	if(now==n+1){
		ans=max(ans,sum);
		return;
	}
	ll tad;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			tad=0;
			vis[i]=1;
			for(int j=l[i];j<=r[i];j++){
				if(!vis[j]) tad+=c[i];
			}
			dfs(now+1,tad+sum);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%lld",&l[i],&r[i],&c[i]); 
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 


