#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define fi first
#define se second
#define pb push_back
#define pii pair<LL,LL>
#define mem(a,x) memset((a),(x),sizeof(a))

//#define long long int
#define LLL __int128

template<typename type>
inline void read(type &x)
{
    x=0;bool flag(0);char ch=getchar();
    while(!isdigit(ch)) flag=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    flag?x=-x:0;
}

template<typename type>
inline void write(type x,bool mode=1)//0为空格，1为换行
{
    x<0?x=-x,putchar('-'):0;static short Stack[50],top(0);
    do Stack[++top]=x%10,x/=10; while(x);
    while(top) putchar(Stack[top--]|48);
    mode?putchar('\n'):putchar(' ');
}

LL qsm(LL a,LL b,LL mod){
	LL ans=1,sum=a;
	while(b){
		if(b&1) ans=ans*sum%mod;
		sum=sum*sum%mod;
		b>>=1;
	}
	return ans;
}

const LL N=4e3+10,INF=1e18;

LL n,a[N],f[N][N][2],anss;

vector<LL> g[N];

bool bl[N];

LL mx;

void dfs(LL u,LL fa,LL root){
	bl[u]=true;
	if(u==root) return ;
	for(LL v:g[u]){
		if(v==fa) continue;
		dfs(v,u,root);
		f[u][a[u]][0]=max(f[u][a[u]][0],(LL)1);
		f[u][a[u]][1]=max(f[u][a[u]][1],(LL)1);
		for(LL i=1;i<=n;i++){
			f[u][i][0]=max(f[u][i][0],f[v][i][0]);
			f[u][i][1]=max(f[u][i][1],f[v][i][1]);
		}
		for(LL i=1;i<=a[u];i++){
			f[u][a[u]][0]=max(f[u][a[u]][0],f[v][i][0]+1);
		}
		for(LL i=a[u];i<=n;i++){
			f[u][a[u]][1]=max(f[u][a[u]][1],f[v][i][1]+1);
		}
	}
	mx=max(mx,f[u][a[u]][0]+f[u][a[u]][1]-1);
}

void solve(){
	read(n);
	for(LL i=1;i<n;i++){
		LL u,v;
		read(u);
		read(v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(LL i=1;i<=n;i++) read(a[i]);
	LL ans=INF;
	for(LL i=1;i<=n;i++){
		memset(bl,false,sizeof(bl));
		mx=0;
		for(LL j=1;j<=n;j++){
			if(bl[j]) continue;
			dfs(j,-1,i);
		}
		ans=min(mx,ans);
	}
	printf("%lld\n",ans);
}

int main(){
	LL T;
	T=1;
	while(T--){
		solve();
	}
}

