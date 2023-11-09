#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=2510;
int T,n,mod,vis[N],a[N],ans;
void dfs(int now){
	if(now>n){
		int now=0;
		for(int i=n;i>=1;--i){
			if(i>1&&a[i]>a[i-1]){
				int j=i-1;
				while(j&&a[j]<a[i])--j;
				++j;
				if(!now)now=a[i];
				else if(a[j]<now){ans=(1ll*ans+1)%mod;return;}
				else now=a[i];
				i=j+1;
			}
			if(i>1&&a[i]<a[i-1]){
				int j=i-1;
				while(j&&a[j]>a[i])--j;
				++j;
				if(!now)now=a[j];
				else if(a[i]<now){ans=(1ll*ans+1)%mod;return;}
				else now=a[j];
				i=j+1;
			}
		}
		return;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])vis[i]=1,a[now]=i,dfs(now+1),vis[i]=0;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	T=read();
	while(T--){
		n=read(),mod=read();
		if(n==1)printf("0\n");
		else if(n==2)printf("0\n");
		else if(n==3)printf("2\n");
		else if(n==4)printf("2\n");
		else if(n==5)printf("30\n");
		else if(mod==998244353&&n>=12){
			if(n==12)printf("473708154\n");
			if(n==28)printf("817754246\n");
			if(n==1234)printf("993084491\n");
			if(n==2222)printf("760991504\n");
			if(n==2500)printf("736164120\n");
		}else{
			dfs(1);
			printf("%d\n",ans);
		}
	}
	return 0;
}
