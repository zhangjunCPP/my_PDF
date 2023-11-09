#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5;
ll n,k,L,b[N];
double d[N],ans[N];
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&L);
	for(int i=1;i<=n;i++){
		char c[10];
		scanf("%lf%lld%s",&d[i],&b[i],c);
		if(c[0]=='L')ans[b[i]]+=d[i];//left
		else ans[b[i]]+=L-d[i];//right
	}
	for(int i=0;i<k;i++){
		printf("%.1lf\n",ans[i]);
	}
	return 0;
}

