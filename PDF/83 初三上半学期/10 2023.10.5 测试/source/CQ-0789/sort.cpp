#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=7e5+5;
int n;
int a[N];
namespace sol1{
	int ans;
	void run(vector<int> arr){
		if(arr.size()<=1) return ;
		vector<int> al,ar;
		al.clear(),ar.clear();
		int mid=arr[(arr.size()+1)/2-1];
		ans+=arr.size();
		for(int u:arr){
			if(u<mid) al.push_back(u);
			if(u>mid) ar.push_back(u);
		}
		arr.clear();
		run(al),run(ar);
		return ;
	}
	void solve(){
		vector<int> arr;
		arr.clear();
		for(int i=1;i<=n;i++)
			arr.push_back(a[i]);
		run(arr);
		cout<<ans;
		return ;
	}
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sol1::solve();
	return 0;
}
/*
5
4 3 5 1 2
*/
