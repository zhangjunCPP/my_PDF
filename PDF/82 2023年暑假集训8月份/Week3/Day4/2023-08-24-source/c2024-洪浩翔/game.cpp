/*
Sakurajima Mai,
Eriri Spencer,
Izumi Sagiri,
Keqing,
Hu tao,
Ganyu
say,"With our sincere wishes to HHX: never to debug code"
*/

#include<bits/stdc++.h>
#define int long long
const int QWQ=2e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} 
struct node{ int id,val; } a[QWQ];
int n,ut[QWQ],ct,ans; 
inline void get_sub1(){
	printf("%lld\n",n*(n-1)/2);
	for (int i=n;i;i--) printf("%lld ",i);
	exit(0);
}
inline void get_sub2(){
	printf("%lld\n",a[1].val*(n-1));
	for (int i=2;i<=n;i++) printf("%lld ",i);
	printf("1");
	exit(0);
}
inline bool cmp(node x,node y){
	if (x.val==y.val) return x.id<y.id;
	return x.val>y.val;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(); bool fl1=1,fl2=1;
	for (int i=1;i<=n;i++){
		a[i].val=read(),a[i].id=i;
		if (a[i].val!=i) fl1=0;
		if (a[i].val!=n+1-i) fl2=0;
	}
	if (fl1) get_sub1();
	else if (fl2) get_sub2();
//	else if (n<=10) get_sub3();
	else{
		sort(a+1,a+n+1,cmp);
		int r=n,rr=n; 
		for (int i=1;i<=n;i++){
			int l=a[i].id;
			if (l>r) continue;
			ans+=(r-l)*a[i].val;
			for (int j=1,k=l+1;j<=r-l&&k<=rr;j++,k++)
				ut[++ct]=k;
			rr-=(rr-l);
			ut[++ct]=a[i].id;
			r=l; rr--;
		} 
		printf("%lld\n",ans);
		for (int i=1;i<=ct;i++)
			printf("%lld ",ut[i]);
	}
	return 0;
} 
/*
10
2 2 1 24 13 15 20 10 29 29
*/
