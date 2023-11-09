/*
¸Ð¾õÊÇhash 
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
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
const int maxn=2e5+4;
int k,n,T,len;
char jk[maxn],op[maxn];
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(k);scanf("%s",jk+1);n=strlen(jk+1);
	read(T);
	for(;T--;){
		int ans=0;
		scanf("%s",op+1);len=strlen(op+1);
		for(int i=1;i+len-1<=n;++i){
			int st=-1,dick=i+len-1,ed=-1;
			for(int j=i;j<=dick;++j)if(jk[j]!=op[j-i+1]){st=j;break;}
			if(st!=-1){
				for(int j=dick;j>=i;--j)
					if(jk[j]!=op[j-i+1]){ed=j;break;}
			}
			if(st==-1||ed-st<k)ans++;
		}
		write(ans,'\n');
	}
	return 0;
}
