#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=128;
const int mod=1e9+7;
int T,n,m,k;
struct edge { int u,v,d,s; } eg[N];

int fa[N];
int get(int x) { return x==fa[x] ? x : fa[x]=get(fa[x]); }
void us(int x,int y) { x=get(x); y=get(y); if(x!=y) fa[x]=y; }

#define ppt pair<int,int>
#define mmp make_pair
map<ppt,int> mp;
bool vip[N];

signed main() {
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld%lld%lld",&n,&m,&k);
		int tot=0; mp.clear();
		for(int i=1;i<=m;i++) {
			int u,v,d,s;
			scanf("%lld%lld%lld%lld",&u,&v,&d,&s);
			ppt xp=mmp(u,v);
			if(mp.count(xp)) {
				int sp=mp[xp];
				eg[sp].d*=d; eg[sp].s*=s;
				eg[sp].d%=mod; eg[sp].s%=mod;
			} else mp[xp]=mp[mmp(v,u)]=++tot,eg[tot]=(edge) { u,v,d,s };
		} m=tot;
//		cout<<eg[tot].d<<" "<<eg[tot].s<<endl;
//		for(int i=1;i<=m;i++) {
//			printf("%lld->%lld    d:%lld s:%lld\n",eg[i].u,eg[i].v,eg[i].d,eg[i].s);
//		}
		int maxn=( 1<<m )-1; int ant=0;
		for(int x=0;x<=maxn;x++) {
			int xp=x,ans=1,num=0,cpm=1;
//			int xm=x;
//			for(int i=1;i<=m;i++) printf("%lld",( xm&1 )), xm>>=1;
//			puts("");
			for(int i=1;i<=n;i++) fa[i]=i;
			for(int i=1;i<=m;i++) vip[i]=false;
			
			for(int i=1;i<=m;i++) {
				if(xp&1) ans=( ans*eg[i].s )%mod, us(eg[i].u,eg[i].v);
				else ans=( ans*eg[i].d )%mod,vip[i]=true;
//				cout<<i<<" "<<ans<<endl;
				xp>>=1;
			} 
			for(int i=1;i<=m;i++) if(vip[i]&&( get(eg[i].u)==get(eg[i].v) )) { ans=0; break; }
//			cout<<"    "<<ans<<" \n";
			if(!ans) continue;
			
			for(int i=1;i<=n;i++) if(i==get(i)) num++;
			
			if(k<num) continue;
			for(int i=1;i<=num;i++) cpm=cpm*(k-i+1)%mod;
			ant=( ant+ans*cpm%mod )%mod;
		} printf("%lld\n",ant);
	}
	return 0;
}
/*
1
5 17 9
1 3 3 7
2 4 8 7
2 5 6 1
2 1 7 3
2 3 5 2
2 4 6 5
3 4 5 6
2 1 5 8
1 2 6 3
2 3 2 1
2 1 7 0
2 5 4 7
2 5 2 5
2 1 1 7
2 5 7 5
2 4 6 7
2 4 5 2

*/
