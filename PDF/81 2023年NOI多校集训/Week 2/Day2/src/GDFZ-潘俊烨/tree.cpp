#include<bits/stdc++.h>
#define int long long
#define _int __int128
#define y1 _
using namespace std;

static char buf[1000000],*p1=buf,*p2=buf;

inline int read(){
	char c=getchar();
	int res=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*f;
}

inline void write(int x){
	static char buf[20];
	static int len=-1;
	if(x<0){
		putchar('-');
		x=-x;
	}
	do{
		buf[++len]=x%10;
		x/=10;
	}
	while(x);
	while(len>=0){
		putchar(buf[len--]+48);
	}
}

const int maxn=1000005;
const int maxm=110;
const int mod=1e9+7;
const int inf=1e18;

int n;

int head[maxn],tot;

struct edge{
	int nxt,to;
}e[maxn<<2];

void add(int u,int v){
	e[++tot].nxt=head[u];
	e[tot].to=v;
	head[u]=tot;
}

int dep[maxn],siz[maxn];

int f[maxn][25];

int d,mx;

vector<int> a,b;

void init(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	siz[u]=1;
	for(int i=1;i<24;i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa){
			dep[v]=dep[u]+1;
			init(v,u);
			siz[u]+=siz[v];
		}
	}
}

void dfs(int dep1,int u,int fa){
	if(dep1>d){
		d=dep1;
		mx=u;
	}
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa){
			dfs(dep1+1,v,u);
		}
	}
}


int lca(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	for(int i=24;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
		}
		if(x==y){
			return x;
		}
	}
	for(int i=24;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

int get(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}

int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}

int pre[maxn],inv[maxn];

int C(int m,int n){
	if(m<n){
		return 0;
	}
	if(m==n){
		return 1;
	}
	return pre[m]*inv[n]%mod*inv[m-n]%mod;
}

void init1(){
	pre[1]=1;
	inv[1]=1;
	for(int i=2;i<=maxn;i++){
		pre[i]=pre[i-1]*i%mod;
		inv[i]=ksm(pre[i],mod-2);
	}	
}

void solve(){
	n=read();
	init1();
	for(int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	init(1,0);
	dfs(0,1,0);
	int k=mx;
	dfs(0,mx,0);
	d=d;
//	cout<<k<<" "<<mx<<" "<<d<<endl;
	if(mx!=k){
		a.push_back(mx);
		a.push_back(k);
		for(int i=2;i<=n;i++){
			if(i==mx||i==k){
				continue ;
			}
			int x1=get(i,1);
//			cout<<i<<" "<<x1<<endl;
			if(d%2==1){
				if(x1==d/2+1){
					a.push_back(i);
				}
			}
			if(d%2==0){
				if(x1==d/2){
					a.push_back(i);
				}
			}
		}
	}
	else{
		a.push_back(mx);
	}
//	cout<<a.back()<<" "<<b.back()<<endl;
//	int ans=0;
//	int cnt=a.size()*b.size();
//	cout<<a.size()<<" "<<b.size()<<" "<<cnt<<" ";
//	ans=(ans+cnt*d%mod*2%mod)%mod;
//	cout<<ans<<" "<<d<<endl;
//	int cnt1=(ksm(2,n)-2*cnt%mod+mod)%mod;
//	cout<<cnt1<<" "<<cnt1*(d-1)<<endl;
//	ans=(ans+cnt1*(d-1)%mod);
//	write(ans);
//	puts("");

	int ans=0;
	int cnt=C(a.size(),2);
	if(a.size()==1){
		cnt=1;
	}
//	cout<<cnt<<" "<<a.size()<<endl;
	ans=d*2%mod*cnt%mod*ksm(2,n-2)%mod;
	int cnt1=(ksm(2,n)-2*cnt%mod*ksm(2,n-2)%mod+mod)%mod;
//	cout<<cnt1<<endl;
	ans=(ans+cnt1*(d-1)%mod)%mod;
	write(ans);
	puts("");
	return ;
}

signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}


/*
6
1 2
2 3
3 4
4 5
3 6
*/

