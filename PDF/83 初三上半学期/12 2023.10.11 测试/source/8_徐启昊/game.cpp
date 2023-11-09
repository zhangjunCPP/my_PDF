/*
当他为树时，就必须输。
所以就是删除多少次边可以变成树。
那么就是m-n+1+1的输 。 
这么简单？？？ 不可能吧？ 
*/
#include<bits/stdc++.h>
#define Genshin_Impact_starts ios::sync_with_stdio ( false )
#define int long long
int rd() {
	int x; scanf("%lld", &x);
	return x;
}
void Freopen() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
}
void Ft() {
	freopen("ex_game2.in", "r", stdin);
//	freopen("game.out", "w", stdout);
}
using namespace std;
const int N=1e6+100, inf=1e9+10;
int n, m, k; 
char s[N];
void solve() {
	n=rd(), m=rd(), k=rd();
	scanf("%s", s+1);
	for ( int i=1; i<=m; i++) {
		int u,v;
		u=rd(), v=rd();
	}
	char ans;
	if (m<n) {
		ans=s[1];
		if (ans=='P') puts("G");
		else puts("P");		
		return ;
	}
	int cnt=m-n+2;
	for ( int i=1; i<=cnt; i++) {
		int p=i%k;
		if (p==0) p=k;
		ans=s[p];
	}
	if (ans=='P') puts("G");
	else puts("P");	
}
signed main() {
	Freopen();
//	Ft();
	for ( int t=rd(); t; t--) solve();
}
/*
3
5 4 1
G
1 2
1 3
2 4
1 5
4 6 1
G
1 2
2 3
1 4
3 1
2 4
3 4
4 4 1
P
1 2
2 3
2 4
1 3

P
P
G

*/
