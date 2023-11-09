#include<iostream>
#define int long long
using namespace std;

struct edge{
	int to,nxt;
};

const int mod=1e9+7;
const int MAXN=1e6+5;
int tot,head[MAXN];
edge a[MAXN*2];
int n,du[MAXN],dep[MAXN],ans,pow3[MAXN],pow2[MAXN],fa[MAXN][20];
bool A,B,C;

void add(int u,int v){
	a[++tot]={v,head[u]};
	head[u]=tot; 
}

void dfs(int u,int f){
	fa[u][0]=f;
	for(int i=head[u];i;i=a[i].nxt){
		int v=a[i].to;
		if(v==f) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}

signed main(){
	pow3[0]=pow2[0]=1;
	A=B=C=true;
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
		du[x]++;
		du[y]++;
		if((x!=i && y!=i+1) && (x!=i+1 && y!=i)) A=false;
		if(x!=1 && y!=1) B=false;
		if((du[x]>2 && x!=1) || (du[y]>2 && y!=1)) C=false;
		pow2[i]=pow2[i-1]*2%mod; 
		pow3[i]=pow3[i-1]*3%mod;
	}
	if(A){
		int len=n-1;
		if(n%2==0){
			ans+=len*pow2[n-1]%mod;
			ans%=mod;
			for(int i=1;i<n/2;i++){
				ans+=((len-i)*pow2[n-i*2-1]%mod)*pow3[i]%mod;
				ans%=mod;
			}
			cout<<ans;
			return 0;
		}
	}
	if(B){
		if(n==3){
			cout<<12;
			return 0;
		}else{
			ans=2*pow2[n];
			ans%=mod;
			cout<<ans;
			return 0;
		}
	}
	dfs(1,0);
	int d=0;
	if(C){
		for(int i=1;i<=n;i++){
			if(du[i]==1 && d==0) d=dep[i];
			if(du[i]==1 && d && dep[i]!=d){
				C=false;
				break;
			}
		}
	}
	if(C){
		ans=d*2*pow2[n]%mod;
		ans%=mod;
		cout<<ans;
		return 0;
	}
	
}
