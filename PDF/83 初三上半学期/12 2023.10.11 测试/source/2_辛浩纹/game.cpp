#include<cstdio>
#include<vector>
#include<algorithm>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	x<0?putchar('-'),x=-x:false;
	char stk[104];int top=0;
	do stk[++top]=x%10+48,x/=10;while(x);
	for(;top;top--)putchar(stk[top]);
}
template<typename T,typename ...Args>void read(T &a,Args &...args){read(a);read(args...);}
template<typename T,typename ...Args>void write(T a,Args ...args){write(a);write(args...);}
template<typename T>T min(T a,T b){return a>b?b:a;}
template<typename T,typename ...Args>T min(T a,T b,Args ...args){return min(a,min(b,args...));}
template<typename T>T max(T a,T b){return a>b?a:b;}
template<typename T,typename ...Args>T max(T a,T b,Args ...args){return max(a,max(b,args...));}
template<typename T>void Swap(T &a,T &b){a^=b^=a^=b;}
template<typename T>T abs(T a){return a<0?-a:a;}
const int maxn=1e5+4;
int T,n,m,k;
char jk[maxn];
std::vector<int>E[maxn];
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(T);
	for(;T--;){
		read(n,m,k);
		for(int i=1;i<=n;++i)E[i].clear();
		scanf("%s",jk);
		for(int i=1;i<=m;++i){
			int x,y;read(x,y);
		}
		write(jk[(m-n+1)%k]=='P'?'G':'P','\n');
	}
	return 0;
}
