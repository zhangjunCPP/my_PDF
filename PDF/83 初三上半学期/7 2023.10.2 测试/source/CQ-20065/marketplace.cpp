#include<bits/stdc++.h>
#define int long long
const int N=1e6+10,M=1e5+10,inf=1e9;
void Freopen();
void Ftest();
using namespace std;
int n,m;
int use[N],ans[N];
struct node {
	int a,b;
} p[N];
signed main() {
//	Ftest();
	Freopen();
	cin>>n>>m;
	for ( int i=1; i<=n; i++) cin>>p[i].a>>p[i].b;
	for ( int x=1; x<=m; x++) {
		for ( int i=1; i<=m; i++) use[i]=0;
		use[x]=1;
		for ( int I=1; ; I++) {
			int i=I%(n+1);
			if (!i) continue;
			int a=p[i].a,b=p[i].b;
			if (!use[a]) use[a]=1;
			else if (!use[b]) use[b]=1;
			else {
				ans[i]++;
				break;
			}
		}
	}
	for ( int i=1; i<=n; i++) cout<<ans[i]<<endl;
}
void Freopen() {
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
}
void Ftest() {
	freopen("ex_data5.in","r",stdin);
//	freopen("b5.out","w",stdout);
}
