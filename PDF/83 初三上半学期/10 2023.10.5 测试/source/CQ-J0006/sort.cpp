#include<bits/stdc++.h>
using namespace std;
int ans;
void ksort(vector<int>a){
	if(a.size()<=1)return;
	int pos=(a.size()+1)/2-1;
	vector<int>al,ag;
	for(int i=0;i<a.size();i++){
		ans++;
		if(a[i]<a[pos])al.push_back(a[i]);
		if(a[i]>a[pos])ag.push_back(a[i]);
	}
	ksort(al);
	ksort(ag);
}
int n;vector<int>v;
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1,a;i<=n;i++)cin>>a,v.push_back(a);
	ksort(v);
	cout<<ans;
	return 0;
}
