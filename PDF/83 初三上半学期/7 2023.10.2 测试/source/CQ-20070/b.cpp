#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e6+10;
int n,a[N],vis[N];
LL sum[N],ans;
void dfs(int now){
	if(now>n){
		LL sum=0,res=0,num=0;
		for(int i=1;i<=n;++i)
			if(vis[i])sum+=1ll*a[i],++res;
		if(!res)return;
		for(int i=1;i<=n;++i)
			if(vis[i]&&a[i]*res>sum)++num;
		ans=max(ans,num);return;
	}
	vis[now]=1,dfs(now+1),vis[now]=0,dfs(now+1);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+1ll*a[i];
	if(n<=20){
		dfs(1);
		printf("%lld\n",ans);
	}else if(n<=2000){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				int now=j;
				while(now<=n&&sum[i]+sum[now]-sum[j-1]>=1ll*a[i]*(1ll*i+now-j+1)&&sum[i]+sum[now]-sum[j-1]<1ll*a[j]*(1ll*i+now-j+1))++now;
				if(now==n+1&&sum[i]+sum[now]-sum[j-1]>=1ll*a[i]*(1ll*i+now-j+1)&&sum[i]+sum[now]-sum[j-1]<1ll*a[j]*(1ll*i+now-j+1))ans=max(ans,1ll*n-j+1);
				else if(now<=n){--now,ans=max(ans,1ll*now-j+1);}
//				cout<<i<<" "<<j<<" "<<now<<" "<<ans<<endl;
			}
		}
		printf("%lld\n",ans);
	}
//	for(int i=1;i<=n;++i){
//		int c=a[i]*i-sum[i],siz=i,now=i+1,du=0;
//		while(now<=n&&du<=c)du+=a[now]-a[i],++now,++siz;
//		if(now==n){
//			if(abs(c-du)>(a[i+1]-a[i])*siz)continue;
//			ans=max(ans,siz-i);
//		}else{
//			while()
//		}
//	}
	return 0;
}
