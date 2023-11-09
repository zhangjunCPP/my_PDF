#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e6+10;
int T,n,m,cnt,head[N],deg[N],ans;
struct node{
	int to,next;
}e[N<<1];
void add(int u,int v){e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;}
/*ÕÒÈýÔª»·*/
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),cnt=0;
		for(int i=1;i<=n;++i)head[i]=deg[i]=0;
		for(int i=1;i<=m;++i){
			int u=read(),v=read();
			add(u,v),add(v,u),++deg[u],++deg[v];
		}
		int flag=0;
		for(int u=1;u<=n;++u){
			if(deg[u]<=1)continue;
			for(int i=head[u];i;i=e[i].next){
				int v=e[i].to;
				if(deg[v]<=1)continue;
				for(int j=head[v];j;j=e[j].next){
					int v2=e[j].to;
					if(v2==u||deg[v2]<=1)continue;
					for(int k=head[v2];k;k=e[k].next){
						int v3=e[k].to;
						if(v3==v||deg[v3]<=1)continue;
						if(v3==u){flag=1;break;}
					}
					if(flag)break;
				}
				if(flag)break;
			}
			if(flag)break;
		}
		ans=flag?3:0;
		for(int i=1;i<=n;++i)ans=max(ans,deg[i]);
		printf("%d\n",ans);
	}
	return 0;
}
