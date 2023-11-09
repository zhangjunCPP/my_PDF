#include<bits/stdc++.h>
using namespace std;
const int N=7e5+75;
int n,a[N];
int ans=0;
int b[N];
int le[N],ri[N];
void solve(int l,int r) {
	int len=r-l+1;
//	for(int i=l;i<=r;i++) printf("%d ",a[i]);
//	puts("");
	if(len<=1) return ;
	int mid=a[l-1+(int)ceil( len/2.0 )];
//	cout<<mid<<" ";
	int tot1=0,tot2=0;
	for(int i=l;i<=r;i++) {
		ans++;
		if(a[i]<mid) le[++tot1]=a[i];
		else if(a[i]>mid) ri[++tot2]=a[i];
	} //cout<<l<<" "<<r<<" "<<mid<<endl;
//	for(int i=1;i<=tot1;i++) cout<<le[i]<<" ";
//	puts("");
//	for(int i=1;i<=tot2;i++) cout<<ri[i]<<" ";
//	puts("");
	for(int i=1;i<=tot1;i++) a[l+i-1]=le[i];
	a[l+tot1]=mid;
	for(int i=1;i<=tot2;i++) a[l+tot1+i]=ri[i];
//	for(int i=l;i<=r;i++) cout<<a[i]<<" ";
//	puts("");
	solve(l,l+tot1-1); solve(l+tot1+1,r);
} 
signed main() {
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	solve(1,n); 
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//	puts("");
	printf("%d\n",ans);
	return 0;
}
/*
5
4 3 5 1 2
*/
