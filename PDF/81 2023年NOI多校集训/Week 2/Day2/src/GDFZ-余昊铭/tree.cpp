#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
const int maxn=10000010;
const int maxm=1010;
inline int read(){
	int x=0,fl=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-1')fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fl;
}
int n,ans;
int head[maxn],tot;
struct nd{
	int nxt,to;
}e[maxn<<1];
void add(int u,int v){
	e[++tot]={head[u],v};
	head[u]=tot;
}
int pw[maxn];
int f[maxm][maxm],siz[maxm][maxm];
void dfs(int u,int fa){
	siz[u][1]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa){
			dfs(v,u);
			for(int j=1;j<=n;j++){
				if(!siz[u][j])break;
				siz[u][j]+=siz[u][j-1];
				for(int k=1;k<=n;k++){
					if(!siz[v][k])break;
					siz[v][k]+=siz[v][k-1];
					int s=(pw[siz[u][j]+siz[v][k]]-pw[siz[u][j-1]+siz[v][k]]-pw[siz[u][j]+siz[v][k-1]]+pw[siz[u][j-1]+siz[v][k-1]]+mod+mod)%mod;
					ans+=s*(j+k-1)%mod;ans%=mod;
					cout<<s<<" "<<j+k-1<<" "<<ans<<"\n";
					siz[v][k]-=siz[v][k-1];
				}
				siz[u][j]-=siz[u][j-1];
			}
			for(int j=1;j<=n;j++)siz[u][j]+=siz[v][j-1];
		}
	}
	cout<<u<<" "<<ans<<"\n";
}
void s1(){
	dfs(1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<siz[i][j]<<" ";
		cout<<"\n";
	}
	printf("%lld\n",ans*2);
}

signed main(){
	freopen("ex_tree2.in","r",stdin);
//	freopen("tree.out","w",stdout);

	n=read();pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v);add(v,u);
	}
	if(n<=1000)s1();
}
