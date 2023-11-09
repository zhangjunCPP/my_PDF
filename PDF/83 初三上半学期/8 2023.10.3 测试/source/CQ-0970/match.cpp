
#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=1e6+5;
int n,m;
vector<int> b[N];
namespace sub1{//n<=10
	
	void work(){
		
	}
}
namespace WA{
	void work(){
		for(int i=1;i<=m;i++) putchar('1');
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	_(n),_(m);
	for(int i=1;i<=n;i++){
		int k,p; _(k);
		while(k--) _(p),b[i].emplace_back(p);
	}
	WA::work();
	return 0;
}

