//能不能不捆绑啊！！！！！！！！！！！！！！！！
#include <cstdio>
#include <cstdlib>
#include <algorithm>
constexpr int N=1000001;
int n,k,Ch,i,a[N+9>>1],cnt,ma,b[6];
char v[N];
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
inline void w(char x){putchar(x);}
inline void w(const char*x){while(*x)putchar(*x++);}
template<typename... Ar>
inline void w(const Ar&...x){std::initializer_list<int>{(w(x),0)...};}
// constexpr std::array<int,N>init(){
// 	std::array<int,N>lg{};
// 	for(int i=1;i<20;i++)lg[1<<i]=i;
// 	return lg;
// }
// constexpr std::array<int,N>lg(init());
void dfs(const int&&x,const int&&S,int&&i){
	if(x==6){
		w("Yes\n");
		while(n--){
			for(int i=0;i<6;i++)w(b[i],' ');
			w('\n');
		}
		exit(0);
	}
	if(v[a[i]]*(6-x)+v[S]>20)return;
	for(;i<ma;i++)
		if((S&a[i])==0){
			b[x]=a[i];
			dfs(x+1,S^a[i],i+1);
		}
}
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	r(n,k);
	for(i=0;i<N;i+=k){
		v[i]=__builtin_popcount(i);
		a[cnt++]=i;
	}
	std::sort(a,a+cnt,[](const int&a,const int&b){return v[a]!=v[b]?v[a]<v[b]:a<b;});
	if(n==0){
		w("Yes");
		return 0;
	}
	if(n==1){
		w("Yes\n",a[0],' ',a[1],' ',a[2],' ',a[3],' ',a[4],' ',a[5]);
		return 0;
	}
	if(k==15||k==30||k==45||k==51||k==60){
		w("No");
		return 0;
	}
	// for(i=0;i<cnt;i++){
	// 	printf("%d %d\n",a[i],v[a[i]]);
	// }
	//return 0;
	for(ma=6;ma<=280&&v[a[0]]+v[a[1]]+v[a[2]]+v[a[3]]+v[a[4]]+v[a[ma-1]]<=20;ma++)dfs(0,0,0);
	w("No");
	return 0;
}
