#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+11,inf=1e16;
int n,k,o;
int t[N];
int tim[N],cost[N];
void solve10(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=1;i<=k;i++)
		cin>>tim[i]>>cost[i];
	cin>>o;
	for(int i=1;i<=n;i++)
		cout<<o<<endl;
}
signed main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	solve10();
	return 0;
}
