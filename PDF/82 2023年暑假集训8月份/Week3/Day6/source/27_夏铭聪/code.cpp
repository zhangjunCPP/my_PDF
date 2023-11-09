#include<stdio.h>
#include<stdlib.h>

const int N=2e5+5,n=42;
int a,b,f[N],sum[N],t,s[N],d[N];
void dfs(int u,int x){
	// printf("%d %d %d\n",u-1,x,sum[u-1]);
	// system("pause");
	if(u>N-5) return;
	if(sum[u-1]>=t)
	{
		if(sum[u-1]==t)
		{
			for(int i=1;i<u;i++) printf("%d",s[i]);
			printf("\n");exit(0);
		}
		return ;
	}
	s[u]=x^1;f[u]=d[u-1];d[u]=f[u]+f[u-1];sum[u]=sum[u-1]+f[u];
	dfs(u+1,x^1);
	s[u]=x;f[u]=f[u-1];d[u]=d[u-1]+f[u];sum[u]=sum[u-1]+f[u];
	dfs(u+1,x);
	return ;
}
int main(){
	// freopen("code.in","r",stdin);
	// freopen("code.out","w",stdout);
	scanf("%d%d",&a,&b);t=a*b-1;
	f[0]=f[1]=1;sum[1]=1;d[1]=2;s[1]=1;
	dfs(2,1);
	// printf("%d %d\n",ans,sum[ans]);
	// if(t==sum[ans]) for(int i=1;i<=ans;i++) printf("%d",i%2);
    
    return 0;
}
/*
1134903168

*/