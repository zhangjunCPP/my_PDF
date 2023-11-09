#include<bits/stdc++.h>
#define N 700005
#define pb push_back
using namespace std;
int n,ans;
vector<int> b;
vector<int> solve(vector<int> now){
	if((int)now.size()<=1)return now;
	int mid=now[ceil((int)now.size()/2.0)-1];
	vector<int> l,r;
	l.clear();
	r.clear();
	for(int x:now){
		ans++;
		if(x<mid)l.pb(x);
		if(x>mid)r.pb(x);
	}
	l=solve(l);
	r=solve(r);
	l.pb(mid);
	for(int x:r)l.pb(x);
	return l;
}
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		b.pb(x);
	}
	solve(b);
	printf("%d",ans);
	return 0;
}
/*
5
4 3 5 1 2
*/
