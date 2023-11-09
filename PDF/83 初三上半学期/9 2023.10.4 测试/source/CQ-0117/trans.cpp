#include<cstdio>
#include<algorithm>
#define int long long
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
const int mod=1e9+7;
int T,n,m,k,x[104],y[104],di[104],sa[104]; 
signed main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	read(T);
	for(;T--;){
		read(n,m,k);
		for(int i=1;i<=m;++i)read(x[i],y[i],di[i],sa[i]);
		if(n==2){
			int same=1,diff=1;
			for(int i=1;i<=m;++i)same=same*sa[i]%mod,diff=diff*di[i]%mod;
			write((k*(k-1)%mod*diff%mod+k*same%mod)%mod,'\n');
		}
		else if(n==5||n==6||n==8||n==10){//只有全部不同才有贡献 
			
		}
	}
	return 0;
}
