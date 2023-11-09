/*
正难则反
排序后，后面的球（包括自己）对自己的贡献的最小值
重要条件：max(i-l[i],r[i]-i)<=7
原问题=排序后，球对前面的球的贡献和的最小值
就是让有贡献的球尽量不在前面 
*/

#include<cstdio>
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
	char stk[14];int tot=0;
	do stk[++tot]=x%10+48,x=x/10;while(x);
	for(;tot;tot--)putchar(stk[tot]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}
template<typename T>T max(T x,T y){return x>y?x:y;}
const int maxn=1e3+4;
int n,l[maxn],r[maxn],c[maxn];
bool flag1=1;
int tt[14],vis[14],ans,ui[14];
void dfs(int x){
	if(x>n){
		memset(ui,0,sizeof(ui));
		int cnt=0;
		for(int i=1;i<=n;++i){
			ui[tt[i]]=1;
			for(int j=l[tt[i]];j<=r[tt[i]];++j)if(!ui[j])cnt+=c[tt[i]];
		}
		ans=max(ans,cnt);
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			vis[i]=1;
			tt[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i){
		read(l[i],r[i],c[i]);
		if(l[i]!=i||r[i]!=i||c[i]!=1)flag1=0;
	}
	if(flag1)return write(0),0;
	else if(n<=10){
		dfs(1);
		write(ans);
	}
	else{
		
	}
	return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/
