#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e5+5;
int n,m,k;
char czc[N];
void solve(){
	n=rd(),m=rd(),k=rd();
	scanf("%s",czc);
	for(int i=1;i<=m;i++)rd(),rd();
	if(czc[(m-n+1)%k]=='P')puts("G");
	else puts("P");
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int t=rd();
	while(t--)solve();
	return 0;
}
