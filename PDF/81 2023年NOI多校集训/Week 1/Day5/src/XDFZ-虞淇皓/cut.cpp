#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],vis[30],dp[N],g[N],s[N];
int st[N],tot;
void sl1(){
//	cout<<endl;
	if(a[1]!=0)dp[1]=0;
	else dp[1]=1;
//	cout<<dp[1]<<" ";
//	cout<<0<<" ";
//	int mx=-1,mx2=-1;
	for(int i=2;i<=n;i++){
		dp[i]=-1;
		int x=0;
		for(int j=i-1;j>=0;j--){
			vis[a[j+1]]=i;
			while(vis[x]==i)x++;
			if(dp[j]+x>=dp[i]){
				dp[i]=dp[j]+x;
				g[i]=j;
				s[i]=s[j]+1;
//				cout<<i<<" "<<j<<"  "<<x<<" "<<dp[i]<<" "<<dp[j]<<" "<<s[i]<<" "<<s[j]<<endl;
			}
		}
//		cout<<g[i]<<" ";
//		if(g[i]<g[i-1]){
//			cout<<a[i]<<" ";
//			mx=max(mx,a[i]),mx2=max(mx2,g[i]);
//		}
	}
//	cout<<endl;
//	cout<<mx<<" "<<mx2<<endl;
//	for(int i=2;i<=n;i++){
//		if(g[i]<g[i-1]){
//			mx=max(mx,a[i]),mx2=max(mx2,g[i]);
//			cout<<i<<' '<<a[i]<<" "<<g[i]<<" "<<a[g[i]]<<endl;
//		}
//	}
	cout<<dp[n];
	int i=n;
	while(i){
		i=g[i];
		st[++tot]=i+1;
	} 
	cout<<" "<<tot<<endl;
	for(i=tot;i;i--){
		cout<<st[i]<<" ";
	}
}
void sl2(){
	if(a[1]!=0)dp[1]=0;
	else dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=-1;
		int x=0,lse;
		if(a[i]<=5||i==2)lse=0;
		else lse=g[i-1]-10;
		for(int j=i-1;j>=lse;j--){
			vis[a[j+1]]=i;
			while(vis[x]==i)x++;
			if(dp[j]+x>=dp[i]){
				dp[i]=dp[j]+x;
				g[i]=j;
				s[i]=s[j]+1;
			}
		}
	}
	cout<<dp[n]<<' '<<s[n]<<endl;
	int i=n;
	while(i){
		i=g[i];
		st[++tot]=i+1;
	} 
	for(i=tot;i;i--){
		cout<<st[i]<<" ";
	}
}
signed main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
//		cout<<a[i]<<" ";
	}
	if(n*n<=8e8)sl1();
	else sl2();
	return 0;
}
/*
*/
