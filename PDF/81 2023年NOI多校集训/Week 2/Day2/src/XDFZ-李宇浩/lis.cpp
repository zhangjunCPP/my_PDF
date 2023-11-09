#include <cstdio>
#include <algorithm>
constexpr int N=500010;
int n,hd[N],to[N<<1],nxt[N<<1],tot,Ch,i,x,y,W[N],cnt[N],del,a[N],now,ma,ans=N,O[N],O_cnt,K[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48||Ch>57);
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=(x<<1)+(x<<3)+(Ch^48);
}
template<typename... Ar>
inline void r(Ar&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T&&x){
	if(x>9)w(x/10);
	putchar(x%10^48);
}
inline void add_(const int&x,const int&y){
	cnt[x]++;
	nxt[++tot]=hd[x];
	hd[x]=tot;
	to[tot]=y;
}
inline void add(const int&x,const int&y){
	add_(x,y);
	add_(y,x);
}
void dfs(const int&x,const int&fa){
	int id=0,tmp=0;
	if(W[x]>a[now]){
		a[++now]=W[x];
		tmp=0;
		id=now;
	}
	else{
		auto p=std::upper_bound(a+1,a+now+1,W[x]);
		if(p!=a+now+1){
			tmp=std::exchange(*p,W[x]);
			id=p-a;
		}
	}
	//printf("%d %d %d %d\n",x,fa,now,W[x]);
	for(int i=hd[x];i;i=nxt[i])if(to[i]!=fa&&to[i]!=del)dfs(to[i],x);
	if(now>ma)ma=now;
	a[id]=tmp;
	if(id&&id==now&&!tmp)now--;
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	r(n);
	for(i=1;i<n;i++){
		r(x,y);
		add(x,y);
	}
	for(i=1;i<=n;i++){
		r(W[i]);
		if(cnt[i]==1)O[O_cnt++]=i;
	}
	for(i=1;i<=n;i++){
		if(cnt[i]!=1)continue;
		now=ma=0;
		dfs(i,0);
		K[i]=ma;
		//printf("%d\n",K[i]);
	}
	std::sort(O,O+O_cnt,[](const int&a,const int&b){return K[a]>K[b];});
	for(del=1;del<=n;del++){
		ma=now=0;
		for(i=0;i<O_cnt&&ma<ans&&K[O[i]]>ma;i++)if(del!=O[i])dfs(O[i],0);
		for(i=hd[del];i&&ma<ans;i=nxt[i])if(cnt[to[i]]==2)dfs(to[i],0);
		//printf("end#%d %d\n",del,ma);
		if(ans>ma)ans=ma;
	}
	w(ans);
	return 0;
}
//0-30