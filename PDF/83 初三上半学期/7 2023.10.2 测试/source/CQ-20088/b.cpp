#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e3+10;
int n,ans;
int a[MAXN];
bool flag[MAXN];
inline int Max(int a,int b){return a>b?a:b;}
inline void work(){
	double ave=0.0; int num=0;
	for(int i=1;i<=n;i++){
		if(!flag[i]) continue;
		ave+=a[i]; num++;
	}
	ave/=num; int cnt=0;
	for(int i=1;i<=n;i++){
		if(flag[i])
			if((double)a[i]>ave) cnt++;
	}
	ans=Max(ans,cnt); return ;
}
void dfs(int k){
	if(k==n+1){
		work(); 
		return ;
	}
	flag[k]=true; dfs(k+1);
	flag[k]=false; dfs(k+1);
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1); printf("%lld",ans);
	return 0;
}
/*
20
1 20 2 19 3 18 4 17 5 16 6 15 7 14 8 13 9 12 10 11
*/
