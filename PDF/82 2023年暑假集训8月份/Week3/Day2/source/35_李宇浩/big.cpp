#include <cstdio>
#include <initializer_list>
constexpr int N=20,M=(N*N-N)>>1;
int Ch,n,cm,m,i,b,d[N],ans,q,j;
struct ss{
	int x,y;
}ce[M],e[M];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename T>
inline void r_b(T&x){
	int c=1;
	while((Ch=getchar())<48);
	x=(Ch&1)<<c++;
	while((Ch=getchar())>47)x=x|(Ch&1)<<c++;
}
template<typename...Ar>
inline void r(Ar&...x){
	std::initializer_list<int>{(r(x),0)...};
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
inline int ck(const int&i){
	return b>>i&1;
}
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	r(n,cm);
	for(i=0;i<cm;i++)r(ce[i].x,ce[i].y);
	r(q);
	while(q--){
		ans=m=0;
		r_b(b);
		for(i=0;i<cm;i++)if(ck(ce[i].x)&&ck(ce[i].y))e[m++]=ce[i];
		if(m>32){
			putchar(49);
			putchar(10);
			continue;		
		}
		for(i=1;i<1<<m;i++){
			__builtin_memset(d+1,0,n<<2);
			for(j=0;j<m;j++)
				if(i>>j&1){
					d[e[j].x]++;
					d[e[j].y]++;
				}
			for(j=1;j<=n&&(~b>>j&1||d[j]>1);j++);
			if(j>n)ans++;
		}
		w(ans);
		putchar(10);
	}
	return 0;
}
