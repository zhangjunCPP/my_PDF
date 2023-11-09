#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15,M=1e6+16;
int n,m,a[N],b[N];
int cnt[N];
bool vis[N],vip[N];
vector<int> fk;
signed main() {
//	freopen("ex_data2.in","r",stdin);
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	scanf("%d%d",&n,&m); int nun=0;
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),fk.push_back(a[i]),fk.push_back(b[i]);
	for(int px=0;px<(int)fk.size();px++) {
		int x=fk[px]; if(vip[x]) continue;
		vip[x]=true; nun++;
		for(int j=1;j<=m;j++) vis[j]=false;
		int i=1; vis[x]=true;
		while(true) {
			if( vis[a[i]]&&vis[b[i]] ) break;
			if( !vis[a[i]] ) vis[a[i]]=true;
			else vis[b[i]]=true;
			i++; if(i>n) i=1;
		} cnt[i]++;
	}
	int anp=0;
	for(int i=1;i<=m;i++) { if(!vip[i]) anp=i; }
	if(anp) {
		int num=m-nun; int x=anp;
		for(int j=1;j<=m;j++) vis[j]=false;
		int i=1; vis[x]=true;
		while(true) {
			if( vis[a[i]]&&vis[b[i]] ) break;
			if( !vis[a[i]] ) vis[a[i]]=true;
			else vis[b[i]]=true;
			i++; if(i>n) i=1;
		} cnt[i]+=num;
	}
	for(int i=1;i<=n;i++) printf("%d\n",cnt[i]);
	return 0;
}
