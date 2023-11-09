/*
there is no time to think,i can only write the 50pts.
*/

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
using ll=long long;
int check1(){
	for(int i=1;i<=n;i++)if(a[i]!=i)return 0;
	return 1;	
}
void solve1(){
	ll sum=0;
	for(int i=1;i<n;i++)sum+=a[i];
	printf("%lld\n",sum);
	for(int i=1;i<=n;i++)printf("%d ",n-i+1); 
}
int check2(){
	for(int i=1;i<=n;i++)if(a[i]!=n-i+1)return 0;
	return 1;
}
void solve2(){
	ll sum=0;
	sum=a[1]*(n-1);
	printf("%lld\n",sum);
	for(int i=n;i>1;i--)printf("%d ",i);
	puts("1"); 
}
int id[14],ps[14];
void solve3(){
	ll ans=0;
	for(int i=1;i<=n;i++)id[i]=i;
	do{
		stack<int> s;
		s.push(id[1]);
		ll sum=0;
		for(int i=2;i<=n;i++){
			while(!s.empty()&&s.top()>id[i])sum+=a[id[i]],s.pop();
			s.push(id[i]);
		}
		if(sum>ans){
			ans=sum;
			for(int i=1;i<=n;i++)ps[i]=id[i];
		}
	}while(next_permutation(id+1,id+1+n)); 
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)printf("%d ",ps[i]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(check1())return solve1(),0; 
	if(check2())return solve2(),0;
	if(n<=10)return solve3(),0; 
	
	return 0;
}

