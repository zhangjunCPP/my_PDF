#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e5+5;
char s[N];
int n;
ull h[N],H[N];
inline bool check(int l1,int r1,int l2,int r2) {
	return (H[r1]-H[l1-1]*h[r1-l1+1])==(H[r2]-H[l2-1]*h[r2-l2+1]);
}
void solve70_go() {
	h[0]=1;
	for(int i=1;i<=n;i++) H[i]=H[i-1]*131+s[i];
	for(int i=1;i<=n;i++) h[i]=h[i-1]*131;
	for(register int i=1;i<=n;++i) {
		int ans=0;
		for(register int len=1;len<=(n-i)/3;++len) {
			if(check(i,i+len-1,i+len,i+2*len-1)&&check(i,i+len-1,n-len+1,n))ans++;
		}
		printf("%d ",ans);
	}
}
signed main() {
	freopen("ccfc1.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n<=10000) solve70_go();
	return 0;
}
