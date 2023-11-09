#pragma GCC optimize(2,3,4,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
using ll=long long;
int p[N];
int q[N];
ll mod;
ll n,ans;
ll v[N];
bool check(int x){
	for(int i=1;i<=x;i++){
		if(q[i]>p[i]){
			return 1;
		}else if(q[i]<p[i]){
			return 0;
		}
	}
	return 0;
}
int main(){
	int x=16;
	for(int i=1;i<=x;i++){
		p[i]=i;
	}
	do{
		for(int i=1;i<=x;i++){
			q[p[i]]=i;
		}
		if(check(x)){
			v[x]=(v[x]+1);
		}
	}while(next_permutation(p+1,p+x+1));
	printf("%d:%lld\n",x,v[x]);
	return 0;
}
