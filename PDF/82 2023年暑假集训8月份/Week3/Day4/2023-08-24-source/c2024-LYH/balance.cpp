#include <cstdio>
#include <initializer_list>
/*
我真的吐了，这代码又臭又长
这个大样例有什么用？
都不考虑发个Checker。难道要我自己写SPJ吗？
真的是，我不管，思路对了就是对了，错了说明SPJ有问题
好慌，就过个样例
不考虑评个最长代码奖？我觉得我还是有戏的。
*/
constexpr int N=300010,INF=0x3fffffff;
int n,i,x,y,tot,hd[N],to[N<<1],nxt[N<<1],Ch,rt,rt2,ma_siz,siz[N],siz2[N],son[N],fa[N],ans[N],fa2[N],son2[N];
bool v[N],v2[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T&&x){
	if(x>9)w(x/10);
	putchar(x%10^48);
}
template<typename T>
constexpr inline T ma(const T&x,const T&y){
	return x>y?x:y;
}
inline void add_(const int&x,const int&y){
	nxt[++tot]=hd[x];
	hd[x]=tot;
	to[tot]=y;
}
inline void add(const int&x,const int&y){
	add_(x,y);
	add_(y,x);
}
void find_root(const int&x,const int n){
	// printf("find: %d %d\n",x,n);
	v[x]=true;
	siz[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		if(!v[to[i]]){
			fa[to[i]]=x;
			find_root(to[i],n);
			siz[x]+=siz[to[i]];
			if(siz[son[x]]<siz[to[i]])son[x]=to[i];
		}
	v[x]=false;
	if(n-siz[x]>siz[son[x]]){
		son[x]=fa[x];
		if(ma_siz>n-siz[x]){
			ma_siz=n-siz[x];
			rt=x;
		}
	}
	else if(ma_siz>siz[son[x]]){
		ma_siz=siz[x];
		rt=x;
	}
	v[x]=false;
}
void dfs2(const int&x){
	v2[x]=true;
	siz2[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		if(!v2[to[i]]){
			fa2[to[i]]=x;
			dfs2(to[i]);
			siz2[x]+=siz2[to[i]];
			if(siz2[son2[x]]<siz2[to[i]])son2[x]=to[i];
		}
	v2[x]=false;
}
void find_root2(const int&x,const int n){
	// printf("find2: %d %d\n",x,siz2[x]);
	v2[x]=true;
	for(int i=hd[x];i;i=nxt[i])if(!v2[to[i]])find_root2(to[i],n);
	if(n-siz2[x]>siz2[son2[x]]){
		son2[x]=fa2[x];
		if(ma_siz>n-siz2[x]){
			ma_siz=n-siz2[x];
			rt2=x;
		}
	}
	else if(ma_siz>siz2[son2[x]]){
		ma_siz=siz2[x];
		rt2=x;
	}
	v2[x]=false;
}
void rev(const int&x){
	// printf("rev: %d\n",x);
	v[x]=true;
	siz[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		if(!v[to[i]]){
			fa[to[i]]=x;
			rev(to[i]);
			siz[x]+=siz[to[i]];
			if(siz[son[x]]<siz[to[i]])son[x]=to[i];
		}
	v[x]=false;
}
void dfs(const int&x,int y){
	v[x]=true;
	// printf("dfs: %d %d\n",x,y);
	while(ma(siz2[son2[y]],n-siz2[y]-siz2[x])>ma(siz2[y],n-siz2[fa2[y]]-siz2[x]))y=fa[y];
	ans[x]=y;
	for(int i=hd[x];i;i=nxt[i])if(!v[to[i]])dfs(to[i],y);
	v[x]=false;
}
void calc(const int x,const int n){
	if(!rt)return;
	rt=0;
	// printf("calc: %d %d\n",x,n);
	v[x]=true;
	if(fa[x]){
		fa[fa[x]]=x;
		rev(fa[x]);
		if(siz[fa[x]]>siz[son[x]])son[x]=fa[x];
	}
	ma_siz=INF;
	if(!v[son[x]])find_root(son[x],siz[son[x]]);
	ma_siz=INF;
	v2[x]=true;
	siz2[x]=1;
	__builtin_memset(son2,0,sizeof son2);
	for(int i=hd[x];i;i=nxt[i]){
		fa2[to[i]]=x;
		dfs2(to[i]);
		siz2[x]+=siz2[to[i]];
		if(siz2[to[i]]>siz2[son2[x]])son2[x]=to[i];
	}
	find_root2(son2[x],siz2[son2[x]]);
	v2[x]=false;
	ans[x]=rt2;
	for(int i=hd[x];i;i=nxt[i])if(to[i]!=son[x]&&!v[to[i]])dfs(to[i],rt2);
	fa[son[x]]=0;
	calc(rt,siz[son[x]]);
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	r(n);
	for(i=1;i<n;i++){
		r(x,y);
		add(x,y);
	}
	ma_siz=INF;
	find_root(1,n);
	calc(rt,n);
	for(i=1;i<=n;i++){
		w(ans[i]);
		putchar(10);
	}
	return 0;
}
