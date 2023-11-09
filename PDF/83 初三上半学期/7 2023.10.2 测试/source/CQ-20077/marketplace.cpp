//the code is from chenjh
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 100005
#define MAXM 1000005
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
bool vis[MAXM];
int ans[MAXN];
int check(const int x){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;++i>n&&(i=1)){
		if(!vis[a[i]] && a[i]!=x) vis[a[i]]=1;
		else if(!vis[b[i]] && b[i]!=x) vis[b[i]]=1;
		else return i;
	}
	return 0;
}
int main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=m;i++) ++ans[check(i)];
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}

