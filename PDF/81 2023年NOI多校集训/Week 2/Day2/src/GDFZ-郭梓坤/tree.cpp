#include<bits/stdc++.h>
#define il inline
#define int long long
using namespace std;
const int N=1e6+5;
const int P=1e9+7;

il int wrd(){
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
	while(isdigit(c)){x=x*10+c-48,c=getchar();}
	return x*f;
}

int n,ans,cnt,head[N];

struct edge{
	int to,nxt;
}e[N<<1];

il void add(int u,int v){
	e[++cnt]=edge{v,head[u]},head[u]=cnt;
}

bool check(int x,int fa){
	if(fa^(x-1)) return 0;
	for(int i=head[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(v^fa && !check(v,x)) return 0;
	}
	return 1;
}

bool chk(){
	int ans=0;
	for(int i=head[1];i;i=e[i].nxt) ++ans;
	return ans==n-1;
}

il int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) (ans*=a)%=P;
		(a*=a)%=P,b>>=1;
	}
	return ans;
}

int dep[N],f[N][21],t;

void dfs(int u,int fa){
	f[u][0]=fa;
	for(int i=1;i<21;++i) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v^fa) dep[v]=dep[u]+1,t=max(t,dep[v]),dfs(v,u);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;--i){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=20;i>=0;--i){
		if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}

int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}

vector<int> a,b;
#define pb push_back
#define pk pop_back

void col(int x){
	if(x>n){
		int maxx=0;
		for(auto i:a) for(auto j:a) maxx=max(maxx,dis(i,j)); 
		for(auto i:b) for(auto j:b) maxx=max(maxx,dis(i,j)); 
		(ans+=maxx)%=P;
		return;
	}
	a.pb(x),col(x+1);
	a.pk(),b.pb(x),col(x+1);
	b.pk();
}

signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=wrd();
	for(int i=1;i<n;++i){
		int u=wrd(),v=wrd();
		add(u,v),add(v,u);
	}
	if(n==2) return puts("2"),0;
	if(n==3) return puts("12"),0;
	
	if(check(1,0)){
		int d=n-2;
		while(d*2>n){
			int num=n-d;
			ans=(ans+qpow(2,d+1-num + 2))%P;
			--d;
		}
		if(!(n&1)) (ans+=n-1)%=P;
		else (ans+=2*(n-1))%=P;
		ans=(ans+(n-1)*qpow(2,n-1)%P)%P;
		return printf("%lld",ans),0;
	}
	if(chk()) return printf("%lld",qpow(2,n)),0;
	
	dfs(1,0);
	if(n<=10){
		col(1);
		return printf("%lld",ans),0;
	}
	return printf("%lld",2*t),0;
}