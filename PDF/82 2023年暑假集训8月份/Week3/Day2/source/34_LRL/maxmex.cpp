#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e5+10;
int n,q,a[N],f[N],vis[N];
void pre(){
	for(int k=1;k<=n;++k){
		for(int l=1;l<=n-k+1;++l){
			int r=l+k-1;
			for(int i=0;i<=n;++i)vis[i]=0;
			for(int i=l;i<=r;++i)vis[a[i]]=1;
			int flag=1e9;
			for(int i=0;i<=n;++i)
				if(!vis[i]){flag=i;break;}
			if(flag==1e9)f[k]=max(f[k],n+1);
			else f[k]=max(f[k],flag);
		}
	}
}
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	q=read();
	if(n<=100){
		pre();
		while(q--){
			int k=read();
			printf("%d\n",f[k]);
		}
	}else if(q<=10){
		while(q--){
			int k=read(),last=1e9,now,ans;
			for(int i=0;i<=n;++i)vis[i]=0;
			for(int i=1;i<=k;++i)++vis[a[i]];
			for(int i=0;i<=n;++i)
				if(!vis[i]){last=i;break;}
			if(last==1e9)last=n+1;
			ans=last;
			for(int i=k+1;i<=n;++i){
				now=last,--vis[a[i-k]];
				if(!vis[a[i-k]]){
					if(a[i-k]<last)now=a[i-k];
				}
				++vis[a[i]];
				if(vis[a[i]]==1){
					if(a[i]==now){
						while(vis[now])++now;
					}
				}
				ans=max(ans,now),last=now;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
