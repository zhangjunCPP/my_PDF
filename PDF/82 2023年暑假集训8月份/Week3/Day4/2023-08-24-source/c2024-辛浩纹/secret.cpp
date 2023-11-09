#include<cstdio>
#include<vector>
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
const int mod=65535;
int T,k,ans=1;
int fast_pow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=x*x%mod)if(y&1)res=res*x%mod;
	return res;
}
int vis[20];
std::vector<int>dick;int siz;
void dfs(int x,int sum){
	if(x>=siz){
		(ans*=sum)%=mod;
		return;
	}
	for(int i=0;i<siz;++i){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,(sum+fast_pow(256,x)*dick[i]%mod)%mod);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	read(T);
	while(T--){
		dick.clear();
		read(k);ans=1;
		if(k==1){
		//	write(1);
			int x,y;read(x,y);
			int io=1;
			for(int i=2;i<=y;++i)(io*=i)%=mod;
			int yu=0;
			for(int i=0;i<y;++i)(yu+=fast_pow(256,i)*x%mod)%=mod;
			write(fast_pow(yu,io),'\n');
		}
		else{
			for(int i=1;i<=k;++i){
				int x,y;read(x,y);
				for(int op=1;op<=y;++op)dick.emplace_back(x);
			}
			siz=dick.size();
			dfs(0,0);
			write(ans,'\n');
		}
	}
	return 0;
}
