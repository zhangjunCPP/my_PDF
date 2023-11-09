#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=110,mod=1e9+7;
int n,m,k;
struct edge{
	int x,y,d,s;
}e[N*2];int k_e=-1;
vector<int>E[N];
int ans,cl[N];
void dfs(int t){
	if(t>n){
		int s=1;
		// for(int i=1;i<=n;i++){
		// 	cout<<cl[i]<<" ";
		// }cout<<endl;
		for(int i=0;i<=k_e;i+=2){
			int x=e[i].x,y=e[i].y,d=e[i].d,sa=e[i].s;
			if(cl[x]!=cl[y])s*=d;
			else s*=sa;
			s%=mod;
		}
		ans+=s;
		// cout<<s<<endl;
		return;
	}
	for(int i=1;i<=min(n,k);i++){
		cl[t]=i;
		dfs(t+1);
		cl[t]=0;
	}
}
int ksm(int a,int b){
	int an=1;
	while(b){
		if(b&1)an=an*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return an;
}
void sol1(){
	cl[0]=1;
	ans=0;
	dfs(1);
	if(n<k){
		for(int i=k-n+1;i<=k;i++){
			ans=ans*i%mod;
		}
		for(int i=1;i<=n;i++){
			ans=ans*ksm(i,mod-2)%mod;
		}
	}
	printf("%lld\n",ans);
}
void sol(){
	scanf("%lld%lld%lld",&n,&m,&k);
	k_e=-1;
	for(int i=1;i<=m;i++){
		k_e++;
		scanf("%lld%lld%lld%lld",&e[k_e].x,&e[k_e].y,&e[k_e].d,&e[k_e].s);
		E[e[k_e].x].push_back(k_e);
		k_e++;
		e[k_e]=e[k_e-1];swap(e[k_e].x,e[k_e].y);
		E[e[k_e].x].push_back(k_e);
	}
	sol1();
}
signed main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int tt;scanf("%lld",&tt);
	while(tt--){sol();}
	return 0;
}