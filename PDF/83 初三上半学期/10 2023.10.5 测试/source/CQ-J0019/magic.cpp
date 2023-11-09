#include<bits/stdc++.h>
using namespace std;
struct num{
	int l;
	int r;
	int c;
}a[1050];
int n,ans;
bool vis[1050];
void dfs(int k,int sum){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			vis[i]=0;
			for(int j=a[i].l;j<=a[i].r;j++){
				sum+=a[i].c*vis[j];
			}
			dfs(k+1,sum);
			for(int j=a[i].l;j<=a[i].r;j++){
				sum-=a[i].c*vis[j];
			}
			vis[i]=1;
		}
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r>>a[i].c;
		vis[i]=1;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
