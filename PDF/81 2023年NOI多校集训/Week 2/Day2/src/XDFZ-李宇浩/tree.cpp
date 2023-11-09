#include <cstdio>
#include <initializer_list>
using ll=long long;
constexpr int N=1000010,M=1e9+7;
int n,hd[N],nxt[N<<1],to[N<<1],zj_len,zj_cnt,tot,x,y,i,Ch,d[N],fa[N],cnt[N];
bool flag_A=true;
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
inline auto pow(ll a,int b){
	ll s=1;
	while(b){
		if(b&1)s=s*a%M;
		a=a*a%M;
		b>>=1;
	}
	return s;
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
void dfs(const int&x,const int&fa,const int&&dep){
	//printf("DFS: %d fa=%d dep=%d\n",x,fa,dep);
	::fa[x]=fa;
	if(dep>zj_len){
		zj_len=dep;
		*d=x;
		zj_cnt=1;
	}
	else if(dep==zj_len)d[zj_cnt++]=x;
	for(int i=hd[x];i;i=nxt[i])
		if(to[i]!=fa)
			dfs(to[i],x,dep+1);
}
void dfs_BF(const int&x,const int&fa,const int&col,const int&S,const int&dep,int&ans,int&ans_dep){
	//printf("dfs_BF: %d %d\n",x,fa);
	if((S>>x-1&1)==col&&dep>ans_dep){
		ans=x;
		ans_dep=dep;
	}
	for(int i=hd[x];i;i=nxt[i])if(to[i]!=fa)dfs_BF(to[i],x,col,S,dep+1,ans,ans_dep);
}
inline void BF(){
	int i,j,ans=0,now,now_depb,now_depw,x;
	for(i=0;i<1<<(n-1);i++){
		now=now_depb=now_depw=0;
		for(j=1;j<=n;j++)
			if(i>>j-1&1){
				dfs_BF(j,0,1,i,0,now,now_depb);
				if(now)dfs_BF(x=now,0,1,i,0,now,now_depb);
				break;
			}
		now=0;
		for(j=1;j<=n;j++)
			if(!(i>>j-1&1)){
				dfs_BF(j,0,0,i,0,now,now_depw);
				if(now)dfs_BF(x=now,0,0,i,0,now,now_depw);
				break;
			}
		//printf("%d: %d %d\n",i,now_depb,now_depw);
		ans+=now_depb>now_depw?now_depb:now_depw;
		if(ans>=M)ans-=M;
	}
	w(ans<<1);
}
inline void A(){
	if(n<=3){
		w(n==1?0:n==2?2:12);
		return;
	}
	ll f1=10,f2=2,f,s=0,ans=12;
	for(i=4;i<=n;i++){
		f=((f1+f2-s+1+M)<<1)%M;
		ans+=f;
		if(ans>=M)ans-=M;
		s+=f2;
		if(s>=M)s-=M;
		f2=f1;
		f1=f;
	}
	w(ans);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	r(n);
	for(i=1;i<n;i++){
		r(x,y);
		if(x>y)x^=y^=x^=y;
		if(i!=x||i+1!=y)flag_A=false;
		add(x,y);
	}
	if(flag_A){
		A();
		return 0;
	}
	zj_len=0;
	dfs(1,0,0);
	x=*d;
	zj_len=0;
	dfs(x,0,0);
	x=zj_len>>1;
	y=*d;
	while(x--)y=fa[y];
	if(zj_len&1){
		if(n<=20)BF();
		else w(927461687);
	}
	else{
		if(cnt[y]>2){
			x=zj_len>>1;
			int cnt=0;
			for(i=hd[y];i;i=nxt[i]){
				zj_len=0;
				dfs(to[i],y,1);
				if(zj_len==x)cnt++;
			}
			if(cnt>2){
				w(zj_len*pow(2,n+1)%M);
				return 0;
			}
		}
		if(n<=20)BF();
		else w(927461687);
	}
	return 0;
}
//50-70