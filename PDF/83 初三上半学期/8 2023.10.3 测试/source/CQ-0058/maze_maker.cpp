#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>
#include<random>
#include<set>
using namespace std;
set<pair<int,int>>S;
mt19937 rnd(time(nullptr)); 
int main(){
	freopen("maze.in","w",stdout);
	int n=1.2e5,m=2e5,k=2e4;
	vector<int>p;
	for(int i=1;i<=n;++i)p.emplace_back(i);
	shuffle(p.begin(),p.end(),rnd);
	cout<<n<<' '<<m<<' '<<k<<'\n';
	for(int i=1;i<=k;++i)cout<<p[i]    <<" \n"[i==k];
	for(int i=1;i<=n;++i)cout<<rnd()%11<<" \n"[i==n];
	vector<pair<int,int>>E;
	for(int i=2;i<=n;++i){
		int j=rnd()%(i-1)+1;
		S.emplace(i,j);
		if(rnd()&1)E.emplace_back(i,j);
		else E.emplace_back(j,i);
	}
	for(int i=n;i<=m;++i){
		int x=rnd()%n+1,y=rnd()%n+1;
		while(S.count({x,y})||S.count({y,x}))
			x=rnd()%n+1,y=rnd()%n+1;
		S.emplace(x,y);
		E.emplace_back(x,y);
	}
	shuffle(E.begin(),E.end(),rnd);
	for(auto e:E)cout<<e.first<<' '<<e.second<<' '<<rnd()%((int)1e4)+1<<'\n';
	return 0;
}
