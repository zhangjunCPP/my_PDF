#include<bits/stdc++.h>
using namespace std;
const int N=2e3+23,MAX=1e8+18;
int p,k;
void write(int x) {
	if(x<0) putchar('-'), x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
} 

int n=1,ant,it;
int ans[MAX],tot;
int anp[N];
void solve() {
	for(int t=k;t>=1;t--) {
		int len=1;
		for(int j=1;j<=k-t;j++) len*=p;
		int now=1;
		while(now<=n) {
			for(int i=0;i<p-2;i++) anp[i]=now+len*i;
			int xp=now+len*(p-1),sp=now+len*p;
			
//			for(int i=0;i<p-2;i++) cout<<anp[i]<<"   ";
//			puts("");
			
			for(int i=now+len*(p-2);i<xp;i++) {
				anp[p-2]=i;
				for(int j=0;j<p-1;j++) ans[++tot]=anp[j];
				for(int j=xp;j<sp;j++) {
					ans[++tot]=j; ant++;
//					for(int l=tot-p+1;l<=tot;l++) cout<<ans[l]<<"  ";
//					puts("");
					if( !(j==sp-1) ) for(int l=0;l<p-1;l++) ans[++tot]=anp[l];
				}
			}
			now+=len*p;
		}
	}
	write(ant); puts("");
	for(int i=1;i<=tot;i++) {
		write(ans[i]-1); putchar(' ');
		if(i%p==0) puts("");
	}
}
signed main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&p,&k);
	if(k==1) {
		puts("1");
		for(int i=1;i<=n;i++) write(i-1),putchar(' ');
		return 0;
	}
	for(int i=1;i<=k;i++) n*=p;
	solve();
	return 0;
}
/*
2 2
2 3
3 2
7 3
11 3
*/
