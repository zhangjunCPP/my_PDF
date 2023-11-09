//除非暴力很难敲，先敲暴力总没错
#include <cstdio>
#include <initializer_list>
constexpr int N=500010,A=22;
int cnt[N][A],a[N],n,i,Ch,j,f[N],la[N],now,stk[N],*top=stk,ans,latest[A],ma=-1;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48||Ch>57);
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=(x<<1)+(x<<3)+(Ch^48);
}
template<typename T>
void w(T&&x){
	if(x>9)w(x/10);
	putchar(x%10^48);
}
inline void w(char x){putchar(x);}
template<typename... Ar>
inline void w(const Ar&...x){std::initializer_list<int>{(w(x),0)...};}
inline void mex(int&ans,const int&l,const int&r){
	int*R=cnt[r],*L=cnt[l];
	while(R[ans]-L[ans])ans++;
}
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	r(n);
	for(i=1;i<=n;i++){
		r(a[i]);
		for(j=0;j<=ma;j++)cnt[i][j]=cnt[i-1][j];
		if(ma<a[i])ma=a[i];
		cnt[i][a[i]]++;
		latest[a[i]]=i;
		now=0;
		for(j=latest[0];j;j=latest[now]){
			mex(now,j-1,i);
			if(f[i]<f[j-1]+now){
				f[i]=f[j-1]+now;
				la[i]=j-1;
			}
		}
	}
	i=n;
	while(i){
		*++top=i=la[i];
		ans++;
	}
	w(f[n],' ',ans,'\n');
	while(top!=stk)w(1+*top--,' ');
	return 0;
}
