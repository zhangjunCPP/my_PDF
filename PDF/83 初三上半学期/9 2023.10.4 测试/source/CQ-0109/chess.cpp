#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
typedef long long ll;
const int N=2e5+10;
const ll INF=2e18;
void File(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
int n,p,k;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int vis[3001][3001]={0};
int aa=0;
queue<int>a[3004];
vector<vector<int>>Ans;
void solve(int x,int sum,int ans[]){
	if(sum==p){
		for(int i=1;i<=p;i++){
			for(int j=i+1;j<=p;j++) {
				if(vis[ans[i]][ans[j]]) return;
			}
			
		}
		
		Ans.pb({});
		for(int i=1;i<=p;i++){
			Ans[aa].pb(ans[i]);
		}
		aa++;
		for(int i=1;i<=p;i++){
			for(int j=i+1;j<=p;j++) vis[ans[i]][ans[j]]++;
		}
		return ;
	}
//	cout<<sum<<endl;
	if(a[x].empty()) return; 
	int u=a[x].front();
//	for(int i=1;i<=sum;i++){
//		if(vis[ans[i]][u]) return;
//	}
	a[x].pop();
	ans[sum+1]=u;
	solve(u,sum+1,ans);
}

int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	File();
	cin>>p>>k;
	n=qpow(p,k);
	if(p==2){
		cout<<n*(n-1)/2<<endl;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				cout<<i<<' '<<j<<endl;
			}
		}
		return 0; 
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			a[i].push(j);
		}
	}
	for(int i=0;i<n;i++){
		int pp[1001];
		pp[1]=i;
		while(a[i].size())solve(i,1,pp);
	}
	cout<<aa<<endl;
	for(auto i:Ans){
		for(auto j:i){
			cout<<j<<' ';
		} 
		cout<<endl;
	}
	return 0; 
} 
