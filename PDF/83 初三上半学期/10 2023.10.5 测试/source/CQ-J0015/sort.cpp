#include <bits/stdc++.h>
using namespace std;
int a[700005],c[700005],d[700005],n,ans;
void sor(int l,int r){
	if(l>=r) return;
	int mid=(l+r)>>1,cnt1=0,cnt2=0;
	for(int i=l;i<=r;i++){
		ans++;
		if(a[i]<a[mid]) c[++cnt1]=a[i];
		if(a[i]>a[mid]) d[++cnt2]=a[i];
	}
	for(int i=1;i<=cnt1;i++) a[l+i-1]=c[i];
	for(int i=1;i<=cnt2;i++) a[l+cnt1+i]=d[i];
	sor(l,l+cnt1-1);
	sor(l+cnt1+1,r);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sor(1,n);
	cout<<ans;
	return 0;
} 
