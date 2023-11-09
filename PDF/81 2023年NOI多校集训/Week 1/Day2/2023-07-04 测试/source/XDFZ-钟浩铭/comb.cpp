#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,ans=-INT_MAX;
int a[MAXN],num[MAXN];
bool vis[MAXN];
inline int work(){
	int len=0; bool flag=0;
	for(int i=1;i<=n;){
		int u=i+2; flag=0;
		if(a[i]==a[u] && a[i+1]==a[u+1]){
			len+=4; i=u+2; flag=1;
		}
		if(!flag) i++;
	}
	return len;
}
//6 
//1 2 0 1 2 0
void dfs(int k){
	if(k==n+1){
		ans=max(ans,work());
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			num[k]=a[i];
			dfs(k+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}
