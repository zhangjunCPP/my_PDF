#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;char c=getchar();/*T fl=1;*/while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}/*x*=fl*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 200005
#define INF 1145141919
#define LINF (1e18)
#define LL long long
int n,m,k;
int t[N<<1],las[N<<1],fir[N],c[N<<1],num=1;
void add(int u,int v,int w){
t[++num]=v;las[num]=fir[u];fir[u]=num;c[num]=w;
t[++num]=u;las[num]=fir[v];fir[v]=num;c[num]=w;}
int ed[N];
int d[N];
LL dis[2][N];
int vis[N];
int fl[N<<1];
struct st{
	int id;
	LL d;
	bool operator < (const st& oth) const{
		return oth.d<d;
	}
};
priority_queue<st> q;
void dij(int mo){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)dis[mo][i]=LINF,vis[i]=0;
	if(mo==1){
		dis[mo][n]=0;
		q.push({n,0});
	}
	else{
		dis[mo][1]=0;
		q.push({1,0});
	} 
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=fir[u];i;i=las[i]){
			if(fl[i^mo])continue;
			if(dis[mo][u]+c[i]<dis[mo][t[i]]){
				dis[mo][t[i]]=dis[mo][u]+c[i];
				q.push({t[i],dis[mo][t[i]]});
			}
		}
	}
}
int ind[N];
int indd[N];
int cn[N];
int hv[N];
int topsort(){
	for(int u=1;u<=n;u++) 
		cn[u]=hv[u]=ind[u]=indd[u]=0;
	for(int u=1;u<=n;u++){
		for(int i=fir[u];i;i=las[i]){
			if(fl[i])continue;
			if((dis[1][u]==dis[1][t[i]]+c[i]&&dis[0][u]+c[i]==dis[0][t[i]])){
				ind[u]++;
				indd[u]++;
			}
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++)if(ind[i]==0)q.push(i);
	cn[n]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(cn[u]>d[u])cn[u]=1;
		else cn[u]=0;
		for(int i=fir[u];i;i=las[i]){
			if(fl[i^1])continue;
			if((dis[0][u]==dis[0][t[i]]+c[i]&&dis[1][u]+c[i]==dis[1][t[i]])){
				cn[t[i]]+=(bool)(cn[u]>0);
				if(--ind[t[i]]==0)q.push(t[i]);
			}
		}
	}
	int ret=cn[1]; 
	for(int u=1;u<=n;u++){
		if(cn[u])continue; 
		for(int i=fir[u];i;i=las[i]){
			if(fl[i])continue;
			if((dis[1][u]==dis[1][t[i]]+c[i]&&dis[0][u]+c[i]==dis[0][t[i]])){
				if(cn[t[i]]&&d[u]>0){
					d[u]--;
					fl[i]=1;
				}
			}
		}
	}
	for(int u=1;u<=n;u++){
		for(int i=fir[u];i;i=las[i]){
			if(fl[i])continue;
			if((dis[1][u]==dis[1][t[i]]+c[i]&&dis[0][u]+c[i]==dis[0][t[i]])){
				if(d[u]>0){
					d[u]--;
					fl[i]=1;
				}
			}
		}
	}
	return ret;
}
LL solve(){
	while(1){
		dij(0);
		dij(1);
		if(topsort())return dis[0][n]; 
	}
	return -1;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1,x;i<=k;i++)read(x),ed[x]=1;
	for(int i=1;i<=n;i++)read(d[i]);
	n++;
	for(int i=1;i<=m;i++){
		int x,y,z;
		read(x);
		read(y);
		read(z);
		if(ed[x]==1)x=n;
		if(ed[y]==1)y=n;
		if(x!=y)add(x,y,z);
	}
	printf("%lld",solve());
	return 0;
}
/*
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
