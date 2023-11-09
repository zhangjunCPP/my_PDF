//the code is from chenjh
#include<cstdio>
#define MAXN 100005
using namespace std;
int n,m,k;
char s[MAXN];
void solve(){
	scanf("%d %d %d %s",&n,&m,&k,s+1);
	int l=(m-(n-1))%k+1;
	puts(s[l]=='P'?"G":"P");
	while(m--) scanf("%*d%*d");
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}

