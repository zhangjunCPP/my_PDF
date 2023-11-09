#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
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
const int maxn=1004;
int id,op,n,p[maxn],Q;
__int128 ls,ans;
int val[maxn][maxn];
void decode(int &l,int &r,int &k,int testop){
	ls%=19260817;
	if(testop){
		l^=ls;l=(l%n+n)%n+1;
		r^=ls;r=(r%n+n)%n+1;if(l>r)std::swap(l,r);
		k^=ls;
		k=(k%min(r-l+1,100ll))+1;
	}
}
int l,r,k;
std::vector<int>hutao;
void dfs(int x,int size){
	if(size>k)return;
	if(x>r&&size==k){
		__int128 cnt=0;
		for(auto x:hutao)
			for(auto y:hutao)
				cnt+=val[x][y];
		for(auto x:hutao)write(x,' ');
		write('\n');
		ans=max(ans,cnt/2);
		return;
	}
	if(x>r)return;
	dfs(x+1,size);
	if(size<k){
		hutao.emplace_back(p[x]);
		dfs(x+1,size+1);
		hutao.pop_back();
	}
}
signed main(){
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout);
	read(id,op,n);
	for(int i=1;i<n;++i){
		int x,y,V;read(x,y,V);
		val[x][y]=V;val[y][x]=V;
	}
	for(int i=1;i<=n;++i)read(p[i]);
	read(Q);
	for(;Q--;){
		read(l,r,k);
		decode(l,r,k,op);
		hutao.clear();
		ans=0;
		dfs(l,0);
		write(ans,'\n','\n');
		ls=ans;
	}
	return 0;
}
