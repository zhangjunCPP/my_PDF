#include <cstdio>
#include <bitset>
constexpr int N=21;
std::bitset<1<<N>v; 
int n,nn,cnt,W[N],x,ans,Ch;
unsigned s;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48); 
}
void dfs2(const unsigned&x){
	//fprintf(stderr,"%u\n",x);
	v.set(x);
	ans++;
	for(int i=0;1<<i<=x;i++){
		//fprintf(stderr,"x=%d\n",x);
		if(x>>i&1){
			unsigned t=x^1<<i;
			//fprintf(stderr,"x=%d t=%u\n",x,t);
			if(i>1&&x>>i-1&1&&~x>>i-2&1&&!v[t|1<<i-2]){//fprintf(stderr,"%u->%u\n",x,t|1<<i-2);
				dfs2(t|1<<i-2);
			}//fprintf(stderr,"x=%d t=%u\n",x,t|1<<i+2);
			if(i+2<n&&x>>i+1&1&&~x>>i+2&1&&!v[t|1<<i+2]){//fprintf(stderr,"%u->%u\n",x,t|1<<i+2);
				dfs2(t|1<<i+2);
			}//fprintf(stderr,"x=%d t=%u\n",x,t|1<<i+2);
		}
	}
}
void dfs(const int&x,const unsigned&s){//fprintf(stderr,"start: %d %u\n",x,s);
	if(x==cnt){
		v.reset();
		dfs2(s);
		return;
	}
	dfs(x+1,s);
	dfs(x+1,s|1<<W[x]);
}
int main(){
//#undef LYH_LOCAL
#ifndef LYH_LOCAL
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
#endif
	r(n);
	nn=n;
	if(Ch!=10)while(getchar()!=10);
	while(n--){
		x=getchar();
		if(x=='1'){
			s|=1<<n;
		}
		else if(x=='?')W[cnt++]=n;
	}
	n=nn;
	if(n<3){
		w(1<<cnt);
		return 0;
	}
	dfs(0,s);
	w(ans);
	return 0;
}
