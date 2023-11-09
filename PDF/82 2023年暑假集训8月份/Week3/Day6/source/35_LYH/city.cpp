#include <cstdio>
#include <algorithm>
#include <map>
constexpr int N=200010;
int n,Ch,hd[N],to[N<<1],nxt[N<<1],tot,k,i,x,y,col[N],rd[N],st,dfn[N],la[N],col2[N],cnt,Cnt[N],now,ans=0x3fffffff;
bool flag=true;
std::map<int,int>mp;
decltype(mp.end())it;
struct ss{
	int l,r;
}a[N],b[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T&&x){
	if(x>9)w(x/10);
	putchar(x%10^48);
}
inline void add(const int&x,const int&y){
	nxt[++tot]=hd[x];
	hd[x]=tot;
	to[tot]=y;
}
void dfs1(const int&x,const int&fa){
	dfn[x]=++tot;
	if(la[col2[dfn[x]]=col[x]])a[cnt++]={dfn[la[col[x]]],dfn[x]};
	la[col[x]]=x;
	for(int i=hd[x];i;i=nxt[i])if(to[i]!=fa)dfs1(to[i],x);
}
inline void add(const int&x){
	if(!Cnt[col2[x]]++)now++;
}
inline void del(const int&x){
	if(!--Cnt[col2[x]])now--;
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	r(n,k);
	for(i=1;i<n;i++){
		r(x,y);
		add(x,y);
		add(y,x);
		rd[x]++;
		rd[y]++;
	}
	for(i=1;i<=n;i++){
		r(col[i]);
		if(rd[i]==1){
			st=i;
		}
		else if(rd[i]>2)flag=false;
	}
	if(!flag){
		putchar(48);
		return 0;
	}
	tot=0;
	dfs1(st,0);
	for(i=0;i<cnt;i++){
		it=mp.lower_bound(a[i].l);
		if(it!=mp.end()&&a[it->second].r<=a[i].r)continue;
		if(it!=mp.begin()){
			it--;
			while(a[it->second].r>=a[i].r)
				if(it!=mp.begin())mp.erase(it--);
				else{
					mp.erase(it);
					break;
				}
		}
		mp[a[i].l]=i;
	}
	cnt=0;
	for(auto p:mp)b[cnt++]=a[p.second];
	int l=1,r=0;
	for(i=0;i<cnt;i++){
		while(l<a[i].l)del(l++);
		while(r<a[i].r)add(++r);
		if(now-1<ans)ans=now-1;
	}
	w(ans);
	return 0;
}
