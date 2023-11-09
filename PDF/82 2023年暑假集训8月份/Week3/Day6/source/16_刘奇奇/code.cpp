#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template<typename T> void Read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
		if(f) x=-x;
	}
	template<typename T,typename ...Args> void Read(T &x,Args &...args){
		Read(x),Read(args...);
	}
	void Write(char x){ putchar(x); }
	template<typename T> void Write(T x){
		if(x<0) x=-x,putchar('-');
		int stk[50],top=0;
		do stk[++top]=x%10,x/=10; while(x);
		for(;top;top--) putchar(stk[top]^48);
	}
	template<typename T,typename ...Args> void Write(T x,Args ...args){
		Write(x),Write(args...);
	}
}
int a,b; 
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	IO::Read(a,b);
	for(int i=1;i<a;i++) putchar('1');
	for(int j=1;j<b;j++) putchar('0');
	return 0;
}

