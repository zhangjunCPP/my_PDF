#include<bits/stdc++.h>
using namespace std;
const int N=1024;
const int mod=998244353;
int n,m,Q;
struct node { int u,v; }ed[N];
int rd[N];
bool vis[N],vip[N];
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&ed[i].u,&ed[i].v);
	scanf("%d",&Q);
	while(Q--) {
		string st; cin>>st;
		int s=0; 
		for(int i=0;i<(int)st.size();i++) {
			rd[i+1]=0; vis[i+1]=false;
			if( st[i]=='1' ) vis[i+1]=true;
		}
		for(int i=1;i<=m;i++) {
			vip[i]=false; s=s*2;
			if( vis[ed[i].u] && vis[ed[i].v] ) vip[i]=true,s++;
		}
		int ans=0;// cout<<s<<" ";
		for(int now=s;now;now=(now-1)&s) {
			int sn=now;
			for(int i=1;i<=n;i++) rd[i]=0;
			for(int i=m;i>=1;i--) {
//				cout<<( sn&1 )<<" ";
				if(sn&1) rd[ed[i].u]++,rd[ed[i].v]++;
				sn>>=1;
			} int fi=1;
//			puts("");
			for(int i=1;i<=n;i++) {
				if( vis[i] && rd[i]<2 ) { fi=0; break; }
			}
			ans+=fi;
		}
		printf("%d\n",ans);
	}
	return 0;
}
