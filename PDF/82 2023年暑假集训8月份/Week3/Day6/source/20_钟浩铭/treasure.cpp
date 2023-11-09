#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=30;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
inline int Min(int a,int b){return a<b?a:b;}
inline int Max(int a,int b){return a>b?a:b;}
int n; ll ans=0x3f3f3f3f3f3f3f3f;
int a[MAXN],flag[MAXN],id[MAXN]; bool vis[MAXN];
inline void Copy(){for(int i=1;i<=n;i++) id[i]=flag[i];}
void dfs(int k,ll sum1,ll sum2,ll sum3){
	if(k==n+1){
		int maxn=Max(Max(sum1,sum2),sum3);
		int minn=Min(Min(sum1,sum2),sum3);
		if(maxn-minn==0){
//			printf("%d\n",maxn-minn);
			for(int i=1;i<=n;i++) printf("%d ",flag[i]);
			exit(0);
		}
		if(ans>maxn-minn) ans=maxn-minn,Copy();
		return ;
	}
	flag[k]=1; dfs(k+1,sum1+a[k],sum2,sum3);
	flag[k]=2; dfs(k+1,sum1,sum2+a[k],sum3);
	flag[k]=3; dfs(k+1,sum1,sum2,sum3+a[k]);
	return ;
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	dfs(1,0,0,0); //printf("ans: %d\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",id[i]);
	return 0;
}

