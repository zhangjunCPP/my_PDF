#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int s=0,w=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*w;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}
const int maxn=2e5+1;
bool flag1=1,flag2=1;
bool vis[maxn];
int n,ans,a[maxn],val[maxn];
int ANS[maxn];
int v[maxn];
inline void dfs(int pos){
	if(pos==n+1){
		for(int i=1;i<=n;++i)a[val[i]]=i;
		stack<int> Q;
		int sum=0;
		for(int i=1;i<=n;++i){
			while(!Q.empty()&&Q.top()>a[i]){
				sum+=v[a[i]];
				Q.pop();
			}
			Q.push(a[i]); 
		}
		if(sum>ans){
			ans=sum;
			for(int i=1;i<=n;++i)ANS[i]=a[i];
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		val[pos]=i;
		vis[i]=1;
		dfs(pos+1);
		vis[i]=0;
	}
} 
signed main(){
	FRE();
	n=read();
	for(int i=1;i<=n;++i){
		v[i]=read();
		if(v[i]!=i)flag1=0;
		if(v[i]!=n-i+1)flag2=0;
	}
	if(flag1){
		printf("%lld\n",n*(n-1)/2);
		for(int i=n;i>=1;--i)printf("%lld ",i);
		return 0;
	}
	if(flag2){
		printf("%lld\n",(n-1)*n);
		for(int i=2;i<=n;++i)printf("%lld ",i);
		printf("1");
		return 0;
	}
	dfs(1);
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i)printf("%lld ",ANS[i]); 
	return 0;
}

