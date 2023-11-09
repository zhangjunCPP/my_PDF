#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int val[N];
int main(){
	freopen("subgraph.in","r",stdin);
	freopen("subgraph.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int M,N,B;
	cin>>M>>N>>B;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		val[x]++;
		val[y]++;
	}
	sort(val+1,val+n+1);
	printf("%d 0",val[1]);
}
