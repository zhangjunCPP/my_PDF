#include<bits/stdc++.h>
using namespace std;
//bool isnum(char ch) { return ( ch>='0'&&ch<='9' ); }
//inline int read() { int x=0; bool f=false; char ch=getchar(); while(!isnum(ch)) { if(ch=='-') f=true; ch=getchar(); } while(isnum(ch)) { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); } return f ? -x : x; }
//inline void write(int x) { if(x<0) putchar('-'), x=-x; if(x>9) write(x/10); putchar(x%10+'0'); }
const int N=2e5+25;
int T,n,m,k;
char ch[N];
void pud(char ch) { if(ch=='P') putchar('G'); else putchar('P'); }
signed main() {
//	freopen("ex_game2.in","r",stdin);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&m,&k);
		scanf("%s",ch+1);
		for(int i=1;i<=m;i++) {
			int u,v; scanf("%d%d",&u,&v);
		} 
		int wh=(m-(n-1)+1-1)%k+1; 
		pud(ch[wh]); puts("");
	}
	return 0;
} 
