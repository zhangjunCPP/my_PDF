#include<bits/stdc++.h>
const int QWQ=7e5+5;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
} long long Eriri;
int n,a[QWQ],b[QWQ];
void dfs(int l,int r){
	if (l==r||l>r) return ;
	int mid=l+((r-l+2)>>1)-1;
	for (int i=l;i<=r;i++) a[i]=b[i];
	int cnt=l-1; Eriri+=r-l+1;
	for (int i=l;i<=r;i++)
		if (a[i]<a[mid]) b[++cnt]=a[i];
	b[++cnt]=a[mid]; int ff=cnt;
	if (cnt==r) goto that; 
	for (int i=l;i<=r;i++)
		if (a[i]>a[mid]) b[++cnt]=a[i];
//	cout<<l<<' '<<r<<' '<<mid<<'\n';
//	for (int i=1;i<=n;i++)
//		if (i==ff) cout<<':'<<' ';
//		else cout<<b[i]<<' '; puts("");
	that:;
	dfs(l,ff-1),dfs(ff+1,r);
}
void work(){
	for (int i=1;i<=n;i++) b[i]=a[i];
	dfs(1,n);
}
void rock(int l,int r){
	if (l==r||l>r) return ;
	int mid=l+((r-l+2)>>1)-1;
	Eriri+=r-l+1;
	rock(l,mid-1);
	rock(mid+1,r); 
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n=read(); bool fl=1;
	for (int i=1;i<=n;i++){
		a[i]=read();
		if (a[i]!=i) fl=0;
	}
	if (fl){ rock(1,n); printf("%lld",Eriri); return 0; }
	work(); printf("%lld",Eriri);
	return 0;
}
/*
10
5 6 7 1 8 3 2 4 9 10
实际上和数的唯一关系就是它往下了几层 
*/
