#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T&x){
x=0;char c=getchar();/*T fl=1;*/while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 100005
#define LL long long
LL a[N];
int cz[N];
int n;
LL c[N];
int vis[N];
LL ans;
int l[N],r[N];
int fl[N];
void xxr(){
	for(int i=1;i<=n;i++)c[i]=0;
	for(int i=1;i<=n;i++){
		int x=a[cz[i]];
		fl[cz[i]]=1;
		for(int j=l[cz[i]];j<=r[cz[i]];j++)
			if(!fl[j])
				c[j]+=x;
	}
	LL sum=0;
	for(int i=1;i<=n;i++)sum+=c[i],fl[i]=0;
	ans=Max(ans,sum);
}
void dfs(int u){
	if(u==n+1){
		xxr();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		cz[u]=i;
		dfs(u+1);
		vis[i]=0;
	}
}
LL an[N];
int main(){
	freopen("magic.in","r",stdin); 
	freopen("magic.out","w",stdout);
	read(n);
	int xxx=1145141919;
	for(int i=1;i<=n;i++)
		read(l[i]),read(r[i]),read(a[i]),xxx=Max(Max(i-l[i],r[i]-i),xxx);
	if(xxx<=0){
		puts("0");
		return 0;
	}
	if(n<=10){
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)for(int j=l[i];j<=r[i];j++)if(j!=i)c[j]+=a[i];
	c[n+1]=(1e18);
	for(int ijk=1;ijk<=n;ijk++){
		int k=n+1;
		for(int i=1;i<=n;i++)
			if(c[i]<c[k]&&fl[i]==0)k=i;
//		cout<<k<<' ';///////////
		fl[k]=1;
		for(int i=l[k];i<=r[k];i++){
			if(fl[i])continue;
			an[i]+=a[k];
			c[i]-=a[k];
		}
	}
//	puts("");
	LL sum=0;
	for(int i=1;i<=n;i++)sum+=an[i];
	printf("%lld",sum); 
	return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5

*/
