#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w; 
}
inline void FRE(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
}
const int maxn=4000+5;
int n,cnt,ans=0x3f3f3f3f,lst;
int siz[maxn];
int group[maxn][maxn];
int w[maxn],val[maxn][maxn];
int dp[maxn];
vector<int> a[maxn];
inline void add(int u,int v){a[u].push_back(v);}
inline void dfs(int u,int FA){
	int sum=0;
	for(int v:a[u]){
		if(v==FA)continue;
		sum++;
		dfs(v,u);
		for(int i=lst;i<=cnt;++i)group[i][++siz[i]]=u;
	}
	if(sum==0)group[++cnt][++siz[cnt]]=u;
}
int main(){
	FRE();
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		cnt=0;
		mem(group,0);
		mem(siz,0);
		lst=1;
		for(int v:a[i]){
			dfs(v,i);	
			lst=cnt+1;
		}		
		for(int j=1;j<=cnt;++j){//第几组 
			for(int k=1;k<=siz[j];++k){//哪一个 
				val[j][k]=w[group[j][k]];
			}
		}
		int SUM=-1;
		for(int j=1;j<=cnt;++j){
			dp[1]=1;
			for(int k=2;k<=siz[j];++k){
				dp[k]=1;
				for(int z=1;z<k;++z){
					if(val[j][k]>val[j][z])dp[k]=max(dp[k],dp[z]+1);
				}	
			}
			SUM=max(SUM,dp[siz[j]]);
			mem(dp,0);
			dp[siz[j]]=1;
			for(int k=siz[j]-1;k>=1;--k){
				dp[k]=1;
				for(int z=siz[j];z>k;--z){
					if(val[j][k]>val[j][z])dp[k]=max(dp[k],dp[z]+1);
				}
			}
			SUM=max(SUM,dp[1]);
		}
		ans=min(ans,SUM);
	}
	printf("%d",ans);	
}
/*
5
1 2
2 3
3 4
4 5
1 2 3 4 5
*/
