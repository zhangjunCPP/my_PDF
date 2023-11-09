#include<stdio.h>

const int N=5e5+5;
int n,a[N],ans;

int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) if(a[i]==a[i+2]&&a[i+1]==a[i+3]) {ans+=4;i+=3;}
	printf("%d",ans);
    return 0;
}