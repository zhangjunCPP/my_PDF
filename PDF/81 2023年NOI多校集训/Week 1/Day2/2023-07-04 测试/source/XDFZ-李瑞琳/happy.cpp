#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e5+10;
int n,k,t[N],x;
LL dp[N];
/*dp[i]>=dp[i-1]*/
struct node{
	int num,cost;
}a[N];
bool cmp(node a,node b){
	if(a.num==b.num)return a.cost<b.cost;
	return a.num>b.num;
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;++i)t[i]=read();
	for(int i=1;i<=k;++i)a[i].num=read(),a[i].cost=read();
	x=read();
	sort(a+1,a+1+k,cmp);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0ll;
	for(int i=1;i<=n;++i){
		dp[i]=min(dp[i],dp[i-1]+1ll*x);
		for(int j=1;j<=k;++j){
			int xx=lower_bound(t+1,t+1+i,t[i]-a[j].num+1)-t;
			dp[i]=min(dp[xx-1]+1ll*a[j].cost,dp[i]);
			if(dp[i]==dp[i-1])break;
		}
	}
	for(int i=1;i<=n;++i)printf("%lld\n",dp[i]-dp[i-1]);
	return 0;
}
