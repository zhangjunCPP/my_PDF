#include <cstdio>
#include <algorithm>
constexpr int mi_N=1010,N=250010;
constexpr int dx[]{1,1,0,-1,-1,-1,0,1},dy[]{0,1,1,1,0,-1,-1,-1};
int Ch,n,m,qn,i,x,y,ans[N],mp[mi_N][mi_N];
struct ss{
	int lx,ly,rx,ry;
	void paint(){
		int i,j;
		for(i=lx;i<=rx;i++){
			for(j=ly;j<=ry;j++){
				mp[i][j]++;
			}
		}
	}
	void operator+=(const int&x){
		lx+=dx[x];
		ly+=dy[x];
		rx+=dx[x];
		ry+=dy[x];
	}
}a[N];
struct sss{
	int lx,ly,width,len;
};
struct p{
	int x,y,id;
	bool operator<(const p&b)const{
		return x<b.x;
	}
}q[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
inline void r(ss&x){
	r(x.lx,x.ly,x.rx,x.ry);
}
inline void r(p&x){
	r(x.x,x.y);
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
namespace solve4{
	struct line{
		int l,r,x,tp;
		bool operator<(const line&b)const{
			return x<b.x;
		}
	}l[N<<1];
	int t[N],now;
	inline void u(int x,const int&k){
		while(x<N){
			t[x]+=k;
			x+=x&-x;
		}
	}
	inline int qry(int x){
		int s=0;
		while(x){
			s+=t[x];
			x^=x&-x;
		}
		return s;
	}
	inline void main(){
		for(i=1;i<=n;i++){
			a[i].rx++;
			a[i].ry++;
			l[i-1<<1]={a[i].ly,a[i].ry,a[i].lx,1};
			l[i-1<<1|1]={a[i].ly,a[i].ry,a[i].rx,-1};
		}
		n<<=1;
		std::sort(l,l+n);
		std::sort(q+1,q+qn+1);
		l[n].x=N+1;
		for(i=1;i<=qn;i++){
			while(l[now].x<=q[i].x){
				u(l[now].l,l[now].tp);
				u(l[now].r,-l[now].tp);
				now++;
			}
			ans[q[i].id]=qry(q[i].y);
		}
	}
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	r(n,m,qn);
	for(i=1;i<=n;i++){
		r(a[i]);
		if(m)a[i].paint();
	}
	if(!m){
		for(i=1;i<=qn;i++){
			r(q[i]);
			q[i].id=i;
		}
		solve4::main();
		for(i=1;i<=qn;i++){
			w(ans[i]);
			putchar(10);
		}
		return 0;
	}
	while(m--){
		r(x,i,y);
		while(y--){
			a[i]+=x;
			a[i].paint();
		}
	}
	while(qn--){
		r(x,y);
		w(mp[x][y]);
		putchar(10);
	}
	return 0;
}
