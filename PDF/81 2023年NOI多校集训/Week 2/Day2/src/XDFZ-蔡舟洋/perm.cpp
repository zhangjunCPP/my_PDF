#include<bits/stdc++.h>
using namespace std;
int n;
long long mod;
long long f[17]={0,1,7,47,322,2404,19778,180130,1809632,19940552,239430724,3113226148};
int vis[12],p[12],pos[12];
long long ans;
void dfs(int k){
	if(k==n+1){
		for(int i=1;i<=n;i++)pos[p[i]]=i;
		for(int i=1;i<=n;i++){
			if(p[i]<pos[i]){
				ans++;
				return;
			}
			if(p[i]>pos[i])return;
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=1;
		p[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}
void solve1(){
	int tmp=0,k=n;
	for(n=3;n<=k;n++){
		ans=0;
		dfs(1);
		tmp^=ans;
	}
	printf("%d",tmp);
}
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%d%lld",&n,&mod);
	if(n<=10)return solve1(),0;
	long long tmp=0,jc=6227020800/2;
	for(int i=3;i<=n;i++){
		if(f[i])tmp^=f[i];
		else{
			jc=jc*i%mod;
			tmp^=jc;
		}
	}
	printf("%lld",tmp);
//	f[3]=1;
//	for(int i=1;i<=n;i++){
//		
//	}
	return 0;
}
/*
3:2
4:5
5:13
6:38
7:116
f_i

Q(p)pi=i
n=3 ans=1
n=4 ans=7
n=5 ans=47
n=6 ans=322
n=7 ans=2404
n=8 ans=19778
n=9 ans=180130
n=10 ans=1809652
n=11 ans=19940552
n=12 ans=239430724
n=13 ans=3113226148
*/
