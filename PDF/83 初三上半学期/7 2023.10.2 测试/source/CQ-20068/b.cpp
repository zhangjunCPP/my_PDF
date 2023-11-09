#include<stdio.h>
#include<math.h>
#include<algorithm>
#define int long long

const int N=1e6+5,inf=2e9;
int n,a[N],s[N],ci,ans;
double b[N];
void dfs(int u){
	if(u==n+1)
	{
		if(ci==0) return ;
		double sum=0;int cnt=0;
		for(int i=0;i<ci;i++) sum+=s[i];
		sum/=1.0*ci;
		for(int i=0;i<ci;i++) if(sum<s[i]) cnt++;
//		printf("cnt:%d %.2lf\n",cnt,sum);
//		for(int i=0;i<ci;i++) printf("%d ",s[i]);
//		printf("\n-----\n");
		ans=std::max(ans,cnt);
		return ;
	}
	s[ci++]=a[u];dfs(u+1);ci--;
	dfs(u+1);
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n>20)
	{
		ci=n;
		while(ci)
		{
			double sum=0,ma=0;int u,cnt=0;
			for(int i=1;i<=n;i++) if(a[i]!=inf) sum+=a[i];
			sum/=1.0*ci;
			for(int i=1;i<=n;i++) if(a[i]!=inf&&a[i]>sum) cnt++;
			if(ans>cnt) break;
			else ans=cnt;
			for(int i=1;i<=n;i++) if(a[i]!=inf) b[i]=abs(sum-a[i]);
			for(int i=1;i<=n;i++) if(a[i]!=inf&&b[i]>ma) {ma=b[i];u=i;}
			a[u]=inf;ci--;
		}
	}
	else dfs(1);
	printf("%lld\n",ans);
	return 0;
}

