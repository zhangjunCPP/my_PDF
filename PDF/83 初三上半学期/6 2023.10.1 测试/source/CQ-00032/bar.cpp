using namespace std;
#include<bits/stdc++.h>
#define int long long 
#define LLL int
#define N 100005
#define INF (1e18)
#define M 100005
#define P 1000000007
template<typename T>
void read(T&x){x=0;char c=getchar();/*int fl=1;*/
while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
int n,m,k;
int t[M],las[M],fir[N],num;
LLL c[M];
void add(int u,int v,LLL w){
//	cout<<u<<"   "<<v<<"   "<<w<<endl;
t[++num]=v;c[num]=w;las[num]=fir[u];fir[u]=num;}
struct st{
	int id;
	LLL d;
	bool operator < (const st& oth) const{return oth.d<d;}
};
priority_queue<st>q1;
LLL dis[N];
int vis[N];
void dij(int u){
	while(q1.size())q1.pop();
	for(int i=1;i<=n;i++)dis[i]=INF,vis[i]=0;
	dis[u]=0;
	q1.push({u,0});
	while(!q1.empty()){
		int u=q1.top().id;
		q1.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=fir[u];i;i=las[i]){
			if(dis[u]+c[i]<dis[t[i]]){
				dis[t[i]]=dis[u]+c[i];
				q1.push({t[i],dis[t[i]]});
			}
		}
	}
}
struct st2{
	vector<int> a;
	int d;
	bool operator < (const st2& oth) const{
		if(d+dis[a.back()]!=oth.d+dis[oth.a.back()])
			return d+dis[a.back()]>oth.d+dis[oth.a.back()];
		for(int i=0;i<(int)Min(a.size(),oth.a.size());i++)
			if(a[i]!=oth.a[i])return a[i]>oth.a[i];
		return a.size()>oth.a.size();
	}
};
priority_queue<st2>q2;
vector<int> vv={1,5,8,20,46,47,50};
void Ax(int u){
	while(q2.size())q2.pop();
	q2.push({{u},0});
	while(!q2.empty()){
		int d=q2.top().d;
		int u=q2.top().a.back();
		vector<int> v=q2.top().a;
//		if(v==vv)cout<<d<<endl;
		if(v.back()==n){
			k--;
			if(k==0){
//				cout<<d<<":::";
				printf("%lld\n",(int)v.size());
				for(int i:v)printf("%lld ",i);
				exit(0);
//				puts("-----");
			}
		}
		q2.pop();
		for(int i=fir[u];i;i=las[i]){
			int fl=0;
			for(int j:v)if(j==t[i])fl=1;
			if(fl)continue;
			v.push_back(t[i]);
			q2.push({v,d+c[i]});
			v.pop_back();
		}
	}
}
signed main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1,x,y,z;i<=m;i++)
		read(x),read(y),read(z),add(x,y,z);
//	dij(1);
	Ax(1);
	puts("-1");
	return 0;
}
/*
4 6 5
2 4 2
1 3 2
1 2 1
1 4 3
2 3 1
3 4 1
*/
