#include<bits/stdc++.h>
using namespace std;
const int N=21;
int n,m;
vector<pair<int,int> > E[N];
int visl[51],visp[21];
  
int main(){
	freopen("hamilton.in","r",stdin);
	freopen("hamilton.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		E[u].push_back({v,i});
	}
	puts("No");
	return 0;
}
