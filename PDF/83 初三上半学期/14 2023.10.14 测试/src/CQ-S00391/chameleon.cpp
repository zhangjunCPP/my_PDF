#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,l;
struct node{
	int d;
	int col;
	bool f;
	friend bool operator <(node a,node b){
		if(a.d==b.d)return a.f>b.f;
		return a.d<b.d;
	}
};multiset<node>a,tmp;
int b[40];
signed main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k>>l;
	for(int i=1;i<=n;i++){
		int d,b;char ch;
		cin>>d>>b>>ch;
		a.insert({d*2,b,ch=='D'});
	}
	while(!a.empty()){
		for(node i:a){
			if(i.d==0&&i.f==0||i.d==2*l&&i.f==1)continue;
			if(i.f==0)tmp.insert({i.d-1,i.col,i.f}),b[i.col]+=1;
			if(i.f==1)tmp.insert({i.d+1,i.col,i.f}),b[i.col]+=1;
		}
		a=tmp;tmp.clear();
		node last={-1,-1,0};
		for(node i:a){
			if(i.d==last.d&&last.f==1&&i.f==0)tmp.insert({i.d,(last.col+i.col)%k,i.f});
			else tmp.insert({i.d,i.col,i.f});
			last=i;
		}
		a=tmp;tmp.clear();
	}
	for(int i=0;i<k;i++)
		cout<<b[i]/2<<"."<<(b[i]&1?5:0)<<endl;
	return 0;
}
