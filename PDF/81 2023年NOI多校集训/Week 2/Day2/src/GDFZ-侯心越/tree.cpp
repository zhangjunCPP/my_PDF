#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+5;
const int mod=1e9+7;
struct edge{
	int to,nxt;
}e[maxn<<1];
int head[maxn],len;
int a[maxn],n;

inline void init(){
	memset(head,-1,sizeof(head));
	len=0;
}
void add(int u,int v){
	e[++len].to=v;
	e[len].nxt=head[u];
	head[u]=len;
}

namespace Sub1{
	int poww[maxn];
	void solve(){
		poww[0]=1;
		for(int i=1;i<=n;i++) poww[i]=1ll*poww[i-1]*2%mod;
		int res=1ll*poww[n-2]*(n-1)%mod;
		for(int i=n-2;i>=1;i-=2){
			if(i==1) res=(res+n/2)%mod;
			else res=(res+(poww[i]-poww[i-2]+mod)%mod*(n-(n-i)/2)%mod)%mod;
		}
		res=(2ll*res)%mod;
		printf("%d\n",res);
	}
}
namespace Sub2{
	int qpow(int x,int y){
		int res=1;
		while(y){
			if(y&1) res=1ll*res*x%mod;
			x=1ll*x*x%mod;
			y>>=1;
		}
		return res;
	}
	void solve(){
		if(n==2) puts("2");
		else if(n==3) printf("%d\n",10);
		else printf("%d\n",qpow(2,n+1));
	}
}

int deg[maxn];

int main(){
	
	bool flag1=1;
	
	scanf("%d" ,&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		if(!((u==i&&v==i+1)||(u==i+1&&v==i))) flag1=0;
		deg[u]++;
		deg[v]++;
		add(u,v);
		add(v,u);
	}
	
	if(flag1) Sub1::solve();
	else if(deg[1]==n-1) Sub2::solve();
	
	return 0;
}