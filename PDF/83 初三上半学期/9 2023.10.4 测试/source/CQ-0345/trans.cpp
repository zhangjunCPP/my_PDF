#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=110;
const int mod=1e9+7;
int T,n,m,k,flag,e[N][N][2],G[N][N],tot,col[N],ans;
struct edge{
	int x,y,diff,same,opt;
}edg[N],edg_n[N];
int vis[N];
void dfs(int now){
	if(now>tot){
		int color=0;
		for(int i=1;i<=n;++i)col[i]=0;
		col[1]=++color;
		int tur=10;
		while(tur--){
			for(int i=1;i<=tot;++i){
				if(col[edg_n[i].x]!=col[edg_n[i].y]&&col[edg_n[i].x]&&col[edg_n[i].y]&&vis[i]==2)return;
				if(col[edg_n[i].x]==col[edg_n[i].y]&&col[edg_n[i].x]&&col[edg_n[i].y]&&vis[i]==1)return;
				if(vis[i]==2){
					if(!col[edg_n[i].x]&&col[edg_n[i].y])col[edg_n[i].x]=col[edg_n[i].y];
					if(col[edg_n[i].x]&&!col[edg_n[i].y])col[edg_n[i].y]=col[edg_n[i].x];
				}
			}
		}
		int res=1;
		for(int i=1;i<=tot;++i)
			if(vis[i]==1)res=1ll*res*edg_n[i].diff%mod;
			else res=1ll*res*edg_n[i].same%mod;
		ans=(1ll*ans+res)%mod;return;
	}
	if(edg_n[now].diff)vis[now]=1,dfs(now+1);
	if(edg_n[now].same)vis[now]=2,dfs(now+1);
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read(),flag=1;
		memset(e,1,sizeof(e)),memset(G,0,sizeof(G)),tot=ans=0;
		for(int i=1;i<=m;++i){
			edg[i].x=read(),edg[i].y=read(),edg[i].diff=read(),edg[i].same=read(),G[edg[i].x][edg[i].y]=G[edg[i].y][edg[i].x]=1;
			e[edg[i].x][edg[i].y][1]=e[edg[i].y][edg[i].x][1]=1ll*e[edg[i].x][edg[i].y][1]*edg[i].diff%mod;
			e[edg[i].x][edg[i].y][0]=e[edg[i].y][edg[i].x][0]=1ll*e[edg[i].x][edg[i].y][0]*edg[i].same%mod;
			if(!edg[i].diff)edg[i].opt=2;
			if(!edg[i].same)edg[i].opt=1;
			if(edg[i].diff!=1||edg[i].same!=0)flag=0;
		}
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				if(G[i][j]){
					edg_n[++tot].x=i,edg_n[tot].y=j,edg_n[tot].diff=e[i][j][1],edg_n[tot].same=e[i][j][0];
				}
		if(n==2){
			int c1=1,c2=1;
			for(int i=1;i<=m;++i)
				c1=1ll*c1*edg[i].diff%mod,c2=1ll*c2*edg[i].same%mod;
			if(k==1)printf("%d\n",c2%mod);
			else printf("%d\n",(1ll*c2*k+k*(k-1)%mod*c1%mod)%mod);
		}else if(flag){
			if(k<n)printf("0\n");
			else{
				int ans=1;
				for(int i=1;i<=n;++i)
					for(int j=i+1;j<=n;++j)
						ans=1ll*ans*e[i][j][1]%mod;
				for(int i=k;i>=k-n+1;--i)ans=1ll*ans*i%mod;
				printf("%d\n",ans);
			}
		}else if(m<=20){
			dfs(1);
			printf("%d\n",ans);
		}
	}
	return 0;
}
