#include<map>
#include<cstdio>
#include<vector>
#include<algorithm>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	x<0?putchar('-'),x=-x:false;
	char stk[104];int top=0;
	do stk[++top]=x%10+48,x/=10;while(x);
	for(;top;top--)putchar(stk[top]);
}
template<typename T,typename ...Args>void read(T &a,Args &...args){read(a);read(args...);}
template<typename T,typename ...Args>void write(T a,Args ...args){write(a);write(args...);}
template<typename T>T min(T a,T b){return a>b?b:a;}
template<typename T,typename ...Args>T min(T a,T b,Args ...args){return min(a,min(b,args...));}
template<typename T>T max(T a,T b){return a>b?a:b;}
template<typename T,typename ...Args>T max(T a,T b,Args ...args){return max(a,max(b,args...));}
template<typename T>void Swap(T &a,T &b){a^=b^=a^=b;}
template<typename T>T abs(T a){return a<0?-a:a;}
const int maxn=504,mod=1e9+7;
int n,a[maxn],ans;
std::vector<int>b,copy;
std::map<std::vector<int>,bool>mp;
void dfs2(std::vector<int>x){
	if(mp.find(x)!=mp.end())return;
	mp[x]=1;ans++;if(ans>=mod)ans-=mod;copy=x;
	for(int i=1;i<n;++i){
		if(i<n-1&&x[i]==1&&x[i+1]==1&&x[i+2]==0){
			copy=x;
			copy[i]=0;copy[i+2]=1;
			dfs2(copy);
		}
		if(i>1&&x[i]==1&&x[i+1]==1&&x[i-1]==0){
			copy=x;
			copy[i+1]=0;copy[i-1]=1;
			dfs2(copy);
		}
	}
}
void dfs(int x){
	if(x>n){
		mp.clear();
		dfs2(b);
		return;
	}
	if(a[x]==-1){
		b[x]=1;
		dfs(x+1);
		b[x]=0;
		dfs(x+1);
	}
	else{
		b[x]=a[x];
		dfs(x+1);
	}
}
signed main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	read(n);b.resize(n+2);
	for(int i=1;i<=n;++i){
		char x=getchar();
		if(x=='?')a[i]=-1;
		if(x=='1')a[i]=1; 
		if(x=='0')a[i]=0;
	}
	dfs(1);
	write(ans); 
	return 0;
}
