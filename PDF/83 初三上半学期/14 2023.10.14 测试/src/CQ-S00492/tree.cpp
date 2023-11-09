#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define In inline
	#define ULL unsigned long long
	#define Re register
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define ff(a,b,i) for(int i=a;i<b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define ff_(a,b,i) for(int i=a;i>b;i--)
	const int inf=0x3f3f3f3f;
	const int INF=0x7f7f7f7f;
	const LL infll=0x3f3f3f3f3f3f3f3fll;
	const LL INFll=0x7f7f7f7f7f7f7f7fll;
	template<typename T>void read(T &x){
		x=0;
		bool fl=0;
		char ch=getchar();
		while(ch<'0'||'9'<ch){
			if(ch=='-')fl=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9'){
			x=x*10+(ch^48);
			ch=getchar();
		}
		x=fl?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

#define N 1000050
#define mod 998244353

typedef pair<int,int> Pi;

int n;

Pi eg[N];

int vis[N];

LL ans=0;

In void dfs(int pos){
	if(pos==n){
		ans++;
		return;
	}
	int u,v;
	tie(u,v)=eg[pos];
	if(vis[u]||vis[v])dfs(pos+1);
	else{
		vis[u]=1;
		dfs(pos+1);
		vis[u]=0;
		vis[v]=1;
		dfs(pos+1);
		vis[v]=0;
	}
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	int u,v;
	ff(1,n,i){
		read(u,v);
		eg[i]=Pi(u,v);
	}
	dfs(1);
	printf("%lld",ans%mod);
	return 0;
}

