#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> tp;
const int N=2e5+5;
const ll mod=998244353;
int n,m;
int a[N];
bool vis[N];
int prime[N],whi[N],tt;
struct quec{
	int l,r,id;
}q[N];
void init(int un){
	for(int i=2;i<=un;i++){
		if(!vis[i]) prime[++tt]=i,whi[i]=tt;
		for(int j=1;j<=tt&&prime[j]*i<=un;j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
	return ;
}
namespace sol1{// n=2e4 => 43pts
	const int N=2e5+5;
	ll pw2[N];
	int ans[N];
	int blo[N],siz;
	vector<tp> num[N];
	map<int,int> cnt[N];
	bool cmp(quec a,quec b){
		if(blo[a.l]==blo[b.l])
			return a.r>b.r;
		else
			return blo[a.l]<blo[b.l];
	}
	void prework(){
		int mxw=0;
		for(int i=1;i<=n;i++)
			mxw=max(mxw,a[i]);
		init(mxw);
		for(int i=1;i<=n;i++){
			int x=a[i];
			for(int j=2;j*j<=x;j++){
				if(x%j!=0) continue;
				int ct=0;
				while(x%j==0) x/=j,ct++;
				num[i].push_back({j,ct});
			}
			if(x>1) num[i].push_back({x,1});
		}
		siz=sqrt(n);
		for(int i=1;i<=n;i++)
			blo[i]=(i-1)/siz+1;
		sort(q+1,q+m+1,cmp);
		pw2[0]=1;
		for(int i=1;i<=2e5;i++)
			pw2[i]=pw2[i-1]*2ll%mod;
		return ;
	}
	void add(int i){
		for(tp u:num[i])
			cnt[u.first][u.second]++;
		return ;
	}
	void del(int i){
		for(tp u:num[i])
			cnt[u.first][u.second]--;
		return ;
	}
	ll pow(ll a,ll b){
		ll rs=1;
		while(b){
			if(b&1) rs=(ll)rs*a%mod;
			a=(ll)a*a%mod,b>>=1;
		}
		return rs;
	}
	ll get(){
		ll ans=1;
		for(int k=1;k<=tt;k++){
			ll sum=0,res=0;
			ll pr=prime[k];
			for(auto u:cnt[pr])
				sum+=u.second;
			for(auto u=cnt[pr].begin();u!=cnt[pr].end();u++){
				ll ct;
				if(u==cnt[pr].begin())
					ct=u->first;
				else{
					auto v=u;v--;
					ct=u->first-v->first;
				}
//				int us=pow(pow(pr,ct),(pow(2,sum)-1+mod)%mod);
				ll us=(ll)ct*((pw2[sum]-1ll+mod)%mod)%mod;
//				res=(ll)res*us%mod;
				res=(res+us)%mod;
				sum-=u->second;
			}
			ans=(ll)ans*pow(pr,res)%mod;
		}
		return ans;
	}
	void debug(){
		for(int i=1;i<=tt;i++){
			cout<<prime[i]<<" :\n";
			for(auto u:cnt[prime[i]])
				cout<<u.first<<' '<<u.second<<'\n';
			cout<<'\n';
		}
	}
	void solve(){
		prework();
		int l=1,r=0;
		for(int i=1;i<=m;i++){
			while(r<q[i].r) add(++r);
			while(l>q[i].l) add(--l);
			while(r>q[i].r) del(r--);
			while(l<q[i].l) del(l++);
//			debug();
			ans[q[i].id]=get();
//			cout<<"ok\n";
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<'\n';
		return ;
	}
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int ti=clock();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>q[i].l>>q[i].r,q[i].id=i;
	sol1::solve();
	cerr<<clock()-ti;
	return 0;
}
