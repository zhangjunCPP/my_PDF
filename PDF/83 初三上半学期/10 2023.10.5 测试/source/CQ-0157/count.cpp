#include<cstdio>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int tot=0;
	do stk[++tot]=x%10+48,x=x/10;while(x);
	for(;tot;tot--)putchar(stk[tot]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}
template<typename T>T max(T x,T y){return x>y?x:y;}
int T,n;
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(T);
	for(;T--;){
		read(n);int ans=0;
		for(int x=1;x<=n*n;++x){
			int cnt=0,gh=x/n;
			if(x%n!=0)gh++;
			for(int i=gh;i*i<=x;++i){
				if(x%i==0){
					if(i*i==x)cnt++;
					else cnt+=2;
				}
			}
			ans+=cnt*cnt;
		}
		write(ans,'\n');
	}
	return 0;
}
