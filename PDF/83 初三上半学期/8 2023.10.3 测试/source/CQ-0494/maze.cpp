#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
/*
���ڵ�ǰһ����u ����Ѿ�֪����������ÿ���ߵ�ʱ�� �����¾���ȡ��du+1С
Ȼ��һֱ��ô�� �ߵ�s�����еĵ� 
����ͼ�����Դ�ÿ���������dij ʱ�临�Ӷȸо��е�Σ�հ�������
80%Ӧ����û�����
�ð��Һ�������������е�����
����ÿ���� �����̵�·��ȷ���ģ� ������ɾ ��Ϊ�����߻��� �Ǿͱ�ɵ��� 
���������Ƕ�Դ��
����̰�ĵ�ѡ ����������ȥ ���߶���ѡ����
ֱ�����·Ҳ����
��ÿ��·���г�������
���߶���ѡҲ����֤�� 
���ȶ�ֱ��� ��Ȩ��С���� ��Щ�߿���ɾ
���� ÿ�����ǰdu���� �õ�du+1С�����º���ĵ� 
���ڼ�ı����� �����һ�����ߵ���һ�� 
����ͦ�ԣ� �ز�һ�£� ����ͼ�ظ�P
զ���㣬���У� �ֲ��� ��Դ ����ȡmax�� ��������ô�� 
����ͼ���������𡣡���һ��DAG�����ز� ��SCC�������ô�� 
*/
const int N=2e5+10;
int n,m,k,cnt,head[N],vis[N],d[N],deg[N],vis2[N],dis[N];
int tag[N],ans;
struct node{
	int to,w,next;
}e[N<<1];
struct edge{
	int u,v;
}edg[N<<1];
void add(int u,int v,int w){e[++cnt].to=v,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;}
priority_queue<PII,vector<PII>,greater<PII> > Q;
void dijkstra(int s){
	while(!Q.empty())Q.pop();
	for(int i=1;i<=n;++i)vis2[i]=0,dis[i]=2e9;
	dis[s]=0,Q.push({0,s});
	while(!Q.empty()){
		int u=Q.top().second;Q.pop();
		if(vis2[u])continue;
		vis2[u]=1;
		for(int i=head[u];i;i=e[i].next){
//			if(tag[i])continue;
			int v=e[i].to;
			if(vis2[v])continue;
			if(dis[v]>dis[u]+e[i].w)dis[v]=dis[u]+e[i].w,Q.push({dis[v],v});
		}
	}
}
bool check(int s,int wt){
	int res=0;
	while(s){
		if(s&1)++res;
		s>>=1;
	}
	return res==wt;
}
int dfs(int u,int fa,int dis){
//	if(now>m){
//		if(!check())return;
//		for(int i=1;i<=m;++i)cout<<tag[i]<<" ";
//		cout<<"\n";
//		dijkstra(1);
//		int res=2e9;
//		for(int i=1;i<=n;++i)
//			if(vis[i])res=min(res,dis[i]);
//		if(res!=2e9)ans=max(ans,res);
//		return;
//	}
//	tag[now]=1,dfs(now+1);
//	tag[now]=0,dfs(now+1);
	tag[u]=1;
	if(vis[u]){
		return dis;
	}
	int res=0;
	for(int s=(1<<deg[u])-1;~s;--s){
		int minn=0;
		if(!check(s,d[u]))continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(v==fa||tag[v])continue;
			if(!((s>>(i-1))&1)){
				int tmp=dfs(v,u,dis+e[i].w);
				if(tmp>0)minn=max(minn,tmp);
			}
		}
		if(minn!=2e9)res=max(res,minn);
	}
	tag[u]=0;
	return res?res:-1;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;++i){
		int x=read();
		vis[x]=1;
	}
	for(int i=1;i<=n;++i)d[i]=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w),++deg[u],++deg[v],edg[i].u=u,edg[i].v=v;
	}
	for(int i=1;i<=n;++i)
		if(d[i]>=deg[i]){printf("-1\n");return 0;}
	if(n<=15&&m<=15){
		ans=dfs(1,0,0);
		printf("%d\n",ans?ans:-1);
	}else{
		dijkstra(1);
		for(int i=1;i<=n;++i){
			if(vis[i])ans=max(ans,dis[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
7 15 2
4 7
2 0 0 1 0 0 0
1 2 7
1 3 5
1 4 1
3 5 4
4 6 3
3 7 7
4 3 4
7 1 4
5 6 3
2 3 7
7 5 3
4 7 4
6 2 7
2 4 4
6 7 6

5 8 3
2 3 5
2 0 1 1 2
1 2 1
2 3 2
3 4 5
2 5 3
4 5 2
5 1 3
3 5 2
4 1 1
*/
