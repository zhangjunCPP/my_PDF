#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6+10,M=N*2,mod=1e9+7;

int head[N],ver[M],nxt[M],tot=1;
void add(int x,int y){
	ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;
}

ll power(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}


int n,m,deg[N],c[N],d[N],f[N][20];
void dfs(int x,int fa){
	d[x]=d[fa]+1,f[x][0]=fa;
	for(int i=1;i<=19;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=19;i>=0;i--)if(d[f[x][i]]>=d[y])x=f[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}

int get_dist(){
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j||c[i]!=c[j])continue;
			int p=lca(i,j);
			ans=max(ans,d[i]+d[j]-2*d[p]);
		}
	return ans;
}
void solve1(){
	int ans=0;
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++)
			c[j+1]=i>>j&1;
		ans+=get_dist();
	}
	printf("%d\n",ans); 
	exit(0);
}
void solve2(){
	printf("%lld\n",power(2,n-1));
}
void solve3(){
	printf("%lld\n",power(2,n)*2%mod);
	exit(0);
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	bool flag=1;
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		deg[x]++,deg[y]++;
		add(x,y),add(y,x);
		if(x>y)swap(x,y);
		if(x!=i||y!=i+1)flag=0;
	}
	if(n<=10)solve1();
	else if(flag)solve2();
	else if(deg[1]==n-1)solve3();
	else solve1();
	return 0;
}
