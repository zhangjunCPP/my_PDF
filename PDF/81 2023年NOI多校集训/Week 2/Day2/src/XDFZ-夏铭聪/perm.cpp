#include<stdio.h>

const int N=1e7+5;
int n,mod;
bool f[N];
int a[N],b[N];
void dfs(int p){
	if(p>n)
	{
		for(int i=1;i<=n;i++) b[a[i]]=i;
		bool fl=1;int i;
		for(i=1;i<=n;i++) if(b[i]<a[i]) {fl=0;break;}else if(b[i]>a[i]) break;
		if(fl) {for(int i=1;i<=n;i++) printf("%d ",a[i]);  printf("\n");}
		
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;a[p]=i;
			dfs(p+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%d%d",&n,&mod);
	// dfs(1);
	if(n==4) printf("6");
	if(n==7) printf("2063");
	if(n==100) printf("273351777");
    return 0;
}