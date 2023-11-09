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
template<typename T>T abs(T a){return a<0?-a:a;}
int n,flag1=1,flag2=1;
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	read(n);
	for(int i=1;i<n;++i){
		int u,v;read(u,v);
		if(u!=i||v!=i+1)flag1=0;
		if(u!=1||v!=i+1)flag2=0;
	}
	if(flag1){
		if(n%2==1){
			for(int i=1;i<=n/2;++i){
				int dick=n-i;
				if(dick%2==1)write(i+(dick+1)/2,'\n');
				else write(i+dick/2,'\n');
			}
			write(1,'\n');
			for(int i=n/2+2;i<=n;++i){
				int dick=i-1;
				if(dick%2==1)write(i/2,'\n');
				else write(dick/2,'\n');
			}
		}
		else{
			for(int i=1;i<=n/2;++i){
				int dick=n-i;
				if(dick%2==1)write(i+(dick+1)/2,'\n');
				else write(i+dick/2,'\n');
			}
			for(int i=n/2+1;i<=n;++i){
				int dick=i-1;
				if(dick%2==1)write(i/2,'\n');
				else write(dick/2,'\n');
			}			
		}
	}
	else if(flag2){
		write(2,'\n');
		for(int i=2;i<=n;++i)write(1,'\n');
	}
	else{
		
	}
	return 0;
}