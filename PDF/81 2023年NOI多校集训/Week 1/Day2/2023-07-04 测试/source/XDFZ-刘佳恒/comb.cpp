#include<bits/stdc++.h>
using namespace std;
const int N=5e5+55;
int n,a[N],s[N],tot;
int f[N],mx[N],st[N];
int main() {
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n-3;i++) if(a[i]==a[i+2]&&a[i+1]==a[i+3]) s[++tot]=i;
	for(int i=1;i<=tot;i++) {
		int l=0,r=i;
		while(l<=r) {
			int mid=( ( l+r ) >>1 );
			if( s[mid]+3<s[i] ) st[i]=mid,l=mid+1;
			else r=mid-1;
		}
		//cout<<st[i]<<" ";
	}
	//puts("");
	for(int i=1;i<=tot;i++) {
		f[i]=mx[ st[i] ]+1;
		mx[i]=max( mx[i-1],f[i] );
	}
	printf("%d",mx[tot]*4);
	return 0;
}
/*
16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
