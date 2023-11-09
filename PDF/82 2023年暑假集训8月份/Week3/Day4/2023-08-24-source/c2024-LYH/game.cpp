#include <cstdio>
using ll=long long;
constexpr int N=200010;
int n,Ch,i,a[N],stk[20][20],*top[N],cz[11],ANS[11];
bool flag1=true,flag2=true,v[N];
ll ans;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename T>
void w(T&&x){
	if(x>9)w(x/10);
	putchar(x%10|48);
}
inline void solve1(){
	w(ll(n-1)*n>>1);
	putchar(10);
	while(n){
		w(n--);
		putchar(32);
	}
}
inline void solve2(){
	w(n*ll(n-1));
	putchar(10);
	while(n){
		w(n--);
		putchar(32);
	}
}
inline void push(const int&x,const int&i,ll&s){
	while(top[x]&&i<*top[x]){
		top[x]--;
		s+=a[i];
	}
	*++(top[x])=i;
}
void dfs(const int&x,const ll&s){
	if(x>n){
		if(s>ans){
			ans=s;
			__builtin_memcpy(ANS,cz,sizeof cz);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=true;
			ll ss=s;
			top[x+1]=stk[x+1]+(top[x]-stk[x]);
			__builtin_memcpy(stk[x+1],stk[x],sizeof stk[x]);
			push(x+1,i,ss);
			cz[x]=i;
			dfs(x+1,ss);
			v[i]=false;
		}
	}
}
inline void solve3(){
	top[1]=stk[1];
	dfs(1,0);
	w(ans);
	putchar(10);
	for(i=1;i<=n;i++){
		w(ANS[i]);
		putchar(32);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	r(n);
	for(i=1;i<=n;i++){
		r(a[i]);
		if(a[i]!=i)flag1=false;
		if(a[i]!=n-i+1)flag2=false;
	}
	if(flag1)solve1();
	else if(flag2)solve2();
	else solve3();
	return 0;
}
