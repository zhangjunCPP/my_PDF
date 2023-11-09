#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
const int Maxn=2e5+5;
const int Mod=998244353;
int  pri[Maxn],tot;
bool vis[Maxn];
void init(int n){
	for(int i=2;i<=n;++i){
		if(!vis[i])pri[++tot]=i;
		for(int j=1;1ll*i*pri[j]<=n&&j<=tot;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
ll quickly_power(ll a,int b){
	ll res=1;
	for(;b;b>>=1,(a*=a)%=Mod)if(b&1)(res*=a)%=Mod;
	return res;
}
int a[Maxn];
int L[Maxn],R[Maxn];
ll ans[Maxn];
vector<int>vec[Maxn];
vector<int>tmp;
int main(){
//	freopen("ex_ddickky/ex_sub1.in","r",stdin);
//	freopen("ddickky.out","w",stdout);
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init(2e5);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=q;++i)cin>>L[i]>>R[i],ans[i]=1;
	for(int i=1;i<=n;++i){
		int x=a[i];
		for(int j=1;j<=tot&&1ll*pri[j]*pri[j]<=x;++j){
			if(x%pri[j]==0)vec[pri[j]].emplace_back(i);
			while(x%pri[j]==0)x/=pri[j];
		}
		if(x!=1)vec[x].emplace_back(i);
	}
	for(int i=1;i<=tot;++i)while(!vec[pri[i]].empty()){
		tmp.resize(0);
		for(int j=1;j<=q;++j){
			int a=lower_bound(vec[pri[i]].begin(),vec[pri[i]].end(),L[j])-vec[pri[i]].begin();
			int b=upper_bound(vec[pri[i]].begin(),vec[pri[i]].end(),R[j])-vec[pri[i]].begin()-1;
//			cout<<pri[i]<<' '<<i<<' '<<j<<' '<<a<<' '<<b<<'\n';
//			system("pause");
			if(a>b)continue;
			int c=quickly_power(2,b-a+1)-1;
			(ans[j]*=quickly_power(pri[i],c))%=Mod;
		}
		for(auto j:vec[pri[i]]){
			a[j]/=pri[i];
			if(a[j]%pri[i]==0)tmp.emplace_back(j);
		}
		vec[pri[i]].swap(tmp);
	}
	for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}
