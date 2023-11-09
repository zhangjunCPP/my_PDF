#include<bits/stdc++.h>
#define PUT putchar('\n')
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0'); 
}
inline void FRE(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
const int N=1e6+5;
bool fl;
int T,n,m,tot,Max,dep[N];
vector<int> a[N];
inline void add(int u,int v){
	a[u].push_back(v);
}
inline void dfs(int u,int ff){
	dep[u]=++tot;
	for(int v:a[u]){
		if(v==ff)continue;
		if(dep[v]){
			if(dep[u]-dep[v]==2)fl=1;
		}
		if(!dep[v])dfs(v,u);
	}
}
inline void init(){
	tot=0;fl=0;Max=0;
	for(int i=1;i<=n;++i)a[i].clear();
}
int main(){
	FRE();
	T=rd();
	while(T--){
		n=rd(),m=rd();
		init();
		for(int i=1;i<=m;++i){
			int u=rd(),v=rd();
			add(u,v);add(v,u);
		}
		for(int i=1;i<=n;++i){
			Max=max(Max,(int)a[i].size());
		}
		dfs(1,0);
		Max=max(Max,fl?3:0);
		wr(Max),PUT;
	}	
	return 0;
}
