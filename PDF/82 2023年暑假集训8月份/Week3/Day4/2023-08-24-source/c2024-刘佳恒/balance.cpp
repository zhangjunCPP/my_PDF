#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0; bool f=false; char ch=getchar();
	while(ch>'9'||ch<'0') { if(ch=='-') f^=1; ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); }
	return (f?-x:x);
}
inline void write(int x) {
	if(x<0) putchar('-'), x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=3e5+35;
int n;
vector<int> eg[N];
int rcd[N],maxd=0;
void add(int u,int v) {
	eg[u].push_back(v);
	eg[v].push_back(u);
	rcd[u]++; rcd[v]++;
	if( rcd[u]>rcd[maxd] ) maxd=u;
	if( rcd[v]>rcd[maxd] ) maxd=v;
}
int mrk[N],id[N],at[N];
int siz[N],dp[N];
void dfs1(int u,int dad) {
	siz[u]=1;
	for(int i=0;i<(int)eg[u].size();i++) {
		int v=eg[u][i];
		if(v==dad) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
	}
}
void dfs2(int & ans,int u,int dad,int si) {
	dp[u]=0;
	for(int i=0;i<(int)eg[u].size();i++) {
		int v=eg[u][i];
		if(v==dad) continue;
		dfs2( ans,v,u,si );
		dp[u]=max( dp[u],siz[v] );
	}
	dp[u]=max( dp[u],si-siz[u] );
//	cout<<u<<"         "<<dp[u]<<endl;
	if( dp[u]<dp[ans] ) ans=u;
}
void doo() {
	for(int u=1;u<=n;u++) {
		int ans=u,an=0; dp[ans]=0x3f3f3f3f;
		for(int i=0;i<(int)eg[u].size();i++) {
			int v=eg[u][i];
			dfs1(v,u);
			if( siz[v]>siz[an] ) {
				an=v; ans=u;
				dfs2(ans,v,u,siz[v]);
			}
		}//cout<<an<<" ";
		printf("%d\n",ans);
//		puts("\n\n\n");
	}
}
signed main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++) {
		int u=read(), v=read();
		add(u,v);
	}
	if( rcd[maxd]==2 ){//Ò»ÌõÁ´
		for(int i=1;i<=n;i++) if( rcd[i]==1 ) mrk[1]=i;
		int now=mrk[1],tot=1,dad=0; id[now]=1;
		while(true) {
			bool fbi=false;
			for(int i=0;i<(int)eg[now].size();i++) {
				if( eg[now][i]==dad ) continue;
				dad=now; now=eg[now][i]; fbi=true;
				mrk[++tot]=now; id[now]=tot;
				break;
			}
			if(!fbi) break;
		}
		for(int i=1;i<=n;i++) {
			if( i>n/2 ) {
				int j=(i-1)/2;
				if( (i-1)&1 ) j++;
//				cout<<i<<"                           "<<j<<"\n";
				at[i]=mrk[j];
			} else {
				int j=i+(n-i)/2;
				if( ( n-i )&1 ) j++;
				at[i]=mrk[j];
			}
		} 
//		for(int i=1;i<=n;i++) cout<<mrk[i]<<" ";
//		puts("");
		for(int i=1;i<=n;i++) {
			printf("%d\n",at[ id[i] ]);
		}
		return 0;
	}
	if( rcd[maxd]==n-1 ) {//¾Õ»¨Í¼ 
		puts("2");
		for(int i=2;i<=n;i++) puts("1");
		return 0;
	}
	doo();
//	int t=clock(); cout<<t<<endl;
	return 0;
}
/*
7
1 3
2 3
2 4
4 7
6 5
7 6

7
1 2
1 3
1 4
1 5
1 6
1 7
*/
