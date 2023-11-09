#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lowbit(x) (x&-x)
const int N=2005;
int check(int x) {
	for(int i=2;i*i<=x;i++) if(x%i==0)return 0;
	return 1;
}
bitset<N>e;
signed main() {
//	freopen("bf.in","r",stdin);
//	freopen("bf.out","w",stdout);
	for(int p=2;p<=2000;p++) {
		if(!check(p)) continue;
		int sum=p;
		for(int k=1;sum<=2000;k++,sum*=p) {
			printf("%d %d %d\n",p,k,sum*(sum-1)/(p*(p-1)));
		}
	}
	return 0;
}
