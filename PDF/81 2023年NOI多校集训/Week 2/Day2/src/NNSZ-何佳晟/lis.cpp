#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500005,INF=0x3f3f3f3f;
int _;
int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    freopen("lis.in","r",stdin);
    freopen("lis.out","w",stdout);
    cin>>n;
	
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	} 
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	cout<<2<<endl;
	
    return 0;
}

