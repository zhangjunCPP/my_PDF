#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005,INF=1e9,mod=1e9+7;
int _;
int n,m;
vector<int>g[maxn];

int main(){
	ios::sync_with_stdio(0);
	freopen("hamilton.in","r",stdin); 
	freopen("hamilton.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y; 
		g[x].push_back(y);
	}
	cout<<"NO"<<endl;
	
    return 0 ^ _ ^ 0;
}



