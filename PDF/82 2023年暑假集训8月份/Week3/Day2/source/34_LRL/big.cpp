#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=180;
const int mod=998244353;
int n,m,q,head[N],cnt,U[N],V[N],deg[N];
struct node{
	int to,next;
}e[N<<1];
void add(int u,int v){e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;}
bool check(int t,int s){
	for(int i=1;i<=n;++i)deg[i]=0;
	for(int i=1;i<=m;++i){
		if(t&(1<<(i-1))){
			if((!(s&(1<<(U[i]-1))))||(!(s&(1<<(V[i]-1)))))return false;
			++deg[U[i]],++deg[V[i]];
		}
	}
	for(int i=1;i<=n;++i)
		if((s&(1<<(i-1)))&&(deg[i]<2))return false;
	return true;
}
int solve(int x){
	int tmp=x,res=0,now=0;
	while(tmp){
		if(tmp%10)res=res|(1<<(n-now-1));
		tmp/=10,++now;
	}
	return res;
}
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		U[i]=read(),V[i]=read();
	}
	q=read();
	while(q--){
		int s=read(),ans=0;
		s=solve(s);
		for(int t=(1<<m)-1;t;t=((1<<m)-1)&(t-1)){
			if(check(t,s))ans=(ans+1)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
