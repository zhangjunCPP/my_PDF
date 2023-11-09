#include<cstdio>
#include<stack>
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
const int maxn=2e5+4;
int n,a[maxn],flag1=1,flag2=1,sum,ans;
int vis[maxn];
std::stack<int>s;
int jk[maxn],op[maxn];
void dfs(int cnt,int sum){
//	write(cnt,' ',sum,'\n');
	if(cnt>n){
//		write('\n','\n','\n','\n');
		if(sum>ans){
			ans=sum;
			for(int i=1;i<=n;++i)op[i]=jk[i];
		}
		return;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			vis[i]=1;
			int yu=sum;std::vector<int>dick;
			while(s.size()&&i<s.top())yu+=a[i],dick.emplace_back(s.top()),s.pop();
			s.push(i);
			jk[cnt]=i;
			dfs(cnt+1,yu);
			vis[i]=0;
			s.pop();
			for(int j=dick.size()-1;j>=0;--j)s.push(dick[j]);
		}
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);sum+=a[i];
		if(a[i]!=i)flag1=0;
		if(a[i]!=n-i+1)flag2=0;
	}
	if(flag1){
		write(sum-n,'\n');
		for(int i=n;i>=1;--i)write(i,' ');
	}
	else if(flag2){
		write(n*(n-1),'\n');
		for(int i=2;i<=n;++i)write(i,' ');
		write(1);
	}
	else{
		dfs(1,0);
		write(ans,'\n');
		for(int i=1;i<=n;++i)write(op[i],' ');
	}
	return 0;
}