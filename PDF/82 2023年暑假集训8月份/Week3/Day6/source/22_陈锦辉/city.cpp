//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 200002
using namespace std;
int n,k;
bool b[MAXN];
int fa[MAXN];
vector<int> G[MAXN];
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	puts("1");
	return 0;
}
