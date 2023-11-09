/*
t3
O(n^2)很容易想到
链的情况也能处理
菊花图的情况更好处理
暴力骗60？？ 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,INF=0x7fffffff;
inline int re(){
    int x=0;
    char c=getchar();
    while(c<48||c>57)c=getchar();
    while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
void wr(int x){
    if(x>9)wr(x/10);
    putchar(x%10|48);
}
int i,n;
inline void lian(){
	for(i=1;i<=n;++i){
		if(i-1>n-i)wr(i>>1);
		else wr((n-i+1>>1)+i);
		putchar(10);
	}
}
inline void flower(){
	for(i=1;i<=n;++i)wr(i==1?2:1),putchar(10);
}
int cnt,first[N];
struct Edge{
	int u,v,nex;
}a[N<<1];
inline void add(int u,int v){
	a[++cnt]={u,v,first[u]};
	first[u]=cnt;
}
int x,y;
bool flag1,flag2;
int fa[N],siz[N];
void prework(int u,int dad){
	fa[u]=dad;
	siz[u]=1;
	for(int i=first[u];i;i=a[i].nex){
		int v=a[i].v;
		if(v!=dad){
			prework(v,u);
			siz[u]+=siz[v];
		}
	}
}
int f[N],s[N],mx,rt;
bool vis[N];
void get_s(int u,int dad){
	s[u]=1;
	for(int i=first[u];i;i=a[i].nex){
		int v=a[i].v;
		if(!vis[v]&&v!=dad){
			get_s(v,u);
			s[u]+=s[v];
		}
	}
}
void find_rt(int u,int dad){
	f[u]=0;
	for(int i=first[u];i;i=a[i].nex){
		int v=a[i].v;
		if(!vis[v]&&v!=dad){
			find_rt(v,u);
			f[u]=max(f[u],s[v]);
		}
	}
	f[u]=max(f[u],s[mx]-s[u]);
	if(f[u]<f[rt])rt=u;
}
int u;
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
//	puts("sb火绒"); 
	n=re();
	for(i=1;i<n;++i){
		x=re();
		y=re();
		add(x,y);
		add(y,x);
		if(x!=i||y!=i+1)flag1=1;
		if(x!=1||y!=i+1)flag2=1;
	}
	if(!flag1)return lian(),0;
	if(!flag2)return flower(),0;
	/*
	O(n^2)
	每次枚举到一个点
	判断它最大的一个子树（头顶也算）
	在那棵子树上找重心 
	*/
	prework(1,0);
	for(u=1;u<=n;++u){
		vis[u]=1;
		mx=rt=0;
		for(i=first[u];i;i=a[i].nex){
			int v=a[i].v;
			if(v!=fa[u]){
				if(siz[v]>siz[mx])mx=v;
			}
		}
		if(n-siz[u]>siz[mx])mx=1;
		f[0]=INF;
		get_s(mx,0);
		find_rt(mx,0);
//		printf("u=%d mx=%d rt=%d\n",u,mx,rt);
		wr(rt);putchar(10);
		vis[u]=0;
	}
	return 0;
}


