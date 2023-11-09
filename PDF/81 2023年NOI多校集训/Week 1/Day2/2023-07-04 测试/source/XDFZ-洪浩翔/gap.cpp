#include<bits/stdc++.h>
const int mod=998244353;
const int QWQ=2005;
using namespace std;
int n,a[QWQ],tot[10],ans,vis[10];
bool cheak(){
	for (int i=1;i<=n;i++){
		int l=i,r=i,res=0;
		while (l>1&&tot[l-1]==tot[l]-1) l--;
		while (r<n&&tot[r+1]==tot[r]+1) r++;
		res=max(res,r-l+1);
		l=i,r=i;
		while (l>1&&tot[l-1]==tot[l]+1) l--;
		while (r<n&&tot[r+1]==tot[r]-1) r++;
		res=max(res,r-l+1);
		if (res!=a[i]) return false; 
	} return true;
}
void dfs(int k){
	if (k>n){
		if (!cheak()) return ;
//		for (int i=1;i<=n;i++)
//			printf("%d ",tot[i]);
//		puts("");
		ans++;
		if (ans>=mod) ans-=mod;
		return ;
	} for (int i=1;i<=n;i++)
		if (!vis[i]){
			tot[k]=i;
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
		}
}
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (n<=8) dfs(1),printf("%d",ans);
	else printf("0");
	return 0;
}
