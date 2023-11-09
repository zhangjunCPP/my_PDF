#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int M=1e6+5;
const int KN=40+5;
int n,m,K;
struct data{
	int c;
	double x;
	char typ;
}a[N];
bool cmp(data a,data b){
	return a.x<b.x;
}
namespace sol1{// 10pts
	data b[N];
	double ans[KN],times=0;
	struct node
	{double ti;};
	priority_queue<node> q;
	bool operator < (node a,node b){
		return a.ti>b.ti;
	}
	bool operator > (node a,node b){
		return b<a;
	}
	char anti(char c){
		return c=='L'?'D':'L';
	}
	void check(){
		for(int i=1;i<n;i++)
			if(b[i].typ=='D'&&b[i+1].typ=='L')
				q.push(node{times+(b[i+1].x-b[i].x)/2.0});
	}
	void solve(){
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		check();
		while(q.size()){
			node u=q.top();q.pop();
			for(int i=1;i<=n;i++)
				b[i].x+=(b[i].typ=='D'?1:-1)*(u.ti-times),
				ans[b[i].c]+=u.ti-times;
			for(int i=1;i<n;i++)
				if(b[i].typ=='D'&&b[i+1].typ=='L'&&b[i].x==b[i+1].x)
					swap(b[i].c,b[i+1].c),b[i].c=(b[i].c+b[i+1].c)%K,
					b[i].typ=anti(b[i].typ),b[i+1].typ=anti(b[i+1].typ);
			check();
			times=u.ti;
		}
		for(int i=1;i<=n;i++)
			ans[b[i].c]+=(b[i].typ=='D'?m-b[i].x:b[i].x);
		for(int i=1;i<=K;i++)
			printf("%.1lf\n",ans[i-1]);
		return ;
	}
}
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>K>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].c>>a[i].typ;
	sort(a+1,a+n+1,cmp);
	sol1::solve();
	return 0;
}
/*
2 3 10
0 0 D
10 1 L


*/
