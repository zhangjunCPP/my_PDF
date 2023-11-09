#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int MAXN=20;
const int mod=65535;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
} 
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int T,ans=1;
int x[MAXN],y[MAXN];
int num[MAXN<<1],n,p[MAXN<<1];
bool vis[MAXN<<1];
inline void work(){
	int sum=(int)0;
	for(int i=(int)1,base=(int)1;i<=n;i++,base=base*(int)256%mod)
		sum=((sum+p[i]*base%mod+mod)%mod)%mod;
	ans=(ans*sum%mod+mod)%mod;
}
void dfs(int t){
	if(t==n+1){
		work();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[t]=num[i];
			dfs(t+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	read(T);
	while(T--){
		n=0; ans=1;
		memset(num,0,sizeof(num)); 
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		int k; read(k);
		for(int i=1;i<=k;i++) read(x[i],y[i]);
		for(int i=1;i<=k;i++)
			for(int j=1;j<=y[i];j++)
				num[++n]=x[i];
//		printf("n: "); write(n); putchar('\n');
		dfs(1); write(ans); putchar('\n');
	}
	return 0;
}

