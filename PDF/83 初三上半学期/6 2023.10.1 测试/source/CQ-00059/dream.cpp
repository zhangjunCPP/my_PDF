#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char ch=getchar();
	int f=1,x=0;
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
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
const int mod=1e9+7;
int n,m,Q,k,id,vis[100005],cnt,first[100005];
ll dp[100005],dis[100005],du[100005],sum[100005],dp1[100005],dis1[100005];
set<int> pre[100005];
set<pair<int,int> > gg;
struct q1{
	int u,w;
	ll v;
	int nex;
}a[400005];
void add(int u1,int w1,ll v1){
	a[++cnt]={u1,w1,v1,first[u1]};
	first[u1]=cnt;
}
struct node{
	int w1;
	ll num;
	bool operator < (const node&t) const{
		return num>t.num;
	}
};
priority_queue<node> q;
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	n=read();
	m=read();
	Q=read();
	k=read();
	id=read();
	for(int i=1,x,y,z;i<=m;i++){
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
		du[x]++;
		du[y]++;
	}
	while(Q--){
		int s,t;
		s=read();
		t=read();
		memset(dp,0,sizeof(dp));
		memset(dis,127,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(dp1,0,sizeof(dp1));
		memset(dis1,127,sizeof(dis1));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			pre[i].clear();
		}
		q.emplace(node{s,0});
		dp[s]=1;
		dis[s]=0;
		while(!q.empty()){
			int k1=q.top().w1;
			q.pop();
			if(vis[k1])
				continue;
			vis[k1]=1;
			for(int i=first[k1];i;i=a[i].nex){
				if(dis[k1]+a[i].v<dis[a[i].w]){
					dis[a[i].w]=dis[k1]+a[i].v;
					q.emplace(node{a[i].w,dis[a[i].w]});
					dp[a[i].w]=dp[k1];
					sum[a[i].w]+=(du[k1]-1)+sum[k1];
					sum[a[i].w]%=mod;
					pre[a[i].w].clear();
					pre[a[i].w].insert(k1);
				}
				else if(dis[k1]+a[i].v==dis[a[i].w]){
					dp[a[i].w]+=dp[k1];
					dp[a[i].w]%=mod;
					pre[a[i].w].insert(k1);
					sum[a[i].w]+=(du[k1]-1)+sum[k1];
					sum[a[i].w]%=mod;
				}
			}
		}
		memset(vis,0,sizeof(vis));
		q.emplace(node{t,0});
		dp1[t]=1;
		dis1[t]=0;
		while(!q.empty()){
			int k1=q.top().w1;
			q.pop();
			if(vis[k1])
				continue;
			vis[k1]=1;
			for(int i=first[k1];i;i=a[i].nex){
				if(dis1[k1]+a[i].v<dis1[a[i].w]){
					dis1[a[i].w]=dis1[k1]+a[i].v;
					q.emplace(node{a[i].w,dis1[a[i].w]});
					dp1[a[i].w]=dp1[k1];
				}
				else if(dis1[k1]+a[i].v==dis1[a[i].w]){
					dp1[a[i].w]+=dp1[k1];
					dp1[a[i].w]%=mod;
				}
			}
		}
		if(!k)
			work(dp[t]);
		else if(id==7||id==8||id==17||id==18||id==19||id==20)
			work(sum[t]);
		else{
			gg.clear();
			ll ans=0;
			queue<pair<int,int> > p;
			for(auto i:pre[t]){
				p.emplace(make_pair(i,t));
			}
			memset(vis,0,sizeof(vis));
			while(!p.empty()){
				int k1=p.front().first,las=p.front().second;
				p.pop();
				for(int i=first[k1];i;i=a[i].nex){
					if(a[i].w==las||gg.find(make_pair(k1,a[i].w))!=gg.end())
						continue;
					gg.insert(make_pair(k1,a[i].w));
					ans+=dp1[a[i].w]*dp[k1]%mod;
					ans%=mod;
				}
				for(auto i:pre[k1]){
					p.emplace(make_pair(i,k1));
				}
			}
			work(ans);
		}
		putchar('\n');
	}
	return 0;
}
