#include <cstdio>
#include <initializer_list>
using ll=long long;
constexpr int N=100,M=1e9+7;
int tot,Ch,n,m,k,T,x,y,i,j,hd[N],col[N],to[N+1<<1],nxt[N+1<<1],es[N+1<<1],ed[N+1<<1];
bool flag_tree,v[N][N];
ll mps[N][N],mpd[N][N],ANS0,inv[N],f[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
inline ll C(const int&n,const int&m){
	ll ans=1;
	for(int i=1;i<=m;i++)ans=ans*(i+n-m)%M*inv[i]%M;
	return ans;
}
inline void add(const int&x,const int&y){
	// printf("add: %d %d %lld %lld\n",x,y,mps[x][y],mpd[x][y]);
	nxt[++tot]=hd[x];
	hd[x]=tot;
	to[tot]=y;
	es[tot]=mps[x][y];
	ed[tot]=mpd[x][y];
	nxt[++tot]=hd[y];
	hd[y]=tot;
	to[tot]=x;
	es[tot]=mps[x][y];
	ed[tot]=mpd[x][y];
}
void dfs(const int&x,const int&fa){
	int i;
	f[x]=1;
	for(i=hd[x];i;i=nxt[i]){
		if(to[i]!=fa){
			// printf("%d->%d\n",x,to[i]);
			dfs(to[i],x);
			f[x]=f[x]*f[to[i]]%M*(es[i]+ed[i]*(k-1))%M;
		}
	}
	// printf("%d %lld\n",x,f[x]);
}
void dfs_BF(const int&x,const int&fa){
	int i;
	for(i=hd[x];i;i=nxt[i]){

	}
}
inline void solve_tree(){
	dfs(1,0);
	w(f[1]*k%M*ANS0%M);
	putchar(10);
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	inv[1]=1;
	for(i=2;i<N;i++)inv[i]=(M-M/i*inv[M%i]%M)%M;
	r(T);
	while(T--){
		r(n,m,k);
		tot=0;
		__builtin_memset(hd+1,0,n<<2);
		if(k>n){
			ANS0=C(k,n);
			k=n;
		}
		else ANS0=1;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)v[i][j]=0;
		while(m--){
			r(x,y,i,j);
			if(!v[x][y]){
				v[x][y]=v[y][x]=true;
				mpd[x][y]=mpd[y][x]=x!=y;
				mps[x][y]=mps[y][x]=1;
			}
			mpd[y][x]=mpd[x][y]=mpd[x][y]*i%M;
			mps[y][x]=mps[x][y]=mps[x][y]*j%M;
		}
		m=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)if(v[i][j]&&!mps[i][j]&&!mpd[i][j])break;
			if(v[i][i]){
				ANS0=ANS0*mps[i][i]%M;
				mps[i][i]=1;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<i;j++){
				if(v[i][j]){
					add(j,i);
					m++;
				}
			}
		}
		flag_tree=m==n-1;
		if(i<=n){
			putchar(48);
			putchar(10);
			continue;
		}
		if(flag_tree){
			solve_tree();
			continue;
		}
		col[1]=1;
		dfs_BF(1,0);
	}
	return 0;
}