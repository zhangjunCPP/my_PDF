/*
难过
打暴力吧 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,INF=INT_MAX;
int n,a[N],i,ans=INF;
void dfs(int now,int mx,int mn){
	if(mx-mn>=ans)return;
	if(now>n){
		ans=min(ans,mx-mn);
		return;
	}
	if(now+1<=n)dfs(now+2,max(mx,a[now]+a[now+1]),min(mn,a[now]+a[now+1]));
	dfs(now+1,max(mx,a[now]),min(mn,a[now]));
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	dfs(1,0,INF);
	printf("%d",ans);
	return 0;
}

