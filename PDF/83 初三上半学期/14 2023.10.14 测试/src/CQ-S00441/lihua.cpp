#include<cstdio>
#include<cstring>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x; 
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int cnt=0;
	do stk[++cnt]=x%10+48,x/=10;while(x);
	for(;cnt;)putchar(stk[cnt--]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}
template<typename T>T min(T x,T y){return x<y?x:y;}
const int maxn=1e5+4;
int n,Q,len[maxn];
char jk[maxn][34];
signed main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i){
		scanf("%s",jk[i]+1);
		len[i]=strlen(jk[i]+1);
	}
	read(Q);
	for(;Q--;){
		int ans=0;
		char a[34];scanf("%s",a+1);int lp=strlen(a+1);
		for(int i=1;i<=n;++i){
			int j=1;
			for(;j<=min(len[i],lp);++j)if(a[j]!=jk[i][j])break;
			ans+=j;
			if(len[i]==lp&&j==lp+1)break;
		}
		write(ans,'\n');
	}
	return 0;
}
