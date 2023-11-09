#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
int n,ans;
vector<int>a;
void solve(vector<int>s){
	if(s.size()==1)return ;
	int l=0,r=s.size()-1;
	int mid=(l+r)/2,val=s[mid];
	vector<int>ls,rs;
	ls.clear(),rs.clear();ans=ans+(r-l+1);
	for(auto k:s){
		if(k<val)ls.push_back(k);
		if(k>val)rs.push_back(k);
	}
	if(ls.size())solve(ls);
	if(rs.size())solve(rs);
}
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	solve(a);
	cout<<ans;
	return 0;
}
//Õ¨ÁË£º£¨ 
