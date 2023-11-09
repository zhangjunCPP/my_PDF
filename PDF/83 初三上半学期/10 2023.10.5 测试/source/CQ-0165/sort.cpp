#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;

int n;
int a[maxn];

int solve(vector<pair<int,int> >& st1,vector<pair<int,int> >& st2) {
	int sz=st1.size(), c=(sz+1)/2; 
	if(sz<=1) return 0;
	vector<pair<int,int> > st3,st4;
	pair<int,int> v=st2[c-1];
	st2.erase(lower_bound(st2.begin(),st2.end(),v));
	swap(v.first,v.second);
	int cnt=lower_bound(st1.begin(),st1.end(),v)-st1.begin();
	st1.erase(lower_bound(st1.begin(),st1.end(),v));
	if(cnt<c) {
		while(cnt>0) {
			--cnt;
			auto it=st1.begin();
			auto p=*it;
			st1.erase(it); st3.push_back(p);
			swap(p.first,p.second);
			st2.erase(lower_bound(st2.begin(),st2.end(),p)); st4.push_back(p);
		}
		sort(st3.begin(),st3.end());
		sort(st4.begin(),st4.end());
		return sz+solve(st1,st2)+solve(st3,st4);
	}
	int tmp=cnt;
	cnt=sz-cnt-1;
	while(cnt>0) {
		--cnt;
		auto it=st1.begin()+tmp;
		auto p=*it;
		st1.erase(it); st3.push_back(p);
		swap(p.first,p.second);
		st2.erase(lower_bound(st2.begin(),st2.end(),p)); st4.push_back(p);
	}
	sort(st3.begin(),st3.end());
	sort(st4.begin(),st4.end());
	return sz+solve(st1,st2)+solve(st3,st4);
}

int main() {
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	vector<pair<int,int> > st1,st2;
	for(int i=1;i<=n;i++) cin>>a[i], st1.push_back({a[i],i}), st2.push_back({i,a[i]});
	sort(st1.begin(),st1.end());
	sort(st2.begin(),st2.end());
	cout<<solve(st1,st2)<<'\n';
	return 0;
} 
