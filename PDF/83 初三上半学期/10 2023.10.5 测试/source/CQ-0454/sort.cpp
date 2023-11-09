#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=7e5+5;
int n;
vector<int> a;
namespace sub1{//n<=3e3
	int cnt=0;
	vector<int> srt(vector<int> a){
		if(a.size()<=1) return a;
		int w=a[ceil((double)a.size()/2.0)-1];
		vector<int> l,r,g;
		for(auto x:a){
			cnt++;
			if(x<w) l.emplace_back(x);
			if(x>w) r.emplace_back(x);
		}
		l=srt(l),r=srt(r);
		for(auto x:l) g.emplace_back(x);
		g.emplace_back(w);
		for(auto x:r) g.emplace_back(x);
		return g;
	}
	void work(){
		/*a=*/srt(a);
		printf("%d",cnt);
	}
}
namespace sub2{//ai=i
	bool check(){
		for(int i=0;i<n;i++) if(a[i]!=i+1) return 0;
		return 1; 
	}
	int solve(int l,int r){
		if(r-l+1<=1) return 0;
		int mid=ceil((double)(r-l+1)/2.0)+l-1;
		return r-l+1+solve(l,mid-1)+solve(mid+1,r);
	}
	void work(){
		printf("%d",solve(1,n));
	}
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	_(n);
	for(int i=1;i<=n;i++){
		int x; _(x);
		a.emplace_back(x);
	}
	if(sub2::check()) sub2::work();
	else sub1::work();
	return 0;
}
/*
5
4 3 5 1 2
*/
/*
10
1 2 3 4 5 6 7 8 9 10
9
1 2 3 4 5 6 7 8 9
8
1 2 3 4 5 6 7 8
*/
