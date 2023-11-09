#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int G[55][55];
struct node{
	int val;
	string s;
};
inline bool operator <(string x,string y){
	int l=min(x.length(),y.length());
	for(int i=0;i<l;i++){
		if(x[i]<y[i]) return true;
		if(x[i]>y[i]) return false;
	}
	if(x.length()<y.length()) return true;
	return false;
}
inline bool cmp(node x,node y){
	if(x.val==y.val) return x.s<y.s;
	return x.val<y.val;
}
vector<node> ans;
int vis[55],d[55];
inline void dfs(int now,int dep,int val){
	if(now==dep+1){
		if(d[dep]!=n) return ;
		string sum;
		sum.clear();
		for(int i=1;i<=dep;i++){
			sum+=('0'+d[i]);
		}
		ans.push_back(node{val,sum});
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i] && G[d[now-1]][i]){
			vis[i]=1;
			d[now]=i;
			dfs(now+1,dep,val+G[d[now-1]][i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		G[u][v]=w;
	}
	for(int i=2;i<=n;i++){
		vis[1]=1,d[1]=1;
		dfs(2,i,0);
	}
	sort(ans.begin(),ans.end(),cmp);
	if(k>(int)ans.size()){
		cout<<-1;
	}
	else{
		cout<<(int)ans[k-1].s.size()<<endl;
		for(int i=0;i<(int)ans[k-1].s.size();i++){
			cout<<ans[k-1].s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

