/*
暴力太难写了，直接冲正解 
o(n^2) 还是比较好想的：
模拟一个双端队列,ok,60分到手 
主要T在哪里，对于每一个k都要来一次
不知如何优化，换题 
*/
#include<cstdio>
#include<cstring>
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
const int maxn=5e5+4;
int n,m,a[maxn],l,r,cnt;
int tim[maxn];
std::pair<int,int>que[maxn];
signed main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	read(n,m);
	for(int i=1;i<=m;++i)read(a[i]);
	for(int k=1;k<=n;++k){
		memset(tim+1,0,n*sizeof(int));
		l=1;r=0;int ans=0;cnt=0;
		for(int i=1;i<=m;++i){
			if(tim[a[i]])tim[a[i]]=i,que[++r]={a[i],i};
			else{
				if(cnt<k)tim[a[i]]=i,que[++r]={a[i],i},cnt++,ans++;
				else{
					for(;l<=r;){
						if(tim[que[l].first]==que[l].second){tim[que[l].first]=0;l++;break;}
						l++;
					}
					que[++r]={a[i],i};tim[a[i]]=i;ans++;
				}
			}
		}
		write(ans,' ');
	}
	return 0;
}
