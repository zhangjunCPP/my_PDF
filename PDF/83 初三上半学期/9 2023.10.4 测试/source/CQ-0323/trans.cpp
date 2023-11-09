//the code is from chenjh
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1000000007;
int n,m,k;
struct Edge{
	int u,v,d,s;
}e[105];
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].d,&e[i].s);
	if(n==2){
		int d=1,s=1;
		for(int i=1;i<=m;i++) d=(LL)d*e[i].d%mod,s=(LL)s*e[i].s%mod;
		printf("%d\n",int((((LL)k*k-k)%mod*d%mod+(LL)k*s%mod)%mod));
		return;
	}
	vector<int> v(n,1);
	int ans=0;
	while(v.back()<=k){
		int w=1;
		for(int i=1;i<=m&&w;i++) w=(LL)w*(v[e[i].u-1]==v[e[i].v-1]?e[i].s:e[i].d)%mod;
		ans=(ans+w)%mod;
		++v[0];
		for(int i=0;i<n-1;i++){
			if(v[i]>k) ++v[i+1],v[i]=1;
			else break;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}

