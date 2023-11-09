#include<cstdio>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x; 
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int cnt=0;
	do stk[++cnt]=x%10+48,x/=10;while(x);
	for(;cnt;)putchar(stk[cnt--]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}
const int maxn=1e6+4,mod=998244353;
int n,x[maxn],y[maxn];
bool flag1=1,flag2=1;
bool vis[maxn];int ans=0;
void dfs(int o){
	if(o>=n){
		ans++;
		if(ans>=mod)ans-=mod;
		return;
	}
	if(!vis[x[o]]&&!vis[y[o]]){
		vis[x[o]]=1;
		dfs(o+1);
		vis[x[o]]=0;
		vis[y[o]]=1;
		dfs(o+1);
		vis[y[o]]=0;
	}
	else dfs(o+1);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	for(int i=1;i<n;++i){
		read(x[i],y[i]);
		if(x[i]!=1||y[i]!=i+1)flag1=0;
		if(x[i]!=i||y[i]!=i+1)flag2=0;
	}
	if(flag1)write(n);
	else{
		dfs(1);
		write(ans); 
	}
	return 0;
}
