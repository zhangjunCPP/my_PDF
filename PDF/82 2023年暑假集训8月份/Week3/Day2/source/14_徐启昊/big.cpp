#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<iterator>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define Genshin_Impact_starts ios::sync_with_stdio(false)
#define ll long long
#define F first
#define S second
#define eps 1e-6
#define For(i,s,t) for(int i=s;i<=t;i++)
#define rFor(i,s,t) for(int i=s;i>=t;i--)

using namespace std;

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void swap(int &a,int &b){a=a^b,b=a^b,a=a^b;}
void Freopen(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
}

const int N=1e4+10,M=1e6+10,inf=1e9+10,mod=998244353;
int n,m,q,tte,ttu,ans;
int du[N],us[N],vis[N],nd[N];
vector<int>G[N];
set<int>ss;
map<set<int>,int>l;
char s[N+1];
struct node{int u,v;}E[N],e[N];

void dfs(int k,set<int>ss){
	for(int i=1;i<=ttu;i++)if(du[nd[i]]<2)return;
	if(!l.count(ss))ans=(ans+1)%mod,l[ss]=1;
	for(int i=1;i<=tte;i++){
		if(!vis[i]){
			vis[i]=1;
			int u=E[i].u,v=E[i].v;
			du[u]--,du[v]--;
			ss.insert(i);
			dfs(k+1,ss);
			ss.erase(i);
			du[u]++,ss,du[v]++;
			vis[i]=0;
		}
	}
}

signed main(){
	Freopen();
	Genshin_Impact_starts;
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>E[i].u>>E[i].v;
	cin>>q;
	while(q--){
		ttu=tte=ans=0;
		ss.clear();
		l.clear();
		for(int i=0;i<=n;i++)us[i]=du[i]=0;
		cin>>s+1;
		for(int i=1;s[i];i++)if(s[i]=='1')us[i]=1,nd[++ttu]=i;
		for(int i=1;i<=m;i++){
			int u=E[i].u,v=E[i].v;
			if(us[u]&&us[v])e[++tte]=E[i],
				du[u]++,du[v]++;
		}
		int f=0;
		for(int i=1;i<=ttu;i++)if(du[nd[i]]>=2){
				f=1;
				break;
			}
		if(!f)return cout<<0,0;
		dfs(1,ss);
		cout<<ans<<endl;		
	}
}
