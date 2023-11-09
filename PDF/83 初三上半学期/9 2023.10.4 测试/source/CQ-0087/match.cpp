#include<bits/stdc++.h>
using namespace std;
const int N=5e5+55;
int k,q;
char s[N],p[N];
signed main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&k); cin>>(s+1); scanf("%d",&q);
	int n=strlen(s+1);
	while(q--) {
		cin>>(p+1); int m=strlen(p+1);
		if(n<m) { puts("0"); continue; }
		int ans=0;
		for(int be=1;be+m-1<=n;be++) {
			int ll=0x3f3f3f3f,rr=0;
			for(int i=be;i<=be+m-1;i++) {
				if(s[i]!=p[i-be+1]) ll=min(ll,i), rr=max(rr,i);
			} 
//			cout<<be<<" "<<ll<<" "<<rr<<endl;
			if(!rr||rr-ll<k) ans++;
		} printf("%d\n",ans);
	}
	return 0;
}
/*
2
baccbcbabc
7
a
abc
aaa
bbb
abbb
acbbc
iamasuperlongstring
*/
