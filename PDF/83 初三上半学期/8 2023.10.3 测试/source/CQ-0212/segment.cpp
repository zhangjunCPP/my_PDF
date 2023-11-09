#include<stdio.h>

template <typename dy> dy max(dy x,dy y){return x>y?x:y;}
template <typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=2e5+5,inf=2e9;
int n,a[N],s[N],ci,ans=inf;
void dfs(int u){
	if(u==n+1)
	{
		int ma=0,mi=inf;
		for(int i=0;i<ci;i++) {
			ma=max(ma,s[i]);
			mi=min(mi,s[i]);
		}
		ans=min(ans,ma-mi);
		return ;
	}
	s[ci++]=a[u];dfs(u+1);ci--;
	if(u<n) {s[ci++]=a[u]+a[u+1];dfs(u+2);ci--;}
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}

