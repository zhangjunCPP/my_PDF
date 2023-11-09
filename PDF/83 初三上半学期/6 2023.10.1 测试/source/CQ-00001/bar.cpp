//the code is from chenjh
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
struct Edge{
	int val;
	vector<int> p;
	Edge(){val=0,p.clear();}
	Edge(int _val,vector<int> _p){
		val=_val;p=_p;
	}
	bool operator < (const Edge&y)const{
		if(val!=y.val) return val<y.val;
		return p<y.p;
	}
};
int n,m,k;
vector<PII> G[55];
bool vis[55];
priority_queue<Edge> Q;
vector<int> q;
void dfs(const int pos,const int now){
	if(pos==n){
		q.emplace_back(n);
		Edge t=Edge(now,q);
		if((int)Q.size()<k||t<Q.top()) Q.emplace(t);
		if((int)Q.size()>k) Q.pop();
		q.pop_back();
		return;
	}
	vis[pos]=1;
	q.emplace_back(pos);
	for(const PII&v:G[pos])if(!vis[v.first])dfs(v.first,now+v.second);
	vis[pos]=0;
	q.pop_back();
}
int main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int u,v,w;m--;){
		scanf("%d%d%d",&u,&v,&w);
		G[u].emplace_back(v,w);
	}
	dfs(1,0);
	if((int)Q.size()<k)puts("-1");
	else{
		vector<int> ans(Q.top().p);
		printf("%zu\n",ans.size());
		for(const int x:ans) printf("%d ",x);
	}
//	putchar('\n');
//	for(Edge u;!Q.empty();){
//		u=Q.top(),Q.pop();
//		printf("%d\n",u.val);
//		for(const int x:u.p) printf("%d ",x);
//		putchar('\n');
//	}
	return 0;
}

