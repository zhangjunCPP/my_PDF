/*
考虑暴力
n<=8，全排列40320种，直接模 
*/
#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;
int n,i,a[100],flag,b[100],j,k,ans;
bool vis[100];
bool check(){
	for(int i=1;i<=n;++i){
		int mx;
//		printf("i=%d ",i);
//		if((a[i]<a[i+1]&&a[i-1]<a[i])||(i==1&&a[i]<a[i+1])||(i==n&&a[i-1]<a[i]))flag=1;//从小到大 
//		else if((a[i]>a[i+1]&&a[i-1]>a[i])||(i==1&&a[i]>a[i+1])||(i==n&&a[i-1]>a[i]))flag=-1;//从大到小
//		printf("flag=%d ",flag);
		flag=1;
		for(j=i-1;j;--j)if(a[j+1]-a[j]!=flag)break;
		for(k=i;k<n;++k)if(a[k+1]-a[k]!=flag)break;
		mx=k-j;
		flag=-1;
		for(j=i-1;j;--j)if(a[j+1]-a[j]!=flag)break;
		for(k=i;k<n;++k)if(a[k+1]-a[k]!=flag)break;
		if(max(mx,k-j)==b[i])continue;
		return 0;
//		printf("j=%d k=%d ",j,k);
//		putchar(10);
	}
	return 1;
}
void dfs(int now){
	if(now>n){
//		for(int i=1;i<=n;++i)printf("%d ",a[i]);
//		if(check())puts("OK");
//		else puts("NO");
		ans+=check();
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			a[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",b+i);
	a[0]=a[n]=INF;
	dfs(1);
	printf("%d",ans);
	return 0;
}
