#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+10;
inline void Freopen(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
}
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
int n,a[MAXN],ans=1e9,tot;
int num[MAXN];
void dfs(int k,int sum){
	if(sum>n) return ;
	if(sum==n){
		int i=1,tot=1,maxn=0,minn=1e9;
		while(1){
			if(i>k-1) break;
			if(num[i]==2){
				maxn=max(maxn,a[tot]+a[tot+1]);
				minn=min(minn,a[tot]+a[tot+1]);
				tot+=2;
			}
			else{
				maxn=max(maxn,a[tot]);
				minn=min(minn,a[tot]);
				tot++;
			}
			i++;
		}
		ans=min(maxn-minn,ans);
		return ;
	}
	num[k]=1; dfs(k+1,sum+1);
	num[k]=2; dfs(k+1,sum+2);
}
signed main(){
	Freopen();
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
} 
