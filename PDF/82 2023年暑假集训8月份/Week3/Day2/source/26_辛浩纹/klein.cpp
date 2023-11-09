#include<cstdio>
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
template<typename T>int abs(T a){return a<0?-a:a;}
int n,q;
int dis(int x,int y,int xx,int yy){return abs(x-xx)+abs(y-yy);}
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	read(n,q);
	while(q--){
		int x,y,xx,yy;read(xx,yy,x,y);
		int ans=dis(x,y,xx,yy);
		ans=min(ans,dis(x,y,0,y)+1+dis(xx,yy,n,n-y));
		ans=min(ans,dis(x,y,n,y)+1+dis(xx,yy,0,n-y));
		ans=min(ans,dis(x,y,x,0)+1+dis(xx,yy,x,n));
		ans=min(ans,dis(x,y,x,n)+1+dis(xx,yy,x,0));
		ans=min(ans,dis(x,y,0,y)+1+dis(n,n-y,n,0)+1+dis(n,n,xx,yy));
		ans=min(ans,dis(x,y,0,y)+1+dis(n,n-y,n,n)+1+dis(n,0,xx,yy));
		ans=min(ans,dis(x,y,n,y)+1+dis(0,n-y,0,0)+1+dis(0,n,xx,yy));
		ans=min(ans,dis(x,y,n,y)+1+dis(0,n-y,0,n)+1+dis(0,0,xx,yy));
		write(ans,'\n');
	}
	return 0;
}
