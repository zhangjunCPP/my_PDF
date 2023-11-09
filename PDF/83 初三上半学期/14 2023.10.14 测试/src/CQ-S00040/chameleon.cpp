#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+15,K=100;
int n,k,len;
struct node { int l,b; bool xp; } p[N];
ll ans[N];
bool cmp(node x,node y) { return x.xp==y.xp ? x.l<y.l : x.xp<y.xp; }
ll f[2][K][K],sumc;
int sm[N],col[N];
signed main() {
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%d%d%d",&n,&k,&len);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&p[i].l,&p[i].b);
		char ch; cin>>ch; p[i].xp=(ch=='D');
	} sort(p+1,p+1+n,cmp);
	int tot=0,csp=0;
	for(int i=1;i<=n;i++) {
//		cout<<p[i].xp<<" "<<p[i].l<<endl;
		if( p[i].xp==1 ) { ans[p[i].b]+=( len-p[i].l )*2; sm[++tot]=p[i].l; col[tot]=p[i].b; }
		else csp++;
	} sm[++tot]=len+1;
	int sp=0,snow=1;
	while( snow<=csp && p[snow].l<sm[1] ) {
		int lenp=p[snow].l;
		ans[p[snow].b]+=lenp*2;
		snow++;
	}
	for(int now=1;now<=tot;now++) {
		int lent=sm[now]-sm[now-1];
		if(now==1) lent=0;
		while( snow<=csp && p[snow].l<sm[now] ) {
			int lenp=p[snow].l-sm[now-1];
//			cout<<p[snow].l<<"   "<<p[snow].b<<"  "<<edcol[sp^1][ p[snow].b ]<<endl;
			ans[p[snow].b]+=lenp;
			int sxp=( p[snow].b+sumc )%k;
//			cout<<p[snow].l<<" "<<lenp<<" "<<sm[1]<<endl;
			for(int i=0;i<k;i++) {
				if(i==sxp) ans[i]+=sm[1]+sm[1]+( p[snow].l-sm[1] );
				ans[i]+=f[sp^1][p[snow].b][i];
			}
			snow++;
		} sumc+=col[now]; sumc%=k;
//		for(int i=0;i<k;i++) printf("%d ",ans[i]);
//		puts("");
		for(int i=0;i<k;i++) {
			int scol=(i+col[now])%k;
			for(int j=0;j<k;j++) 
				f[sp][i][j]=f[sp^1][scol][j]+( scol==j ? lent : 0 );
//			printf("%d->%d   ",i,scol);
		} sp^=1; //puts("");
//		for(int i=0;i<k;i++) {
//			for(int j=0;j<k;j++) {
//				printf("f[%d][%d][%d]=%d   ",now,i,j,f[sp^1][i][j]);
//			} puts("");
//		} puts("");
	} /**/
	for(int i=0;i<k;i++) printf("%.1lf\n",(double)ans[i]/2.0);
	return 0;
} 
/*
2 3 10
0 0 D
10 1 L

4 3 7
1 0 D
3 0 D
4 1 L
6 2 D

4 4 5
1 1 D
3 3 L
4 2 D
5 0 L
*/
