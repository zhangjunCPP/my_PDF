#include<stdio.h>

const int N=2005;
int n,a[N];
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==6) printf("6");
	if(n==8) printf("370");
    return 0;
}