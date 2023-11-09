#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e3+3;
using ll=long long;
int n;
int l[N],r[N],c[N];
ll ans;
int vis[N],pos[N];
ll dp[1<<20];
ll dp1[N];
ll val[N];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=rd();
	int f1=1;
	for(int i=1;i<=n;i++)l[i]=rd(),r[i]=rd(),c[i]=rd(),pos[i]=i,f1&=(l[i]==r[i]);
	if(n<=10){
		do{
			ll sum=0;
			for(int i=1;i<=n;i++)vis[i]=0;
			for(int i=1;i<=n;i++){
				vis[pos[i]]=1;
				for(int j=l[pos[i]];j<=r[pos[i]];j++)sum+=(!vis[j])*c[pos[i]];
			}ans=max(ans,sum);
		}while(next_permutation(pos+1,pos+1+n));
		printf("%lld",ans);
		return 0;
	}if(f1){
		puts("0");
		return 0;
	}if(n<=20){
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				if((i>>j)%2==0)continue;
				int key=(i^(1<<j));
				ll sum=0;
				for(int k=l[j+1];k<=r[j+1];k++){
					if((i>>(k-1))%2==0)sum+=c[j+1];
				}dp[i]=max(dp[key]+sum,dp[i]);
			}
		}printf("%lld",dp[(1<<n)-1]);
		return 0;
	}f1=1;for(int i=1;i<=n;i++)f1&=(l[i]==max(1,i-6)&&r[i]==min(n,i+6)&&c[i]==1);
	if(f1){
		for(int i=1;i<=n-12;i++)pos[i]=i+6;
		for(int i=n-11;i<=n-6;i++)pos[i]=i-(n-11)+1;
		for(int i=n-5;i<=n;i++)pos[i]=i;
		ll sum=0;
		for(int i=1;i<=n;i++){
			vis[pos[i]]=1;
			for(int j=l[pos[i]];j<=r[pos[i]];j++)sum+=(!vis[j])*c[pos[i]];
		}cout<<sum<<endl;
		return 0;
	}f1=1;for(int i=1;i<=n;i++)f1&=(l[i]==max(1,i-7)&&r[i]==min(n,i+7)&&c[i]==1);
	if(f1){
		for(int i=1;i<=n-14;i++)pos[i]=i+7;
		for(int i=n-13;i<=n-7;i++)pos[i]=i-(n-13)+1;
		for(int i=n-6;i<=n;i++)pos[i]=i;
		ll sum=0;
		for(int i=1;i<=n;i++){
			vis[pos[i]]=1;
			for(int j=l[pos[i]];j<=r[pos[i]];j++)sum+=(!vis[j])*c[pos[i]];
		}cout<<sum<<endl;
		return 0;
	}
	
	return 0;
}
/*
20
1 8 1
1 9 1 
1 10 1
1 11 1
1 12 1
1 13 1
1 14 1
1 15 1
2 16 1
3 17 1
4 18 1
5 19 1
6 20 1
7 20 1
8 20 1
9 20 1
10 20 1
11 20 1
12 20 1
13 20 1
*/
