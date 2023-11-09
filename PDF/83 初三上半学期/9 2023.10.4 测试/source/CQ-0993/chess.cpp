#include<bits/stdc++.h>

using namespace std;

vector<int>ans[2222222];
int o=0;
int solve(int p,int x,int d){
	cout<<x<<" "<<p<<endl;
	for(int i=1;i<=x/p;i++){
		o++;
		
		for(int j=1;j<=p;j++){
			ans[o].push_back(((i-1)*p+j)*d);
		}
	}
	if(x==p){
		return 0;
	}
	solve(p,x/p,d*p);
	
	return 0;
}
int main(){
	//freopen("name.in","r",stdin);
	//freopen("name.out","w",stdout);
	int p,k;
	cin>>p>>k;
	int x=1;
	while(k--){
		x*=p;
	}
	if(k==1){
		cout<<1<<endl;
		for(int i=0;i<p;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	if(p==2){
		cout<<(x-1)*x/2<<endl;
		for(int i=0;i<x;i++){
			for(int j=i+1;j<x;j++){
				cout<<i<<" "<<j<<endl;
			}
		}
		return 0;
	}
	
	int yu=x*(x-1)/2;
	int op=p*(p-1)/2;
	cout<<yu/op<<endl;
	solve(p,x,1);
	
	for(int i=1;i<=o;i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
/*
0 1 2
0 3 4
0 5 6
0 7 8
1 3 6
1 4 7
1 5 8
2 3 8
2 4 5
2 6 7
3 5 7
4 6 8


0 1 2
3 4 5
6 7 8
0 3 6
0 4 7
0 5 8
1 3 7
1 4 8
1 5 6
2 3 8
2 4 6
2 5 7

0 1 2
3 4 5
6 7 8
0 3 6

0 1 2
0 3 4


*/
