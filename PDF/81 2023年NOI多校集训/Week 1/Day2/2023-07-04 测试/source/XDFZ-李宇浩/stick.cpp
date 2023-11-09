#include <cstdio>
#include <bitset>
#include <unordered_set>
#include <iostream>
constexpr int N=510,M=124755;
int T,n,m,Ch,v[N],a[N];
std::bitset<M>f[N];
std::unordered_set<std::bitset<N> >st;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48||Ch>57);
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=(x<<1)+(x<<3)+(Ch^48);
}
template<typename... Ar>
inline void r(Ar&...x){std::initializer_list<int>{(r(x),0)...};}
inline void p(const int&x){
	putchar(x^48);
	putchar(10);
}
void dfs(int*a,std::bitset<N>&S,const int&n,const int&now){
	if(now==1||st.find(S)!=st.end())return;
	st.emplace(S);
	int b,i,s,ans=0,pre=0,nxt;
	while(a[pre]==-1)pre++;
	s=a[pre];
	nxt=pre+1;
	while(a[nxt]==-1)nxt++;
	for(i=nxt;i!=n;pre=i,i=nxt){
		while(++nxt<n&&a[nxt]==-1);
		ans+=s*a[i];
		if(nxt==n||a[i]+a[pre]<=a[nxt]){
			b=a[i];
			a[pre]+=a[i];
			S[s]=1;
			a[i]=-1;
			dfs(a,S,n,now-1);
			a[i]=b;
			a[pre]-=b;
			S[s]=0;
		}
		s+=a[i];
	}
	f[n][ans]=true;
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	r(T);
	for(n=0;n<500;n++)a[n]=1;
	while(T--){
		r(n,m);
		if(!m||m==n-1||m==n*n-n>>1){
			p(1);
			continue;
		}
		if(m<(n-2)*2||m>n*n-n>>1){
			p(0);
			continue;
		}
		if(v[n]){
			p(f[n][m]);
			continue;
		}
		st.clear();
		v[n]=true;
		auto S=std::bitset<N>();
		dfs(a,S,n,n);
		p(f[n][m]);
	}
	return 0;
}
