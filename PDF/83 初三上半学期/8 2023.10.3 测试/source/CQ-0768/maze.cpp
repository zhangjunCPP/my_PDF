#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
linux的虚拟机居然没有配置
肯定拦住最短的,也就是说拦的路是固定的 
不对,因为可以拦多次,那么它可以把你往一个方向去赶 
假设u通往出口节点的数目是sum[u]个
手玩了下样例,拦的路的确是固定的
设dp[u]表示u到出口节点最坏情况要走多久
从出口开始跑一个拓扑就行了? 
*/
int n,m,k,col[200005],vis[200005],d[200005],dp[200005],cnt,first[200005];
set<int> q[200005];
struct q1{
	int u,w,v,nex;
}a[400005];
void add(int u1,int w1,int v1){
	a[++cnt]={u1,w1,v1,first[u1]};
	first[u1]=cnt;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > p; 
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=k;i++){
		col[read()]=1;
	}
	for(int i=1;i<=n;i++){
		d[i]=read();
	}
	for(int i=1,x,y,z;i<=m;i++){
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
	}
	memset(dp,127,sizeof(dp));
	for(int i=1;i<=n;i++){
		if(col[i]){
			dp[i]=0;
			continue;
		}
		for(int j=first[i];j;j=a[j].nex){
			if(col[a[j].w]){
				q[i].insert(a[j].v);
				if((int)q[i].size()==d[i]+1)
					dp[i]=(*(--q[i].end()));
				else if((int)q[i].size()>d[i]+1){
					if(a[j].v<dp[i])
						dp[i]=(*(--q[i].lower_bound(dp[i])));
				}
			}
		}
		p.emplace(make_pair(dp[i],i));
	}
	while(!p.empty()){
		int k=p.top().second;
		p.pop();
		if(vis[k])
			continue;
		vis[k]=1;
		if(dp[k]>1e9)
			continue;
		for(int i=first[k];i;i=a[i].nex){
			q[a[i].w].insert(dp[k]+a[i].v);
			if((int)q[a[i].w].size()==d[a[i].w]+1){
				dp[a[i].w]=(*(--q[a[i].w].end()));
				p.emplace(make_pair(dp[a[i].w],a[i].w));
			}
			else if((int)q[a[i].w].size()>d[a[i].w]+1){
				if(dp[k]+a[i].v<dp[a[i].w]){
					dp[a[i].w]=(*(--q[a[i].w].lower_bound(dp[a[i].w])));
					p.emplace(make_pair(dp[a[i].w],a[i].w));
				}
			}
		}
	}
	if(dp[1]>1e9)
		work(-1);
	else
		work(dp[1]);
	return 0;
}
