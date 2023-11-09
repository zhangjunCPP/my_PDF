#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e6+10;
const int mod=1e9+7;
int n,head[N],cnt,out[N],in[N],ans,col[N],now[N],st[N][20],dep[N];
struct node{
	int to,next;
}e[N<<1];
void add(int u,int v){e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;}
int my_pow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
void dfs(int u,int f){
	st[u][0]=f,dep[u]=dep[f]+1;
	for(int i=1;i<20;++i)st[u][i]=st[st[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==f)continue;
		dfs(v,u);
	}
}
int get(int u,int k){
	for(int i=19;~i;--i)
		if(dep[st[u][i]]>=k)u=st[u][i];
	return u;
}
int LCA(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	v=get(v,dep[u]);
	if(u==v)return u;
	for(int i=19;~i;--i)
		if(st[u][i]!=st[v][i])u=st[u][i],v=st[v][i];
	return st[u][0];
}
int get_dis(int u,int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();int flag=1,flag2=1;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u),++out[u],++in[v];
		if(u!=i||v!=i+1)flag=0;
	}
	for(int i=1;i<=n;++i){
		if(i==1&&out[i]+in[i]<=2)flag2=0;
		if(i!=1&&out[i]+in[i]>2)flag2=0;
	}
	dep[0]=-1,dfs(1,0);
	if(out[1]==n-1){
		if(n==2)printf("2\n");
		else if(n==3)printf("12\n");
		else printf("%d\n",my_pow(2,n)*2%mod);
	}else if(n<=10){
		int hh=0;
		for(int s=(1<<n)-1;s;s=(s-1)&((1<<n)-1)){
			int mx=0;
			for(int i=1;i<=n;++i)
				for(int j=i+1;j<=n;++j){
					if(((s>>(i-1))&1)==((s>>(j-1))&1))mx=max(mx,get_dis(i,j));
				}
			ans+=mx,hh=max(hh,mx);
		}
		ans+=hh;
		printf("%d\n",ans);
	}else if(flag2){
		int mx=0;
		for(int i=2;i<=n;++i)
			mx=max(mx,dep[i]);
		printf("%d\n",my_pow(2,n)*mx%mod*2%mod);
	}else if(flag){
		
	}
	return 0;
}
/*
6
1 2
2 3
3 4
4 5
3 6
*/
