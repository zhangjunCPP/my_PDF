using namespace std;
#include<bits/stdc++.h>
#define int long long 
//#define LLL __int128
#define LLL int
#define N 200005
#define INF (1e18)
#define M 400005
#define P 1000000007
template<typename T>
void read(T&x){x=0;char c=getchar();/*int fl=1;*/
while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
int n,m,q,k,id;
int t[M],las[M],fir[N],num;
LLL c[M];
void add(int u,int v,LLL w){
//	cout<<u<<"   "<<v<<"   "<<w<<endl;
t[++num]=v;c[num]=w;las[num]=fir[u];fir[u]=num;
t[++num]=u;c[num]=w;las[num]=fir[v];fir[v]=num;}
struct st{
	int id;
	LLL d;
	bool operator < (const st& oth) const{return oth.d<d;}
};
//从这往后的都要重置 
priority_queue<st>que;
LLL dis[N];
int vis[N];
void dij(int u){
	while(que.size())que.pop();
	for(int i=1;i<=n;i++)dis[i]=INF,vis[i]=0;
	dis[u]=0;
	que.push({u,0});
	while(!que.empty()){
		int u=que.top().id;
		que.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=fir[u];i;i=las[i]){
			if(dis[u]+c[i]<dis[t[i]]){
				dis[t[i]]=dis[u]+c[i];
				que.push({t[i],dis[t[i]]});
			}
		}
	}
}
int cnt[N];//每个点可走的最短路点数（出度） 
int d[N];//入度 
int d2[N];//入度 
int dp[N][2];
queue<int> Q;
#define f(u) (((u)-1)%n+1)
void top_sort(int u,int v){
	//DP硬转容易出顺序问题，采用拆点。用1~n、n+1~2n来区分两层
	//拆你妈点啊，就两遍DP 
	while(Q.size())Q.pop();
	for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=0;
	dp[u][0]=1;
	for(int i=1;i<=n;i++)if(d[i]==0)Q.push(i);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		if(u==v)continue;
		for(int i=fir[u];i;i=las[i]){
			if(dis[u]==dis[t[i]]+c[i]){
				dp[t[i]][0]=(dp[t[i]][0]+dp[u][0])%P;
				if(--d[t[i]]==0)Q.push(t[i]);
				if(cnt[u]>1)
					dp[t[i]][1]=(dp[t[i]][1]+dp[u][0])%P;
			}
			else{
				dp[t[i]][1]=(dp[t[i]][1]+dp[u][0])%P;
			}
		}
	}
	while(Q.size())Q.pop();
	for(int i=1;i<=n;i++)if(d2[i]==0)Q.push(i);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int i=fir[u];i;i=las[i]){
			if(dis[u]==dis[t[i]]+c[i]){
				dp[t[i]][1]=(dp[t[i]][1]+dp[u][1])%P;
				if(--d2[t[i]]==0)Q.push(t[i]);
			}
		}
	}
}

//map<pair<int,int>,int> mp;
//map<pair<int,int>,int> ct;
int ask(int u,int v){
	for(int i=1;i<=n;i++)cnt[i]=d[i]=d2[i]=0;
	dij(v);
//	cout<<":"<<dis[n]<<endl;
//	for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
//	puts("_");
	for(int u=1;u<=n;u++)
		for(int i=fir[u];i;i=las[i])
			if(dis[u]==dis[t[i]] +c[i]){
//				cnt[u]+=ct[{Min(u,t[i]),Max(u,t[i])}],d[t[i]]++,d2[t[i]]++;
				
				cnt[u]++,d[t[i]]++,d2[t[i]]++;
				
			}
	top_sort(u,v);
//	for(int i=1;i<=n;i++)cout<<dp[i][0]<<' ';
//	puts("");
//	for(int i=1;i<=n;i++)cout<<dp[i][1]<<' ';
//	puts("::");
	return dp[v][k];
}
signed main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	read(n);
	read(m);
	read(q);
	read(k);
	read(id);
	for(int i=1;i<=m;i++){
		int x,y;
		LLL z;
		read(x),read(y),read(z);
		add(x,y,z);
//		if(x>y)swap(x,y);
//		ct[{x,y}]++;
//		if(mp.find({x,y})==mp.end())mp[{x,y}]=z;
//		else mp[{x,y}]=Min(mp[{x,y}],z);
	}
//	map<pair<int,int>,int>::iterator p;
//	for(p=mp.begin();p!=mp.end();p++)
//		add(p->first.first,p->first.second,p->second);
	for(int i=1;i<=q;i++){
		int u,v;
		read(u);
		read(v);
		printf("%lld\n",ask(u,v));
	}
	return 0;
}
/*
4 5 2 1 0
1 2 1
2 3 1
1 3 2
2 4 5
3 4 2
1 3
1 4
*/
/*
4 6 2 1 0
1 2 1
2 3 1
1 3 2
2 4 5
3 4 2
3 4 100
1 3
1 4
*/
