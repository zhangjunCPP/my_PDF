#include<cstdio>
#include<ctime>
#include<iostream>
#include<random>
using namespace std;
mt19937 rnd(time(nullptr));
int main(){
	freopen("segment.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n=2e5,mod=10;
	cout<<n<<'\n';
	for(int i=1;i<=n;++i)cout<<(rnd()%mod+1)<<' ';
	cout<<'\n';
	return 0;
}
