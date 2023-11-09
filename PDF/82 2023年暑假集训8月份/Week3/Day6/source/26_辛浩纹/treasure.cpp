#include<cstdio>
#include<algorithm>
#include<cstring>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	x<0?putchar('-'),x=-x:false;
	char stk[10];int top=0;
	do stk[++top]=x%10+48,x/=10;while(x);
	for(;top;top--)putchar(stk[top]);
}
template<typename T,typename ...Args>void read(T &a,Args &...args){read(a);read(args...);}
template<typename T,typename ...Args>void write(T a,Args ...args){write(a);write(args...);}
template<typename T>T min(T a,T b){return a>b?b:a;}
template<typename T,typename ...Args>T min(T a,T b,Args ...args){return min(a,min(b,args...));}
template<typename T>T max(T a,T b){return a>b?a:b;}
template<typename T,typename ...Args>T max(T a,T b,Args ...args){return max(a,max(b,args...));}
template<typename T>void swap(T &a,T &b){a^=b^=a^=b;}
template<typename T>T abs(T a){return a<0?-a:a;}
const int maxn=30;
int n,a[maxn],sum,ans[maxn],ANS=0x3f3f3f3f;
int vis[maxn],yu[maxn],dp[maxn],net[maxn];
int v[maxn],siz;
void dfs(int x,int cnt){
	if(sum-cnt<cnt*2)return;
	if(x>n){
//		for(int i=1;i<=n;++i)write(vis[i],' ');
		siz=0;int gh=0;
		for(int i=1;i<=n;++i){
			yu[i]=3;
			if(!vis[i])v[++siz]=i,gh+=a[i];
			else yu[i]=vis[i];
		}
		memset(dp,0,sizeof(dp));
		int oi=0,io=0;
		for(int i=1;i<=siz;++i){
			for(int j=0;j<i;++j)
				if(dp[v[j]]+a[v[i]]<=gh/2&&dp[v[i]]<dp[v[j]]+a[v[i]])
					dp[v[i]]=dp[v[j]]+a[v[i]],
					net[v[i]]=v[j];
			if(dp[v[i]]>oi){
				oi=dp[v[i]];
				io=v[i];
			}
		}
		for(int i=io;i;i=net[i])yu[i]=1;
		if(oi<=cnt&&cnt<=gh-oi&&gh-oi-oi<=ANS){
			ANS=gh-oi-oi;
			for(int j=1;j<=n;++j)ans[j]=yu[j];
		}
		return;
	}
	dfs(x+1,cnt);
	vis[x]=2;
	dfs(x+1,cnt+a[x]);
	vis[x]=0;
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)read(a[i]),sum+=a[i];
	dfs(1,0);
	for(int i=1;i<=n;++i)write(ans[i],' ');
	return 0;
}