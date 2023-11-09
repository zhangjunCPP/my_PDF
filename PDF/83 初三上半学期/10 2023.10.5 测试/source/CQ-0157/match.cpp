/*
比较easy
显然一个皮配的所以边的共同端点都是一个
统计下一个端点多少次
输出最大的连边数
时间：O(m+n) 
欸，过不了。
三元环也可以，但是不能在此之上连边 
*/

#include<cstdio>
#include<vector>
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
const int maxn=1e6+4;
int T,n,m,du[maxn];
std::vector<int>E[maxn];
bool vis[maxn],flag;
void dfs(int x,int FA,int yu){
	if(flag)return;
	if(yu>4)return;
	if(yu==3&&vis[x]==1){
		flag=1;
		return;
	}
	vis[x]=1;
	for(int v:E[x])
		if(v!=FA)
			dfs(v,x,yu+1);
	vis[x]=0;
}
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(T);
	for(;T--;){
		read(n,m);flag=0;
		for(int i=1;i<=n;++i)du[i]=0,E[i].clear(),vis[i]=0;
		for(int i=1;i<=m;++i){
			int x,y;read(x,y);
			E[x].emplace_back(y);
			E[y].emplace_back(x);
			du[x]++;du[y]++;
		}
		int maxx=0,id=-1;
		for(int i=1;i<=n;++i)if(du[i]>maxx)maxx=du[i],id=i;
		if(id==-1)write(0,'\n');
		else{
			int len=(int)E[id].size();
			if(len<3){//三元环 
				for(int i=1;i<=n;++i){
					if(!vis[i])dfs(1,0,0);
					if(flag)break;
				}
				if(flag)write(3,'\n');
				else write(len,'\n');
			}
			else write(len,'\n');
		}
	}
	return 0;
}
/*
3
4 1
2 3
1 0
5 4
3 2
5 3
5 1
4 5
*/
