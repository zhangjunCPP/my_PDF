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
int qpow(int a,int b) {
	int res=1;
	while(b) {
		if(b&1) res=res*a/*%mod*/;
		b>>=1;
		a=a*a/*%mod*/;
	}
	return res;
}
bitset<N>e[N],stk[N],zero;
int line[N][N],top[N],sum[N],vis[N];
int p,k;
signed main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&p,&k);
	int n=qpow(p,k);
	printf("%d\n",n*(n-1)/p/(p-1));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			e[i][j]=1;
		}
		e[i][i]=0;
		sum[i]=n-1;
	}
	for(int i=1;i<=n;i++) {
		int tot=sum[i]/(p-1);
		for(int k=1;k<=tot;k++) stk[k][i]=1,line[k][++top[k]]=i;
		for(int j=i+1;j<=n;j++) {
			for(int k=1;k<=tot;k++) {
				if((stk[k]&e[j])==stk[k]&&top[k]<p) {
					stk[k][j]=1;
					line[k][++top[k]]=j;
					break;
				}
			}
		}
		for(int k=1;k<=tot;k++) {
			for(int j=1;j<=top[k];j++) {
				e[line[k][j]]^=stk[k];
				sum[line[k][j]]-=p-1;
				printf("%d ",line[k][j]-1);
			}
			printf("\n");
			top[k]=0;
			stk[k]&=zero;
		}
		for(int i=1;i<=n;i++)vis[i]=0;
//		printf("://%d\n",i);
	}
	
	return 0;
}
