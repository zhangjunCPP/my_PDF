#include<cstdio>
int n;
int a[5555];
long double add[5555];
long double ch[5555];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++) add[i]=a[i]/(long double)a[i-1];
	for(int i=2;i<=n;i++) ch[i]=add[i]-add[i-1];
	for(int i=2;i<=n;i++) printf("%Lf\n",ch[i]);
	return 0;
}
