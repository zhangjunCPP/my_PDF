#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define fi first
#define se second
#define pb push_back
#define pii pair<LL,LL>
#define mem(a,x) memset((a),(x),sizeof(a))

//#define long long int
#define LLL __int128

template<typename type>
inline void read(type &x)
{
    x=0;bool flag(0);char ch=getchar();
    while(!isdigit(ch)) flag=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    flag?x=-x:0;
}

template<typename type>
inline void write(type x,bool mode=1)//0为空格，1为换行
{
    x<0?x=-x,putchar('-'):0;static short Stack[50],top(0);
    do Stack[++top]=x%10,x/=10; while(x);
    while(top) putchar(Stack[top--]|48);
    mode?putchar('\n'):putchar(' ');
}

LL qsm(LL a,LL b,LL mod){
	LL ans=1,sum=a;
	while(b){
		if(b&1) ans=ans*sum%mod;
		sum=sum*sum%mod;
		b>>=1;
	}
	return ans;
}

const LL N=1e3+10,M=1e6+10,mod=1e9+7;

LL n;

vector<LL> g[M];

LL dis[N][N];

LL dag[M],sum[M];

bool checkA(){
	for(LL i=1;i<=n;i++) sum[dag[i]]++;
	if(sum[1]==2&&sum[2]==n-2){
		return true;
	}
	return false;
}

bool checkB(){
	if(dag[1]==n-1) return true;
	return false;
}

void doA(){
	LL ans=0;
	for(LL s=0;s<n;s++){
		LL r=min(s+2,n);
		LL l=max(n-s-1,(LL)1);
		if(l>=r) continue;
		ans+=qsm(2,r-l,mod)*s;
	}
	printf("%lld\n",ans);
}

void doB(){
	if(n>=4){
		printf("%lld\n",qsm(2,n+1,mod));
	}
	else{
		doA();
	}
}

bool vis[M];

void bfs(LL st){
	queue<pair<LL,LL> > q;
	for(LL i=1;i<=n;i++) vis[i]=false;
	q.push({st,0});
	while(!q.empty()){
		pair<LL,LL> tp=q.front();
		q.pop();
		if(vis[tp.first]) continue;
		vis[tp.first]=true;
		dis[st][tp.first]=tp.second;
		for(LL x:g[tp.first]){
			if(vis[x]) continue;
			q.push({x,tp.second+1});
		}
	}
}

LL dep[M];

void dfs(LL u,LL fa,LL &ans){
	if(fa==-1) dep[u]=1;
	else dep[u]=dep[fa]+1;
	if(dep[u]>dep[ans]) ans=u;
	for(LL v:g[u]){
		if(v==fa) continue;
		dfs(v,u,ans);
	}
}

struct Node{
	LL v;
	LL dis;
};

bool cmp(Node x,Node y){
	return x.dis>y.dis;
}

vector<Node> gg[M];

queue<pair<LL,LL> > q;

LL bl[M];

LL f[M];

void solve(){
	read(n);
	for(LL i=1;i<n;i++){
		LL u,v;
		read(u);
		read(v);
		g[u].push_back(v);
		g[v].push_back(u);
		dag[u]++;
		dag[v]++;
	}
	if(checkA()){
		doA();
		return ;
	}
	if(checkB()){
		doB();
		return ;
	}
	for(LL i=1;i<=n;i++){
		bfs(i);
	}
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			gg[i].push_back({j,dis[i][j]});
		}
		sort(gg[i].begin(),gg[i].end(),cmp);
	}
	LL u=0,v=0;
	dfs(1,-1,u);
	dfs(u,-1,v);
	LL diss=dep[v]-dep[u];
	LL l=(diss-1)/2,r=diss,ans=0;
	for(LL i=l;i<=r;i++){
		while(!q.empty()) q.pop();
		q.push({1,0});
		LL gt=n;
		bool bll=true;
		for(LL j=1;j<=n;j++) bl[j]=-1;
		while(!q.empty()){
			pair<LL,LL> tp=q.front();
			q.pop();
			if(bl[tp.first]!=-1) continue;
			bl[tp.first]=tp.second;
			gt--;
			for(Node x:gg[tp.first]){
				if(x.dis<=i) break;
				if(bl[x.v]==-1){
					q.push({x.v,tp.second^1});
				}
				else if(bl[x.v]!=(tp.second^1)){
					bll=false;
					break;
				}
			}
			if(!bll) break;
		}
		if(bll){
			f[i]=qsm(2,gt+1,mod);
			if(i==l){
				ans=(ans+f[i]*i%mod)%mod;
			}
			else{
				ans=(ans+((f[i]-f[i-1])%mod+mod)%mod*i%mod)%mod;
			}
		}
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	LL T;
	T=1;
	while(T--){
		solve();
	}
}

