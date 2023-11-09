#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 200010
#define ll long long
int n=50000,m=828,q=60,re=50000;
int rnd(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	freopen("match.in","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cout<<m<<'\n';
	For(i,1,n){
		cout<<(char)(rnd(0,2)+'a');
	};
	cout<<'\n';
	cout<<q<<'\n';
	For(i,1,q){
		int len=re/q;
		For(j,1,len){
			cout<<(char)(rnd(0,2)+'a');
		};
		cout<<'\n';
	};
	return 0;
}
