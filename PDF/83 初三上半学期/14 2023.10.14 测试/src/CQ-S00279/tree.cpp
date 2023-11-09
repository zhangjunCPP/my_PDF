#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+2,P=998244353;
vector<ll>v;
map<vector<ll>,ll>mp;
ll n,f[N];
struct ROSE{ll x,y;}t[N];
void dfs(ll i){
	if(i==n){
		mp[v]++;
		return ;
	}
	if(!f[t[i].x]&&!f[t[i].y]){
		vector<ll>tmp=v;
		v.push_back(t[i].x);
		f[t[i].x]=1;
		dfs(i+1);
		f[t[i].x]=0;
		v=tmp;
		v.push_back(t[i].y);
		f[t[i].y]=1;
		dfs(i+1);
		f[t[i].y]=0;
		v=tmp;
	}else{
		dfs(i+1);
	}
}
int main(){//40
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	bool A=1,B=1;
	for(ll i=1;i<n;i++){
		scanf("%lld%lld",&t[i].x,&t[i].y);
		if(t[i].x!=1||t[i].y!=i+1) A=0;
		if(t[i].x!=i||t[i].y!=i+1) B=0;
	}
	if(A){
		printf("%lld",n);
		return 0;
	}
	if(B){
		f[0]=f[1]=1;
		for(ll i=2;i<=n;i++){
			f[i]=(f[i-1]+f[i-2])%P;
		}
		printf("%lld",f[n]);
		return 0;
	}
	if(n<=10){
		dfs(1);
		printf("%lld",(ll)mp.size()%P);
	}
	
	return 0;
}

