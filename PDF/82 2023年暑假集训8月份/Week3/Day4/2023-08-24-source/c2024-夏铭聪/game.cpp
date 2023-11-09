#include<stdio.h>

const int N=2e5+5;
struct dy{
	int v,id;
}a[N];
bool f[N];
int n,b[N],ci,c[N],cc,ans,so[N];
void dfs(int u){
	if(u==n+1)
	{
		int s=0;cc=0;
		for(int i=0;i<ci;i++)
		{
			while(cc&&a[c[cc-1]].id<a[b[i]].id){cc--;s+=a[b[i]].v;}
			if(!cc||a[c[cc-1]].id>a[b[i]].id) c[cc++]=b[i];
		}
		if(s>ans)
		{
			for(int i=0;i<ci;i++) {so[i]=b[i];}
			ans=s;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			b[ci++]=i;
			dfs(u+1);
			f[i]=0;ci--;
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);bool f1=1,f2=1;
	for(int i=1;i<=n;i++) {scanf("%d",&a[i].v);a[i].id=n-i+1;if(a[i].v!=i) f1=0;if(a[i].v!=n-i+1) f2=0;}
	if(f1)
	{
		ans=n*(n-1)/2;printf("%d\n",ans);
		for(int i=1;i<=n;i++) printf("%d ",n-i+1);
	}
	else if(f2)
	{
		ans=n*(n-1);printf("%d\n",ans);
		for(int i=2;i<=n;i++) printf("%d ",i);
		printf("1");
	}
	else
	{
		dfs(1);printf("%d\n",ans);
		for(int i=0;i<n;i++) printf("%d ",so[i]);
	}
    return 0;
}