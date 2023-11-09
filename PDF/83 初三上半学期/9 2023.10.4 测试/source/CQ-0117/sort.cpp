/*
ûɶ˼· 
*/

#include<cstdio>
#include<algorithm>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	char y[14];int tot=0;
	do y[++tot]=x%10+48,x/=10;while(x);
	for(;tot;tot--)putchar(y[tot]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}

signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	
	return 0;
}
