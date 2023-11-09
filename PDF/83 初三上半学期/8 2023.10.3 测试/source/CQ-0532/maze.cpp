#include <cstdio>
#include <queue>
constexpr int N=200010;
int n,m,k,i,hd[N],to[N<<1],nxt[N<<1],e[N<<1],d[N],tot,Ch,rd[N];
bool v[N];
struct ss{
	int to,dis;
	ss(const int&to_,const int&dis_):to(to_),dis(dis_){}
	bool operator<(const ss&b)const{
		return dis>b.dis; 
	}
};
struct edge_t{
	int x,y,w;
}edge[N];
std::priority_queue<ss>q;
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
	if(9<x)w(x/10);
	putchar(x%10|48);
}
inline void add_(const int&x,const int&y,const int&w){
	nxt[++tot]=hd[x];
	hd[x]=tot;
	to[tot]=y;
	e[tot]=w;
}
inline void add(const int&x,const int&y,const int&w){
//	printf("add: %d %d\n",x,y);
	if(!v[y])add_(x,y,w);
	if(!v[x])add_(y,x,w);
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	r(n,m,k);
//	__builtin_memset(dis+1,0x3f,n<<2);
	while(k--){
		r(i);
		v[i]=true;
		q.emplace(i,0);
	}
	for(i=1;i<=n;i++){
		r(d[i]);
		if(v[i])d[i]=1;
		else d[i]++;
	}
	for(i=0;i<m;i++){
		r(edge[i].x,edge[i].y,edge[i].w);
		rd[edge[i].x]++;
		rd[edge[i].y]++;
	}
	for(i=0;i<m;i++)
		if(rd[edge[i].x]>=d[edge[i].x]&&rd[edge[i].y]>=d[edge[i].y])
			add(edge[i].x,edge[i].y,edge[i].w);
	while(!q.empty()){
		auto x=q.top();
		q.pop();
//		printf("%d %d\n",x.to,x.dis);
		if(--d[x.to])continue;
		v[x.to]=true;
//		printf("%d %d\n",x.to,x.dis);
		if(x.to==1){
			w(x.dis);
			return 0;
		}
		for(i=hd[x.to];i;i=nxt[i])if(!v[to[i]])q.emplace(to[i],x.dis+e[i]);
	}
	putchar(45);
	putchar(49);
	return 0;
}
/*
5 8 3
2 3 5
2 0 1 1 2
1 2 1
2 3 2
3 4 5
2 5 3
4 5 2
5 1 3
3 5 2
4 1 1
*/
