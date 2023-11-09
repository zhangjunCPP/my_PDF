#include<bits/stdc++.h> 
using namespace std;
int n,m,q;
int head[10005],ver[20005],nxt[20005],value[20005],num=1;
int dp[10005][205],ID[10005],rnk[205],vis[10005],tot;
void add(int u,int v,int w){ver[num]=v,value[num]=w,nxt[num]=head[u],head[u]=num++;}
struct Node{int u,v,ID,ans;};
vector<Node> ask;
void init_read(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=2,u,v;i<=m;i++)scanf("%d%d",&u,&v),add(u,v,i),add(v,u,i);
	for(int i=1,u,v;i<=q;i++)scanf("%d%d",&u,&v),ask.push_back(Node{u,v,i,0});
	vis[m]=1;
	for(int i=m;i!=1;i--)if(vis[i]){
		rnk[++tot]=i;ID[i]=tot;
		for(int j=1;j<m;j++)vis[i/j]=1;
	}
}
void Freopen(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
}
int main(){
	Freopen();
	init_read();
	sort(ask.begin(),ask.end(),[](const Node &a,const Node &b){return a.v<b.v;});
	for(int l=0,r=0;l<(int)ask.size();l=++r){
		while(r+1<(int)ask.size()&&ask[r+1].v==ask[r].v)++r;
		int t=ask[r].v;
		memset(dp,-1,sizeof(dp));
		dp[t][0]=1;
		for(int k=tot;k;k--){
			dp[t][k]=1;
			for(int s=1;s<=n;s++){
				for(int i=head[s];i;i=nxt[i])if(value[i]<=rnk[k])
					dp[s][k]=dp[ver[i]][ID[rnk[k]/value[i]]]==-1?dp[s][k]:max(dp[ver[i]][ID[rnk[k]/value[i]]]*value[i],dp[s][k]);
			}
		}
		for(int i=l;i<=r;i++)
			ask[i].ans=dp[ask[i].u][1];
	}
	sort(ask.begin(),ask.end(),[](const Node &a,const Node &b){return a.ID<b.ID;});
	for(int i=0;i<(int)ask.size();i++) 
		printf("%d\n",ask[i].ans);
}
