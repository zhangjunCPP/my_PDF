#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int MAXN=1e6+10;
int n;
int jc[MAXN];
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	for(int i=1;i<=MAXN;i++) jc[i]=jc[i-1]*i%mod;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int u,v; scanf("%d%d",&u,&v);
	}
	printf("%lld\n",jc[n]);
	return 0;
}
