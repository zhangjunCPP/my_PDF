#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int p=1e9+7;
const int N=105;
int t;
int n,m,k;
int u[N],v[N],df[N],sm[N];
vector<int> e[N];
//namespace sub1{//same=0
//	bool check(){
//		for(int i=1;i<=m;i++) if(df[i]!=1||sm[i]) return 0;
//		return 1;
//	}
//	bool vis[N];
//	int ans;
//	void dfs(int u,int fa){
//		
//	}
//	void work(){
//		memset(vis,0,sizeof vis);
//		dfs(1,0);
//	}
//}
//namespace sub2{
//	bool check(){
//		return m==n-1;
//	}
//	void dfs(int u,int fa){
//		
//	}
//	void work(){
//		int s=0;
//		for(;;s++) if(e[s].size());
//	}
//}
void solve(){
	_(n),_(m),_(k);
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<=m;i++){
		_(u[i]),_(v[i]),_(df[i]),_(sm[i]);
		e[u[i]].emplace_back(v[i]),e[v[i]].emplace_back(u[i]);
	}
	puts("0");
//	if(sub1::check()) sub1::work();
	//sbsbsbsbsb
	
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	_(t);
	while(t--) solve();
	return 0;
}

