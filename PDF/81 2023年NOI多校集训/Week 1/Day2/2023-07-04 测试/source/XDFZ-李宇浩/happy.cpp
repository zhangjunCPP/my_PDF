#include <cstdio>
#include <initializer_list>
using ll=long long;
constexpr int N=100010,M=510,INF=0x3fffffff;
int n,i,O,m,Ch,t[N],j,l[M],c[M],L,la1[N],la2[N];
bool cont;
ll f[N];
// struct ss{
// 	int c,l;
// }p[M];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48||Ch>57);
	x=Ch^48;
	while((Ch=getchar())<58&&Ch>47)x=(x<<1)+(x<<3)+(Ch^48);
}
template<typename... Ar>
inline void r(Ar&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void uw(T&&x){
	if(x>9)uw(x/10);
	putchar(x%10^48);
}
template<typename T>
inline void w(T x){
	if(x<0){
		putchar(45);
		x=-x;
	}
	if(x>9)uw(x/10);
	putchar(x%10^48);
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	r(n,m);
	for(i=1;i<=n;i++){
		r(t[i]);
		f[i]=INF;
	}
	t[n+1]=INF;
	c[0]=INF;
	for(i=1;i<=m;i++){
		r(l[i],c[i]);
		L=0;
		for(j=1;j<=n;j++){
			while(t[L+1]<=t[j]-l[i])L++;
			if(f[j]>f[la1[j]]+c[la2[j]])f[j]=f[la1[j]]+c[la2[j]];
			if(f[j]>f[L]+c[i]){
				cont=true;
				la1[j]=L;
				la2[j]=i;
				f[j]=f[L]+c[i];
			}
		}
	}
	r(c[++m]);
	l[m]=1;
	for(i=1;i<=n;i++){
		if(f[i]>f[la1[i]]+c[la2[i]])f[i]=f[la1[i]]+c[la2[i]];
		if(f[i]>f[i-1]+c[m]){
			cont=true;
			la1[i]=i-1;
			la2[i]=m;
			f[i]=f[i-1]+c[m];
		}
	}
	for(i=m;i;i--){
		L=0;
		for(j=1;j<=n;j++){
			while(t[L+1]<=t[j]-l[i])L++;
			if(f[j]>f[la1[j]]+c[la2[j]])f[j]=f[la1[j]]+c[la2[j]];
			if(f[j]>f[L]+c[i]){
				cont=true;
				la1[j]=L;
				la2[j]=i;
				f[j]=f[L]+c[i];
			}
		}
	}
	while(cont){
		cont=false;
		for(i=1;i<=m;i++){
			L=0;
			for(j=1;j<=n;j++){
				while(t[L+1]<=t[j]-l[i])L++;
				if(f[j]>f[la1[j]]+c[la2[j]])f[j]=f[la1[j]]+c[la2[j]];
				if(f[j]>f[L]+c[i]){
					cont=true;
					la1[j]=L;
					la2[j]=i;
					f[j]=f[L]+c[i];
				}
			}
		}
		if(!cont)break;
		cont=false;
		for(i=m;i;i--){
			L=0;
			for(j=1;j<=n;j++){
				while(t[L+1]<=t[j]-l[i])L++;
				if(f[j]>f[la1[j]]+c[la2[j]])f[j]=f[la1[j]]+c[la2[j]];
				if(f[j]>f[L]+c[i]){
					cont=true;
					la1[j]=L;
					la2[j]=i;
					f[j]=f[L]+c[i];
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		w(f[i]-f[i-1]);
		putchar(10);
	}
	return 0;
}
