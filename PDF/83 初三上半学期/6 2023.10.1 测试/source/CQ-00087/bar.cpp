#include <cstdio>
#include <queue>
constexpr int N=55,M=N*N;
int ch,n,m,k,i,x,y,tot,W,nxt[M],dis[N],hd[N],to[M],e[M],nxt2[M],hd2[N],to2[M],e2[M],tot2,DIS;
bool v[N];
template<typename T,int N,int page_size>
class memory_pool{
	T m[N*page_size];
	T*stk[N],**top;
public:
	memory_pool():m{},top(stk-1){
		for(int i=0;i<N;i++)*++top=m+i*page_size;
	}
	T*alloc(){
		return *top--;
	}
	void free(T*p){
		if(!p)return;
		*++top=p;
		__builtin_memset(p,0,page_size*sizeof(T));
		return;
	}
};
memory_pool<char,N*N*N,N>mp;
struct path{
	char*s;
	int k,n;
	long long v;
	path():s(mp.alloc()){
		k=0;
		n=1;
		v=2;
		s[0]=1;
	}
	path(const path&b):s(mp.alloc()){
		k=b.k;
		n=b.n;
		v=b.v;
		__builtin_memcpy(s,b.s,n);
	}
	path(path&&b){
		s=b.s;
		b.s=nullptr;
		k=b.k;
		n=b.n;
		v=b.v;
	}
	void operator=(const path&b){
		mp.free(s);
		s=mp.alloc();
		k=b.k;
		n=b.n;
		v=b.v;
		__builtin_memcpy(s,b.s,n);
	}
	void operator=(path&&b){
		s=b.s;
		b.s=nullptr;
		k=b.k;
		n=b.n;
		v=b.v;
	}
	bool operator<(const path&b)const{
		if(k+dis[s[n-1]]!=b.k+dis[b.s[b.n-1]])return k+dis[s[n-1]]>b.k+dis[b.s[b.n-1]];
		int i;
		for(i=0;s[i]==b.s[i];i++);
//		printf("cmp: %d %d i=%d a=%d b=%d\n",s[n-1],b.s[b.n-1],i,s[i],b.s[i]);
		return s[i]>b.s[i];
	}
	path operator+(const int&i)const{
		path ans=*this;
		ans.s[ans.n++]=to[i];
		ans.k+=e[i];
		ans.v|=1ll<<to[i];
//		printf("plus#%d k=%d dis=%d\n",to[i],ans.k,dis[to[i]]);
		return ans;
	}
	void out();
	~path(){
		mp.free(s);
	}
};
struct ss{
	int dis,to;
	ss(const int&a,const int&b):dis(a),to(b){}
	bool operator<(const ss&b)const{
		return dis>b.dis;
	}
};
struct sss{
	int d,to;
	long long v;
	sss(const int&a,const int&b,const long long&c):d(a),to(b),v(c){}
	bool operator<(const sss&b)const{
		return d+dis[to]>b.d+dis[b.to];
	}
};
template<typename T>
inline void r(T&x){
	while((ch=getchar())<48);
	x=ch&15;
	while((ch=getchar())>47)x=(x<<1)+(x<<3)+(ch&15);
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
inline void path::out(){
	w(n);
//	printf(" %d %lld",k,v);
	putchar(10);
	for(int i=0;s[i];i++){
		w(s[i]);
		putchar(32);
	}
	putchar(10);
}
template<typename...Ar>
inline void r(Ar&&...x){
	std::initializer_list<int>{(r(x),0)...};
}
inline void add(const int&x,const int&y,const int&w){
//	printf("%d %d\n",x,y);
	nxt[++tot]=hd[x];
	hd[x]=tot;
	to[tot]=y;
	e[tot]=w;
}
inline void add2(const int&x,const int&y,const int&w){
	nxt2[++tot2]=hd2[x];
	hd2[x]=tot2;
	to2[tot2]=y;
	e2[tot2]=w;
}
//void dfs(const int&x,const int&s){
//	if(x==n){
//		printf("%d %d\n",s,cnt+1);
//		for(char*i=stk+1;i<=top;i++){
//			printf("%d ",*i);
//		}
//		puts("");
//		::s[cnt++].set(s,stk);
//		return;
//	}
//	v[x]=true;
//	*++top=x;
//	for(int i=hd[x];i;i=nxt[i])if(!v[to[i]])dfs(to[i],s+e[i]);
//	v[x]=false;
//	top--;
//}
std::priority_queue<path>q;
std::priority_queue<ss>q2;
std::priority_queue<sss>q3;
int main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	r(n,m,k);
	for(i=0;i<m;i++){
		r(x,y,W);
		add(x,y,W);
		add2(y,x,W);
	}
	__builtin_memset(dis,0x3f,n<<2);
	q2.emplace(0,n);
	while(!q2.empty()){
		auto now=q2.top();
		q2.pop();
		if(v[x=now.to])continue;
		v[x]=true;
		for(i=hd2[x];i;i=nxt2[i]){
			if(dis[to2[i]]>dis[x]+e2[i]){
				q2.emplace(dis[to2[i]]=dis[x]+e2[i],to2[i]);
			}
		}
	}
	int kk=k;
	q3.emplace(0,1,2);
	while(!q3.empty()){
		auto now=q3.top();
		q3.pop();
		if(now.to==n){
//			printf("%lld %d\n",now.v,now.d);
			if(!--kk){
				DIS=now.d;
				break;
			}
			continue;
		}
		for(i=hd[now.to];i;i=nxt[i])if(~now.v>>to[i]&1)q3.emplace(now.d+e[i],to[i],now.v|1ll<<to[i]);
	}
	if(q3.empty()&&kk){
		putchar(45);
		putchar(49);
		return 0;
	}
//	printf("%d\n",DIS);
//	for(i=1;i<=n;i++){
//		printf("dis[%d]=%d\n",i,dis[i]);
//	}
	q.emplace();
	while(!q.empty()){
		auto now(q.top());
		q.pop();
//		now.out();
		if(now.k+dis[now.s[now.n-1]]>DIS)continue;
		if(now.v>>n&1){
//			printf("%lld %d\n",now.v,now.k);
			if(!--k){
				now.out();
				return 0;
			}
			continue;
		}
		for(i=hd[now.s[now.n-1]];i;i=nxt[i]){
//			printf("%d->%d\n",now.s[now.n-1],to[i]);
			if(~now.v>>to[i]&1){
				q.emplace(now+i);
//				auto now=q.top();
//				printf("top=%d\n",now.n);
			}
		}
	}
	putchar(45);
	putchar(49);
	return 0;
}
