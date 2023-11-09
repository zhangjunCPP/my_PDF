#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b; read(a,b); int len=a*b-1;
	for(int i=1;i<=len;i++) putchar('0');
	return 0;
}

