#include<bits/stdc++.h>
#define il inline
#define int long long
using namespace std;
const int N=2e5+5;
const int inf=1e9+7;

il int wrd(){
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
	while(isdigit(c)){x=x*10+c-48,c=getchar();}
	return x*f;
}

int n,P,ans,tot[N];

int p[N],q[N];
bool vis[N];

int v[15]={0,0,0,1,7,47,322,2404,19778,180130,1809652,19940552};
int a[N];

void dfs(int x,int y){
	if(x>y){
		for(int i=1;i<=y;++i) q[p[i]]=i;
		for(int i=1;i<=y;++i){
			if(p[i]>q[i]) return;
			if(p[i]<q[i]){
				(++tot[y])%=P;
				return;
			}
		}
	}
	for(int i=1;i<=y;++i){ 
		if(vis[i]) continue;
		vis[i]=1,p[x]=i,q[i]=x;
		dfs(x+1,y);
		vis[i]=0;
	}
}

signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	n=wrd(),P=wrd();
	if(P==998244353){
		 for(int i=3;i<=11;++i) a[i]=a[i-1]^v[i];
		 if(n<=11) printf("%lld",a[n]);
	}else{
		if(n<=11){
			for(int i=3;i<=n;++i) dfs(1,i),ans^=tot[i];
			printf("%lld",ans);
		}else{
			
		}
	}
	return 0;
}