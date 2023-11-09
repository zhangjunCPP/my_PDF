#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
struct edge{
	int to,nxt;
}e[maxn<<2];
int head[maxn],tot;
void add(int u,int v){
	e[++tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
int n,m,ans,T;
bitset<maxn>b;
bool dfs(){
	for(int i=1;i<=n;i++){
		b=0;
		for(int j=head[i];j;j=e[j].nxt)b[e[j].to]=1;
		for(int j=head[i];j;j=e[j].nxt)
			for(int k=head[e[j].to];k;k=e[k].nxt)
				if(b[e[k].to]&&e[k].to!=i)return 1;
	}
	return 0;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;memset(head,0,sizeof head);
		cin>>n>>m;
		for(int i=1,u,v;i<=m;i++){
			cin>>u>>v;
			add(u,v);add(v,u);
		}
		for(int u=1;u<=n;u++){
			int res=0;
			for(int i=head[u];i;i=e[i].nxt)res++;
			ans=max(res,ans);
		}
		if(ans<3)if(dfs())ans=3;
		cout<<ans<<endl;
	}
	return 0;
}
