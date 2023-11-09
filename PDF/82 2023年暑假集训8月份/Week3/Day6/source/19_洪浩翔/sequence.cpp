#include<bits/stdc++.h>
#define int long long 
const int mod=998244353;
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
int n,k,s[305];
//map<pair<int,int>,bool> q;
void dfs(int st,int a,int b){
	if (st>n){
		int tmp=(a+1)*(b+1)-1;
		if (tmp<1||tmp>k) return ;
//		if (q.find({a,b})!=q.end()) return ;
		printf("%d %d\n",a,b);
		s[tmp]++; //q[{a,b}]=1;
		if (s[tmp]>=mod) s[tmp]-=mod;
		return ;
	}
	dfs(st+1,a,b+1);
	dfs(st+1,a+1,b);
}
signed main(){
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	n=read(),k=read();
	if (n<=20){
		dfs(1,0,0);
		for (int i=1;i<=k;i++)
			printf("%lld ",s[i]);
	}
	return 0;
}

