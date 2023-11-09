#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lowbit(x) (x&-x)
const int N=2e5+5;
char s[N],t[N];
int S,T,k,q;
ull h[N],h1[N],h2[N];
int check(int l1,int r1,int l2,int r2) {
	return (h1[r1]-h1[l1-1]*h[r1-l1+1])==(h2[r2]-h2[l2-1]*h[r2-l2+1]);
}
signed main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d\n%s\n%d",&k,s+1,&q);
	S=strlen(s+1);
	h[0]=1;
	for(int i=1;i<=S;i++) h1[i]=h1[i-1]*131+s[i];
	for(int i=1;i<=2000;i++) h[i]=h[i-1]*131;
	while(q--) {
		int ans=0;
		scanf("\n%s",t+1);
		T=strlen(t+1);
		for(int i=1;i<=T;i++) h2[i]=h2[i-1]*131+t[i];
		for(int i=1;i<=S-T+1;i++) {
			int st,ed;
			int l=1,r=T;
			while(l<=r) {
				if(check(i,i+mid-1,1,mid)) l=mid+1;
				else r=mid-1;
			}
			st=r+1;
			l=1,r=T;
			while(l<=r) {
				if(check(i+mid-1,i+T-1,mid,T)) r=mid-1;
				else l=mid+1;
			}
			ed=l-1;
			if(ed-st<k) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
