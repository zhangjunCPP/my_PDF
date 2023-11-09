#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=2e5+10;
int n,flag1,flag2,tmp[N];
LL ans;
struct node{
	int id,v;
}a[N];
bool cmp(node a,node b){return a.v<b.v;}
int num[N],vis[N];
stack<int> stk;
void dfs(int now){
	if(now>n){
		LL res=0;
		while(stk.size())stk.pop();
		for(int i=1;i<=n;++i){
			while(stk.size()&&a[stk.top()].id<a[num[i]].id)
				res+=1ll*a[num[i]].v,stk.pop();
			stk.push(num[i]);
		}
		if(res>ans){
			ans=res;
			for(int i=1;i<=n;++i)tmp[i]=num[i];
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=1,num[now]=i,dfs(now+1),vis[i]=0;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),flag1=flag2=1;
	for(int i=1;i<=n;++i){
		a[i].id=n-i+1,a[i].v=read();
		if(a[i].v!=i)flag1=0;
		if(a[i].v!=n+1-i)flag2=0;
	}
	if(flag1){
		printf("%lld\n",1ll*n*(n-1)/2);
		for(int i=n;i;--i)printf("%d ",i);
	}else if(flag2){
		printf("%lld\n",1ll*n*(n-1));
		for(int i=2;i<=n;++i)printf("%d ",i);
		printf("1\n");
	}else if(n<=10){
		dfs(1);
		printf("%lld\n",ans);
		for(int i=1;i<=n;++i)printf("%d ",tmp[i]);
	}
	return 0;
}
