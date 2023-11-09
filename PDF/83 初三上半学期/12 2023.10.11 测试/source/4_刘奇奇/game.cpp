#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; char ch=getchar(); bool f=0;
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=1e5+5;
int T;
int n,m,k;
char s[N];

signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	_(T);
	while(T--){
		_(n),_(m),_(k),scanf("%s",s+1);
		for(int i=1;i<=m;i++){ int u,v; _(u),_(v); }
		int x=(m-n+2)%k;
		if(!x) x=k;
		if(s[x]=='P') puts("G");
		else puts("P");
	}
	return 0;
}
