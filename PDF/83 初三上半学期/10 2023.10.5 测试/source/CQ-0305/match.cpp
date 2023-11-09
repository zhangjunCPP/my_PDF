//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int n,m;
vector<int> G[MAXN];
inline void read(int&x){
	x=0;
	bool sign=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')sign=1;
	for(;'0'<=ch && ch<='9';ch=getchar())x=x*10+(ch^'0');
	if(sign) x=-x;
}
inline void write(const int x){
	if(x>9) write(x/10);
	putchar((x%10)|'0');
}
bool ring(){
	for(int i=1;i<=n;i++)if(G[i].size()==2u){
		int u=G[i][0],v=G[i][1];
		for(const int w:G[u])if(w==v)return 1;
	}
	return 0;
}
void solve(){
	read(n),read(m);
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=0,u,v;i<m;i++){
		read(u),read(v);
		G[u].emplace_back(v),G[v].emplace_back(u);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,(int)G[i].size());
	if(ans==2 && ring()) ans=3;
	write(ans);putchar('\n');
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;read(T);
	while(T--) solve();
	return 0;
}

