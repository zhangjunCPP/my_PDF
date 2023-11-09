#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6+10;
const ll INF=1e18;
ll n,m,K,id[maxn],p[maxn],d[maxn],tmp[maxn],vis[maxn],v[maxn];
ll dp[maxn],bk[maxn];
vector<ll>pos[maxn];
struct node{
	ll data,nxt,val;
}a[maxn];
ll first[maxn],cnt;
void add(ll x,ll y,ll val){
	a[++cnt].data=y;
	a[cnt].val=val;
	a[cnt].nxt=first[x];
	first[x]=cnt;
}
void check(){
	for(ll i=1;i<=n;i++)tmp[i]=d[i];
	queue<ll>q;
	for(ll i=1;i<=K;i++)q.push(id[i]);
	while(q.size()){
		ll x=q.front();q.pop();
		for(ll i=first[x];i;i=a[i].nxt){
			ll k=a[i].data;
			d[k]--;
			if(d[k]<0&&vis[k]==0){
				vis[k]=1;q.push(k);
			}
		} 
	}
	if(!vis[1]){
		cout<<-1;
		return ;
	}
	for(ll i=1;i<=n;i++)d[i]=tmp[i];
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>K;
	for(ll i=1;i<=K;i++)cin>>id[i],vis[id[i]]=v[id[i]]=1,p[id[i]]=1;
	for(ll i=1;i<=n;i++)cin>>d[i],bk[i]=d[i];
	for(ll i=1;i<=m;i++){
		ll x,y,val;
		cin>>x>>y>>val;
		add(x,y,val),add(y,x,val);
	}
	check();
	queue<ll>q;
	for(ll i=1;i<=K;i++)q.push(id[i]),dp[id[i]]=0;
//	for(ll i=1;i<=n;i++)cout<<dp[i]<<endl;
	while(q.size()){
		ll x=q.front();q.pop();
//		if(x==4)cout<<pos[x].size()<<endl;
		if(pos[x].size()){
			sort(pos[x].begin(),pos[x].end());
			dp[x]=pos[x][bk[x]];
		}
		for(ll i=first[x];i;i=a[i].nxt){
			ll k=a[i].data;
			d[k]--;
			if(d[k]<0&&v[k]==0)q.push(k),v[k]=1;
			if(vis[k]&&p[k]==0){
				pos[k].push_back(dp[x]+a[i].val);
			}
		}
	}
//	for(ll i=1;i<=n;i++)cout<<v[i]<<" ";
	cout<<dp[1];
	return 0;
}
//能反应的过来吗，老弟？
//包反应的啊 
