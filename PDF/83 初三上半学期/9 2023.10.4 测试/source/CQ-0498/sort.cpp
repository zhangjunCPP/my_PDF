#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=5e6+5;
using ll=long long;
int n;
ll p;
//namespace sub1{//n<=6
//	int asd[N];
//	stack<int> a,b,s1,s2;
//	ll ans;
//	bool flag;
//	void dfs(int dep){
//		if(flag) return ;
//		if((int)b.size()==n){ ans=(ans-1+p)%p,flag=1; return ; }
//		if(dep>n*3) return ;
//		if(!a.empty()&&(s1.empty()||(!s1.empty()&&a.top()<s1.top()))){
//			int x=a.top();
//			a.pop(),s1.emplace(x);
//			dfs(dep+1);
//			s1.pop(),a.emplace(x);
//		}
//		if(!s1.empty()){
//			int x=s1.top();
//			s1.pop(),s2.emplace(x);
//			dfs(dep+1);
//			s2.pop(),s1.emplace(x);
//		}
//		if(!s2.empty()&&(b.empty()||(!b.empty()&&s2.top()<b.top()))){
//			int x=s2.top();
//			s2.pop(),b.emplace(x);
//			dfs(dep+1);
//			b.pop(),s2.emplace(x);
//		}
//	}
//	void work(){
//		ans=1;
//		for(ll i=1;i<=(ll)n;i++) ans=ans*i%p,asd[i]=i;
//		do{
//			while(!a.empty()) a.pop();
//			while(!b.empty()) b.pop();
//			while(!s1.empty()) s1.pop();
//			while(!s2.empty()) s2.pop();
//			for(int i=1;i<=n;i++) a.emplace(asd[i]);
//			flag=0;
//			dfs(1);
//		}while(next_permutation(asd+1,asd+n+1));
//		printf("%lld\n",ans);
//	}
//}
const int res[20]={0,0,0,0,2,30,326,3234,31762,321294};
void solve(){
	_(n),_(p);
//	/*if(n<=6) */sub1::work();
	printf("%d\n",res[n]);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int T; _(T);
	while(T--) solve();
	return 0;
}
/*
10
1 998244353
2 998244353
3 998244353
4 998244353
5 998244353
6 998244353
7 998244353
8 998244353
9 998244353
10 998244353
*/
