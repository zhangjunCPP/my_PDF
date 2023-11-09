/*
T1 game
ÆÀ¼ÛÎª£ºsbÌâ
*/
#include<bits/stdc++.h>
using namespace std;
char s[100010];
inline void solve()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s);
	for(int i=1;i<=m;i++){int a,b;scanf("%d%d",&a,&b);}
	int p=(m-n+1)%k;
	puts(s[p]=='P'?"G":"P");
	return;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
