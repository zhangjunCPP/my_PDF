#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N=1e3+5;
int n;
ll ans;
vector<int> a;
void solve(vector<int> a){
	if(a.size()-1<=1) return ;
	int pivot=a[(int)a.size()>>1];
	vector<int> al,ag; al.pb(0),ag.pb(0);
	for(int i=1;i<(int)a.size();++i){
		++ans;
		if(a[i]<pivot) al.pb(a[i]);
		if(a[i]>pivot) ag.pb(a[i]);
	}
	solve(al),solve(ag);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("S_bl.out","w",stdout);
	scanf("%d",&n),a.resize(n+1);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	solve(a);
	printf("%lld\n",ans);

	return 0;
}
