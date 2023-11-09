#include <cstdio>
#include <initializer_list>
constexpr int N=500010; 
int n,m,a[N],i,j,q[N],*st,*ed,ans,Ch,del[N],cnt;
bool v[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){
	std::initializer_list<int>{(r(x),0)...};
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48); 
}
int main(){
#undef LYH_LOCAL
#ifndef LYH_LOCAL
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
#endif
	r(n,m);
	for(i=0;i<m;i++){
		r(a[i]);
	}
	for(i=1;i<=n;i++){
		st=ed=q;
		ans=cnt=0;
		for(j=0;j<m;j++){
			if(del[a[j]])del[*ed++=a[j]]++;
			while(del[*st]>1)del[*st++]--;
			if(del[a[j]])continue;
			ans++;
			if(cnt==i){
//				printf("del: %d %d\n",j,*st);
				del[*st++]=0;
				cnt--; 
			}
//			printf("add: %d %d\n",j,a[j]);
			del[*ed++=a[j]]=1;
			cnt++;
		}
		while(st!=ed){
			del[*st++]--;
		}
		w(ans);
		putchar(32);
	}
	return 0;
}
