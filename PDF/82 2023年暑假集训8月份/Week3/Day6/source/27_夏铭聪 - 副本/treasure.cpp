#include<stdio.h>

template<typename dy> dy max(dy x,dy y){return x>y?x:y;}
template<typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=35;
int n,a[N],b[N],ans=0x3f3f3f3f,s[N];
void dfs(int u){
	if(u==n+1)
	{
		int sum[4]={};
		for(int i=1;i<=n;i++) sum[b[i]]+=a[i];
		int t=max(max(sum[1],sum[2]),sum[3]),tt=min(min(sum[1],sum[2]),sum[3]);
		if(t-tt<ans)
		{
			ans=t-tt;
			for(int i=1;i<=n;i++) s[i]=b[i];
		}
		return;
	}
	b[u]=1;dfs(u+1);
	b[u]=2;dfs(u+1);
	b[u]=3;dfs(u+1);
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	for(int i=1;i<=n;i++) printf("%d ",s[i]);
    return 0;
}