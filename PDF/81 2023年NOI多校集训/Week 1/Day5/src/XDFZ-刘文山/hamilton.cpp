#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1e5+5;
int dfn[maxn],low[maxn],scc[maxn],instack[maxn],tot,col;
int cnt[maxn],qi[maxn];
vector<int> G[maxn];
vector<int> q[maxn];
stack<int> st;
inline void Tarjan(int x){
	dfn[x]=++tot;
	low[x]=dfn[x];
	st.push(x);
	instack[x]=1;
	for(auto v:G[x]){
		if(!dfn[v]){
			Tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(instack[v]) low[x]=min(low[x],dfn[v]); 
	}
	if(low[x]==dfn[x]){
		scc[x]=++col;
		qi[col]=x;
		cnt[col]++;
		while(st.top()!=x){
			scc[st.top()]=col;
			instack[st.top()]=0;
			st.pop();
			cnt[col]++;
		}
		instack[x]=0;
		st.pop(); 
	}
}
int main(){
	freopen("hamilton.in","r",stdin);
	freopen("hamilton.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1,a,b;i<=m;i++){
		cin>>a>>b;
		G[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) Tarjan(i);
	}
//	for(int i=1;i<=col;i++){
//		
//	}
	cout<<"NO";
	return 0;
} 
