#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15;
int n,Q,a[N];
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&Q);
	if( n<=100 ) {
		while(Q--) {
			int len; scanf("%d",&len);
			int ans=0;
			for(int i=1;i+len-1<=n;i++) {
				bitset<N> s;
				for(int j=i;j<=i+len-1;j++) {
					s[ a[j] ]=1;
				}
				for(int i=0;i<=n;i++) if( !s[i] ) { ans=max(ans,i); break; }
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	return 0;
}
