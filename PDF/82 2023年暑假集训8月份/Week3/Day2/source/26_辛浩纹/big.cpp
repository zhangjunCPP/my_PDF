#include<cstdio>
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
	char stk[50];int top=0;
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
template<typename T>void abs(T &a){if(a<0)a=-a;}
int n,m,q,x[1004],y[1004],vis[1004],du[1004];
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	read(n,m);
	for(int i=1;i<=m;++i)read(x[i],y[i]);
	read(q);
	for(;q--;){
		int ans=0;
		for(int i=1;i<=n;++i)scanf("%1d",&vis[i]);
		for(int i=0;i<(1<<m);++i){
			memset(du,0,sizeof(du));
			int flag=1;
			for(int j=1;j<=m;++j){
				if(vis[x[j]]&&vis[y[j]]&&(i>>(j-1)&1))
					du[x[j]]++,du[y[j]]++;
				if((i>>(j-1)&1)&&(!vis[x[j]]||!vis[y[j]]))flag=0;
			}
			for(int j=1;j<=n;++j)
				if(vis[j]&&du[j]<2)flag=0;
			ans+=flag;
		}
		write(ans,'\n');
	}
	return 0;
}