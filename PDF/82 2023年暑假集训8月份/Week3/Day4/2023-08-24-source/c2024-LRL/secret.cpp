#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int mod=65535;
int T,k,c[260],num[20],n,vis[20],p[20],flag;
LL ans;
void dfs(int now){
	if(now>n){
		int quan=1;
		LL res=0;
		for(int i=1;i<=n;++i)res=(res+1ll*p[i]*quan%mod)%mod,quan=quan*256%mod;
		ans=ans*res%mod;return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=1,p[now]=num[i],dfs(now+1),vis[i]=0;
	}
}
int main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	T=read();
	while(T--){
		k=read(),n=0,ans=1;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=k;++i){
			int x=read(),y=read();
			c[x]=y,flag=x;
			if(k<=3&&y<=9){
				for(int j=1;j<=y;++j)num[++n]=x;
			}else n+=y;
		}
		if(k<=3&&n<=9){
			dfs(1);
			printf("%lld\n",ans);
		}else if(k==1){
			int base=1;
			LL res=0;
			for(int i=1;i<=c[flag];++i)
				res=(res+1ll*base*flag%mod)%mod,base=base*256%mod;
			printf("%lld\n",res);
		}
	}
	return 0;
}
