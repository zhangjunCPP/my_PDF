/*
盲猜一波：打暴力找规律于是切下一道题  
3：15又切了回来。 
首先每组的棋子确定，说明所包含的组  
*/

#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
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
int p,k,n;
std::map<std::pair<int,int>,int>mp;
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(p,k);n=pow(p,k);
	if(k==1){
		write(p,'\n');
		for(int i=0;i<p;++i)write(i,' ');
	}
	else if(p==2){
		write(n*(n-1)/2,'\n');
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				write(i,' ',j,'\n');
	}
	return 0;
}
