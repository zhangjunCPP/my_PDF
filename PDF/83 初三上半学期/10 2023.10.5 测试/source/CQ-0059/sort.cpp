#include<bits/stdc++.h>
#define int long long
const int N=1e6+10,M=1e5+10,inf=1e9+7;
void Freopen();
void Ftest();
int rd();
using namespace std;
int n,ans;
vector< int >v;
void Genshin(vector< int >v) {
	int len=v.size();
	if (len<=1) return ;
	int f=ceil(( double )(len/2.0));
	int mid=v[f-1];
//	cout<<mid<<endl;
	vector< int >v1,v2;
	for ( int i=0; i<len; i++) {
		ans=ans+1;
		if (v[i]<mid) v1.push_back(v[i]);
		if (v[i]>mid) v2.push_back(v[i]);
	}
	Genshin(v1);
	Genshin(v2);
}
signed main() {
	Freopen();
//	Ftest();
	cin>>n;
	for ( int i=1,x; i<=n; i++) x=rd(),
		v.push_back(x);
	Genshin(v);
	cout<<ans;
}
void Freopen() {
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
}
void Ftest() {
	freopen("sort10.in","r",stdin);
//	freopen("sort.out","w",stdout);
}
int rd() {
	int x; scanf("%lld",&x);
	return x;
}
/*
5
4 3 5 1 2
*/
 
