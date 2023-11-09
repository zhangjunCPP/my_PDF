#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int MAXN=1e5+10;
int n,m,q,k,id;
struct node{
	int to,nxt,w;
}edge[MAXN<<1];
int head[MAXN],tot=0;
inline void add(int u,int v,int w){
	edge[++tot]={v,head[u],w}; head[u]=tot;
	return ;
}
int dis[MAXN],ans[MAXN];
void spfa(int s){
	queue<int> q; q.push(s);
	for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f; 
	dis[s]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to,w=edge[i].w;
			if(dis[v]>=dis[u]+w){
				if(dis[v]==dis[u]+w) ans[v]=ans[u]+1;
				dis[v]=dis[u]+w;
				q.push(v);
			}
		}
	}
}
int tmp[MAXN],num,cnt; bool vis[MAXN];
void bfs(int s,int t){
	queue<int> q,res; q.push(s),res.push(s);
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int u=q.front(); q.pop(); vis[u]=true;
		int k=res.front(); res.pop();
		if(k==t){
			cnt++; 
			int len=0; tmp[++len]=k;
			while(!res.empty()){
				int x=res.front(); res.pop();
				tmp[++len]=x;
				if(x==s) break;
			}
			reverse(tmp+1,tmp+len+1);
			for(int i=1;i<=len-1;i++){
				for(int j=head[tmp[i]];j;j=edge[j].nxt)
					if(edge[j].to!=tmp[i+1]) num++;
			}
		}
		if(cnt==ans[t]+1) return ;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(vis[v] && v!=t) continue;
			res.push(v); q.push(v);
		}
	}
}
int dep[MAXN],Ans; bool kk=false;
void dfs(int u,int t,int father,int step){
	if(kk) return ;
	if(u==t){
		kk=true;
		Ans=step;
		return ;
	}
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==father) continue;
		dfs(v,t,u,step+1);
		if(kk) return ;
	}
}
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&q,&k,&id);
	for(int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		dep[u]++; dep[v]++;
		add(u,v,w); add(v,u,w);
	}
	int cnt1=0,cnt2=0; bool fbi=true;
	for(int i=1;i<=m;i++){
		if(dep[i]!=1 || dep[i]!=2) fbi=false;
		cnt1+=(dep[i]==1);
		cnt2+=(dep[i]==2);
	}
	if(k==0){
		while(q--){
			int s,t; scanf("%d%d",&s,&t);
			spfa(s); 
			if(dis[t]==0x3f3f3f3f){puts("0"); continue;}
			printf("%d\n",(ans[t]+1)%mod); 
			memset(ans,0,sizeof ans); 
		}
	}
	else{
		if(fbi && cnt1==2 && cnt2){
			while(q--){
				int s,t; scanf("%d%d",&s,&t);
				dfs(s,t,0,0);
				printf("%d\n",Ans%mod);
			}
		}
		while(q--){
			int s,t; scanf("%d%d",&s,&t);
			spfa(s); 
			if(dis[s]==0x3f3f3f3f){puts("0"); continue;}
			bfs(s,t); printf("%d\n",num%mod);
		}
	}
	return 0;
}
/*
5 7 1 0 0
1 2 1
1 3 2
2 3 1
3 4 1
3 5 2
4 5 1
2 4 2
1 5
*/
