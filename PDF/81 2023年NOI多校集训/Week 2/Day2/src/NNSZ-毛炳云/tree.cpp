//情况A是一条链，感觉像dp 
//只会性质BC，每种情况贡献相同 
#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
const int N=2e6+5;
int n,du;
long long ans=1;

struct line{
	int to,pre;
}b[2*N];
int k,head[N];
void add(int x,int y){
	k++;
	b[k].to=y;
	b[k].pre=head[x];
	head[x]=k;
}
int dep[N],md=0;
bool vis[N];
void dfs(int x){
	md=max(md,dep[x]);
	vis[x]=1;
	for(int i=head[x];i;i=b[i].pre){
		int y=b[i].to;
		if(vis[y])continue;
		vis[y]=1;
		dep[y]=dep[x]+1;
		dfs(y);
	}
}


int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		if(x==1||y==1)du++;
	}
	if(n==1)printf("%d",0);
	else if(n==2)printf("%d",2);
	else if(n==3)printf("%d",12);
	else if(du==n-1){//性质B 
		for(int i=1;i<=n+1;i++){
			ans=ans*2%MOD;
		}
		printf("%lld",ans);
	}
	else{//性质C 
		dep[1]=1;
		dfs(1);
		int q=(md-1)*2;
		for(int i=1;i<=n;i++){
			ans=ans*2%MOD;
		}
		ans=ans*q%MOD;
		printf("%lld",ans);
	}
	return 0;
}
