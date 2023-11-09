#include<bits/stdc++.h>
using namespace std;
//bool isnum(char ch) { return ( ch>='0'&&ch<='9' ); }
//inline int read() { int x=0; bool f=false; char ch=getchar(); while(!isnum(ch)) { if(ch=='-') f=true; ch=getchar(); } while(isnum(ch)) { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); } return f ? -x : x; }
//inline void write(int x) { if(x<0) putchar('-'), x=-x; if(x>9) write(x/10); putchar(x%10+'0'); }
const int N=500;
int n; char ch[N];
int dp[1<<25];
bool p[1<<23][23];

int fa[1<<25],siz[1<<25],maxn=1<<23;
void init() { for(int i=0;i<=maxn;i++) fa[i]=i,siz[i]=1; }
int get(int x) { return x==fa[x] ? x : fa[x]=get(fa[x]); }
void us(int x,int y) { x=get(x); y=get(y); if(x!=y) { fa[x]=y,siz[y]+=siz[x], siz[x]=0; } }

int vip[1<<25];
void getnum(int x) {
	if(vip[x]) return ;
	int fux=x; vip[x]=true;
	for(int i=0;i<n;i++) p[x][i]=(fux&1), fux>>=1;
//	printf("x:%d :",x);
//	for(int i=0;i<n;i++) cout<<p[x][i];
//	puts("");
	for(int i=0;i<n-2;i++) {
		if(p[x][i]==1&&p[x][i+1]==1&&p[x][i+2]==0) {
			int nat=x-(1<<i)+(1<<(i+2));
			us(nat,x); getnum(nat);
//			printf("%d->%d\n",x,nat);
		}
	}
	for(int i=2;i<n;i++) {
		if(p[x][i]==1&&p[x][i-1]==1&&p[x][i-2]==0) {
			int nat=x-(1<<i)+(1<<(i-2));
			us(nat,x); getnum(nat);
//			printf("%d  ->  %d\n",x,nat);
		}
	} 
}
void dfs(int now,int x) {
	if(now>n) { /*cout<<x<<" ";*/ getnum(x); return ; }
	if(ch[now]!='?') { dfs(now+1,x*2+(ch[now]-'0')); return ; }
	dfs(now+1,x*2); dfs(now+1,x*2+1);
} int ans=0;
void dfs2(int now,int x) {
	if(now>n) { ans+=siz[get(x)]; /*cout<<x<<" "<<get(x)<<" "<<siz[get(x)]<<endl;*/ return ; }
	if(ch[now]!='?') { dfs2(now+1,x*2+(ch[now]-'0')); return ; }
	dfs2(now+1,x<<1); dfs2(now+1,x<<1|1);
}
signed main() {
//	freopen("ex_jumpgo3.in","r",stdin);
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
//	int bt=clock();
	scanf("%d%s",&n,ch+1);
	init();
	dfs(1,0); dfs2(1,0); printf("%d",ans);
//	int et=clock(); printf("   %d",et-bt);
	return 0;
}
/*
5
?0110
3
???
*/
