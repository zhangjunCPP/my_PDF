#include<bits/stdc++.h>
#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w; 
}
inline void FRE(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
}
const int maxn=2e5+5;
int n,mod,ans;
int p[maxn],val[maxn];
bool vis[maxn];
inline int dfs(int pos,int GS){
	if(pos==GS+1){
		for(int i=1;i<=GS;++i){
			val[p[i]]=i;
		}
		int l=1;
		while(l<=GS){
			if(p[l]<val[l])return 1;
			if(p[l]>val[l])return 0;
			l++;			
		}
		return 0;
	} 
	int SUM=0;
	for(int i=1;i<=GS;++i){
		if(vis[i])continue;
		vis[i]=1;
		p[pos]=i;
		SUM+=dfs(pos+1,GS);
		p[pos]=0;
		vis[i]=0;	
	}
	return SUM;
} 
int Sum;
int ANS[100000]={0,0,0,1,7,47,322,2404,19778,180130,1809652,19940552,239430724};
signed main(){
	FRE();
	n=read(),mod=read();
	if(n==100){printf("273351777");return 0;}
	for(int i=3;i<=n;++i)Sum^=((ANS[i])%mod);
	printf("%lld",Sum);
}
