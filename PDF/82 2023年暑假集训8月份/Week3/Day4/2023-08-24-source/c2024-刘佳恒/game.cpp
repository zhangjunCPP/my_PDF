#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x=0ll; bool f=false; char ch=getchar();
	while(ch>'9'||ch<'0') { if(ch=='-') f^=1; ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<3ll)+(x<<1ll)+ch-48; ch=getchar(); }
	return (f?-x:x);
}
inline void write(int x) {
	if(x<0) putchar('-'), x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=2e5+25;
int n,val[N],mrk[N];
bool vis[N];
stack<int> s;
int ans=0,an[N];
void dfs(int now) {
	if(now>n) {
		while(!s.empty()) s.pop();
		int sum=0;
		s.push( mrk[1] );
		
//		for(int i=1;i<=n;i++) cout<<mrk[i]<<" ";
//		puts("");
		
		for(int i=2;i<=n;i++) {
			while( !s.empty() && s.top()>mrk[i] ) {
				sum+=val[ mrk[i] ]; s.pop();
			}
			s.push( mrk[i] );
		}
		if( sum>ans ) {
			ans=sum;
			for(int i=1;i<=n;i++) an[i]=mrk[i];
		}
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=true;
			mrk[now]=i;
//			cout<<mrk[now]<<" "<<i<<" ";
			dfs(now+1);
			mrk[now]=0;
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	bool fbi1=true,fbi2=true;
	for(int i=1;i<=n;i++) {
		val[i]=read();
		fbi1&=( val[i]==i );
		fbi2&=( val[i]==n-i+1 );
	}
	if( fbi1 ) {
		int sum=0;
		for(int i=1;i<=n-1;i++) sum+=val[i];
		write(sum); putchar('\n');
		for(int i=n;i>=1;i--) write(i),putchar(' ');
		return 0;
	}
	if( fbi2 ) {
		int sum=val[1]*(n-1);
		printf("%lld\n",sum);
		write(sum); putchar('\n');
		for(int i=2;i<=n;i++) write(i),putchar(' ');
		puts("1"); return 0;
	}
	dfs(1);
	write(ans); putchar('\n');
	for(int i=1;i<=n;i++) write(an[i]),putchar(' ');
//	int t=clock(); cout<<t<<" ";
	return 0;
}
/*
10
2 2 1 24 13 15 20 10 29 29
*/
