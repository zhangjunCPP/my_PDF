//the code is from xhb.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*w;
}
inline void fre(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
}
const int N=2e5+5;
int n,k,cnt,tot,ans=1e9;//Ê±¼ä´Á
int col[N],sum[N],vis[N],A[N],in[N],fa[N],rev[N]; 
vector<int> a[N],G[N];
inline void add(int u,int v){
	a[u].push_back(v);
}
inline void dfs(int u,int FA){
	fa[u]=FA;
	if(col[u]!=col[FA]){
		A[++cnt]=col[u];
		rev[u]=cnt;
		G[col[u]].push_back(cnt); 
		int si=G[col[u]].size();
		if(si>1){
			++tot;
			int x_=0;
			for(int i=fa[u];i!=0&&col[i]!=A[G[col[u]][si-2]];i=fa[i]){
				if(vis[A[rev[i]]]!=tot){
					vis[A[rev[i]]]=tot;
					x_++;
				}
			}
			sum[col[u]]+=x_;
		}
	}
	else rev[u]=cnt;
	for(int v:a[u]){
		if(v==FA)continue;
		dfs(v,u);
	}
} 
int main(){
	fre();
	n=read();k=read();
	for(int i=1;i<n;++i){
		int x=read(),y=read();
		add(x,y);add(y,x);in[x]++;in[y]++;
	}
	for(int i=1;i<=n;++i)col[i]=read();
	for(int i=1;i<=n;++i){
		if(in[i]==1){
			dfs(i,0);
			break;
		}
	}
	for(int i=1;i<=k;++i)ans=min(ans,sum[i]);
	printf("%d",ans);
	return 0;
}
/*
5 
1 2
2 3
3 4
4 5
1 2 1 2
*/

