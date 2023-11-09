#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	char c=getchar();
	bool f=0;
	while(c<'0' || c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar(); 
	}
	if(f) x=-x;
}
const int maxn=1e5+5;
char s[maxn];
inline void solve(){
	int n,m,k;
	read(n),read(m),read(k);
	scanf("%s",s+1);
	for(int i=1,x,y;i<=m;i++) read(x),read(y);
	int rest=(m-n+1)%k;
	rest++;
	if(s[rest]=='G')
	putchar('P'),putchar('\n');
	else
	putchar('G'),putchar('\n');
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	int T;
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
/*
水题？
每个人一定会删去一条除桥以外的边。
最后结局一定是一颗树，谁动那颗树谁就输了。 
*/ 
