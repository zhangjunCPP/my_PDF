#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template<typename T> void read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
		if(f) x=-x;
	}
	template<typename T,typename ...Args> void read(T &x,Args &...args){
		read(x),read(args...);
	}
	template<typename T> void write(T x){
		if(x<0) putchar('-'),x=-x;
		short stk[50],top=0;
		do stk[++top]=x%10,x/=10; while(x);
		for(;top;top--) putchar(stk[top]^48);
	}
	void write(char x){ putchar(x); }
	template<typename T,typename ...Args> void write(T x,Args ...args){
		write(x),write(args...);
	}
}
int n,q;
int g(int sx,int sy,int tx,int ty){	return abs(sx-tx)+abs(sy-ty); }//Ö±½Ó×ß 
int g_up(int sx){ return sx+1; }//(0,j)->(n,n-j)
int g_down(int sx){ return n-sx+1; }//(n,n-j)->(0,j)
int g_left(int sy){ return sy+1; }//(i,0)->(i,n)
int g_right(int sy){ return n-sy+1; }//(i,n)->(i,0)
int ans[15];
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	IO::read(n,q);
	for(;q--;){
		int sx,sy,tx,ty; IO::read(sx,sy,tx,ty);
		ans[1]=g(sx,sy,tx,ty);
		ans[2]=g_up(sx)+g(n,n-sy,tx,ty);
		ans[3]=g_down(sx)+g(0,n-sy,tx,ty);
		ans[4]=g_left(sy)+g(sx,n,tx,ty);
		ans[5]=g_right(sy)+g(sx,0,tx,ty);
		ans[6]=g_up(sx)+g_left(n-sy)+g(n,n,tx,ty);
		ans[7]=g_up(sx)+g_right(n-sy)+g(n,0,tx,ty);
		ans[8]=g_down(sx)+g_left(n-sy)+g(0,n,tx,ty);
		ans[9]=g_down(sx)+g_right(n-sy)+g(0,0,tx,ty);
		ans[10]=g_left(sy)+g_up(sx)+g(n,n,tx,ty);
		ans[11]=g_left(sy)+g_down(sx)+g(0,0,tx,ty);
		ans[12]=g_right(sy)+g_up(sx)+g(n,n,tx,ty);
		ans[13]=g_right(sy)+g_down(sx)+g(0,0,tx,ty);
		sort(ans+1,ans+13+1);
		IO::write(ans[1],'\n');
	}
	return 0;
}
