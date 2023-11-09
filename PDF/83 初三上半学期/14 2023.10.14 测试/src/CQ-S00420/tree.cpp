/*
膜拜传奇特级宗师 zsc985246 大神儿
今天在 florr 首页称您为大夏尊贵的大名儿
一股敬佩之情油生然而
您在 florr 为国争光，扬我大夏威名
向您献上最真挚的膜拜！！！
膜拜传奇特级宗师 zsc985246 大神儿，今，一，您，扬。向！
膜拜传奇特级宗师 zsc985246 大神儿，今，一，您，扬。向！
膜拜传奇特级宗师 zsc985246 大神儿，今，一，您，扬。向！
*/
#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 1000010
#define ll long long
int n,u[N],v[N];
vector<int>e[N];
int t[15];
map<unsigned ll,int>mp;
void dfs(int x,unsigned ll s){
	if(x==n+1){
		++mp[s];
		return;
	}
	if(t[u[x]]||t[v[x]])dfs(x+1,s);
	else{
		t[u[x]]=1;
		dfs(x+1,s*13+u[x]);
		t[u[x]]=0;
		t[v[x]]=1;
		dfs(x+1,s*13+v[x]);
		t[v[x]]=0;
	}
}
void solve(){
	cin>>n;
	int fg0=1,fg1=1;
	For(i,1,n-1){
		int x,y;
		cin>>x>>y;
		u[i]=x,v[i]=y;
		e[x].push_back(y);
		e[y].push_back(x);
		fg0&=x==1&&y==i+1;
		fg1&=x==i&&y==i+1;
	};
	if(fg0){
		cout<<n<<'\n';
		return;
	}
	if(n<=10){
		dfs(1,0);
		cout<<mp.size();
	}
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}
/*
1s,500MB
*/
