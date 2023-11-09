#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int s=0,w=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*w;
}
inline void fre(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
}
const int N=30;
int n;
int a[N];
int vis[N];
int ANS=1e18;
int ans[N]; 
inline void dfs(int pos){
	if(pos==n+1){
		int sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;++i){
			if(vis[i]==1)sum1+=a[i];
			if(vis[i]==2)sum2+=a[i];
			if(vis[i]==3)sum3+=a[i];
		}
		int dd=max({sum1,sum2,sum3})-min({sum1,sum2,sum3}); 
		if(dd<ANS){
			ANS=dd;
			if(dd==0){
				for(int i=1;i<=n;++i)printf("%lld ",vis[i]);
				exit(0);
			}
			for(int i=1;i<=n;++i)ans[i]=vis[i];
		}
		return;
	}
	vis[pos]=1;dfs(pos+1);
	vis[pos]=2;dfs(pos+1);
	vis[pos]=3;dfs(pos+1);
	vis[pos]=0;
}
signed main(){
	fre();
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	dfs(1);																										
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}
/*
13
1 1 4 5 1 4 1 9 1 9 8 1 0

1 3 3 2 3 1 2 2 3 1 3 1 1
*/
/*
*/
