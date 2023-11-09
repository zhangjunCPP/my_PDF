#include <bits/stdc++.h>
using namespace std;
/*
int n,m,vis[100010],st[100010],tot,la[100010];
struct as{
	int u,v;
}e[200010];
vector<int>f[100010],h[100010];
int cnt=0;
void dfs(int u,int last){
	cout<<u<<" "<<last<<endl;
	if(vis[u]){
		cnt++;
		while(st[tot]!=u&&tot>0){
			h[cnt].push_back(st[tot]);
			vis[st[tot]]=0;
			tot--;
		}
		h[cnt].push_back(u);
	}
	else{
		st[++tot]=u;
		vis[u]=1;
	}
	for(int i=la[u],fs=f[u].size();i<fs;i=la[u],la[u]++){
		int v=e[f[u][i]].v;
		if(v==last)continue;
		la[u]++;
		dfs(v,u);
	}
	tot--;
	vis[u]--;
}
*/
signed main(){
//	freopen("hamilton.in","r",stdin);
//	freopen("hamilton.out","w",stdout);	
	cout<<"NO";
/*
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&e[i].u,&e[i].v);
		f[e[i].u].push_back(i);
	} 
	cout<<endl;
	dfs(1,0);
	for(int i=1;i<=n;i++){
		memset(la,0,sizeof(la));
		dfs(i,0);
	}
cout<<endl;
	for(int i=1;i<=cnt;i++){
		tot=0;
		for(int j:h[i]){
			cout<<j<<' ';
		}
		cout<<endl;
	}
	*/
	return 0;
}
/*
6 16
1 3
1 6
2 3
2 4
2 6
3 1
3 6
4 2
4 3
4 5
4 6
5 2
5 6
6 1
6 3
6 5

*/
