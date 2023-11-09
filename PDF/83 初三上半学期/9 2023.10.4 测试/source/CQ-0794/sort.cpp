#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll p;
const int maxn=5e6+5;
int a[maxn],vis[maxn],ans;
inline void dfs(int now){
	if(now+1==n){
		
	}
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	while(1); 
	int T;
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%lld",&n,&p);
		dfs(1);
	} 
	return 0;
}
/*

a    x x x x x x x x x x
s1  n n-1 ->
s2 n-1 n

观察一波，发现s2没卵用。
看错了有用

s2->b n ,n-1,n-2,n-3,n-4,n-5,.....1
s1->s2 ->  

n-2 n-1 n
2 1 3

->

<-

->
不会多项式做法，南蚌 
*/
