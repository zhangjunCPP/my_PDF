#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int mod=998244353;
const int N=30;
int n,a[N],vis[N],answ[N],ans,sum,x;
void dfs(int now,int res1,int res2,int res3){
	if(now>n){
		int res=max(abs(res1-res2),max(abs(res2-res3),abs(res3-res1)));
		if(ans>res){
			ans=res;
			for(int i=1;i<=n;++i)answ[i]=vis[i];
		}
		return;
	}
	vis[now]=1,dfs(now+1,res1+a[now],res2,res3);
	vis[now]=2,dfs(now+1,res1,res2+a[now],res3);
	vis[now]=3,dfs(now+1,res1,res2,res3+a[now]);
}
void dfs2(int now,int res1,int res2,int res3){
	if(res1>x||res2>x||res3>x)return;
	if(now>n){
		int res=max(abs(res1-res2),max(abs(res2-res3),abs(res3-res1)));
		if(ans>res){
			ans=res;
			for(int i=1;i<=n;++i)answ[i]=vis[i];
		}
		return;
	}
	vis[now]=1,dfs(now+1,res1+a[now],res2,res3);
	vis[now]=2,dfs(now+1,res1,res2+a[now],res3);
	vis[now]=3,dfs(now+1,res1,res2,res3+a[now]);
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),sum+=a[i];
	if(n<=15){
		ans=0x3f3f3f3f;
		dfs(1,0,0,0);
		for(int i=1;i<=n;++i)printf("%d ",answ[i]);
	}else{
		x=sum/3;
		dfs2(1,0,0,0);
	}
	return 0;
}
