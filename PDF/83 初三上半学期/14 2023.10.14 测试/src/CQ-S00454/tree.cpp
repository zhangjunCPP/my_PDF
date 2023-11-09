#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mid ((l+r)>>1)
const int N=1e6+5;
int n,cnt,head[N],U[N],V[N];
int vis[N],ans[100000][15],len[100000],res[15],top,tot;
void dfs(int k) {
	if(k==n) {
		for(int i=1;i<=tot;i++) {
			int flag=0;
			if(len[i]!=top) continue;
			for(int j=1;j<=len[i];j++) {
				if(ans[i][j]!=res[j]) flag=1;
			}
			if(!flag) return;
		}
		tot++;
		return;
	}
	int x=U[k],y=V[k];
	if(!vis[x]&&!vis[y]) {
		vis[x]=1,res[++top]=x;
		dfs(k+1);
		vis[x]=0,top--;
		vis[y]=1,res[++top]=y;
		dfs(k+1);
		vis[y]=0,top--;
	}
	else dfs(k+1);
}
signed main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	int flag=0;
	for(int i=1;i<n;i++) {
		scanf("%d%d",&U[i],&V[i]);
		if(U[i]!=1) flag=1;
	}
	if(!flag) {
		printf("%d",n);
		return 0;
	}
	dfs(1);
	printf("%d",tot);
	return 0;
}
