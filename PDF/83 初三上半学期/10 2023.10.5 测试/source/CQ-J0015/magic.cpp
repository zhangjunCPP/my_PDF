#include <bits/stdc++.h>
using namespace std;
struct ball{
	int l,r,c;
} a[1005];
int n,vis[1005],c[1005],ans;
void dfs(int k,int sum){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		int c=0;
		for(int j=a[i].l;j<=a[i].r;j++)
			c+=!vis[j];
		dfs(k+1,sum+c*a[i].c);
		vis[i]=0;
	}
}
int cmp(ball p,ball q){
	return p.c>q.c;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].l>>a[i].r>>a[i].c;
	sort(a+1,a+n+1,cmp);
	dfs(1,0);
	cout<<ans;
	return 0;
} 
