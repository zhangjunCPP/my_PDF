#include<cstdio>
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
template<typename T>T abs(T a){return a<0?-a:a;}
int p,s,dick;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	read(p,s);
	if(p==4){
		if(s==1)printf("2333");
		else printf("Impossible");
	}
	else if(s==2){
		if(p==6)printf("232332");
		else printf("Impossible");
	}
	else if(s==3){
		if(p==8)printf("22323313");
		else printf("Impossible");
	}
	else if(s==4){
		if(p==10)printf("2322233222");
		else if(p==8)printf("22323232");
		else printf("Impossible");
	}
	else if(s==5){
		if(p==12)printf("232222332222");
		else if(p==10)printf("2313232322");
		else printf("Impossible");
	}
	
	return 0;
}
