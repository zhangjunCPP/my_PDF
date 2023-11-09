#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
#define int long long
int t;
int n;
int calc(int x){
	int res=0;
	for(int i=1;i<=n;i++) if(x%i==0&&x/i<=n) res++;
	return res;
}
void solve(){
	_(n);
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++){
		int w=calc(i*j);
		if(i==j) ans+=w;
		else ans+=w*2;
	}	
	printf("%lld\n",ans);
}
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	_(t);
	while(t--) solve();
	return 0;
}
/*
4
1
2
7
35

*/
