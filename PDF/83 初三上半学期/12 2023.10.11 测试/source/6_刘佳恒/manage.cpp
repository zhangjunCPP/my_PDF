#include<bits/stdc++.h>
using namespace std;
bool isnum(char ch) { return ( ch>='0'&&ch<='9' ); }
inline int read() { int x=0; bool f=false; char ch=getchar(); while(!isnum(ch)) { if(ch=='-') f=true; ch=getchar(); } while(isnum(ch)) { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); } return f ? -x : x; }
inline void write(int x) { if(x<0) putchar('-'), x=-x; if(x>9) write(x/10); putchar(x%10+'0'); }
const int N=5e5+55;
int n,m,a[N],tot,p[N];
int nut[N];
vector<int> wh[N];
bool vit[N];
struct Tree {
	int t[N];
	#define lson k<<1
	#define rson k<<1|1
	void update(int k) { t[k]=t[lson]+t[rson]; }
	void change(int k,int l,int r,int x) {
		if(l==r) { t[k]++; return ; }
		int mid=(l+r)>>1;
		if( x<=mid ) change(lson,l,mid,x);
		else change(rson,mid+1,r,x);
		update(k);
	}
	int alt(int k,int l,int r,int x,int y) {
		if(x<=l&&r<=y) return t[k];
		int mid=(l+r)>>1,ans=0;
		if(x<=mid) ans+=alt(lson,l,mid,x,y);
		if(y>mid) ans+=alt(rson,mid+1,r,x,y);
		return ans;
	}
}tr;
int ant[N];
void ditans() {
	for(int i=tot;i>=1;i--) tr.change(1,1,n,nut[i]);
//	for(int i=1;i<=tot;i++) cout<<nut[i]<<" ";
//	puts("");
	int latkb=0;
	for(int i=1;i<=n;i++) {
		int anp=tr.alt(1,1,n,1,i); int kb=tot-anp;
//		cout<<i<<" "<<anp<<" "<<kb<<endl;
		if(kb==latkb) ant[i]=ant[i-1];
		else ant[i]=i+kb, latkb=kb;
	} 
	for(int i=1;i<=n;i++) write(ant[i]), putchar(' ');
}
int nas;
struct query{ int l,r,id; } q[N];
int len,dl[N];
bool cmp(query x,query y) {
	if( dl[x.l]!=dl[y.l] ) return dl[x.l]<dl[y.l];
	if( x.l&1 ) return x.r>y.r;
	return x.r<y.r;
}
struct MD {
	void init() {
		len=sqrt(tot);
		if(len) for(int i=1;i<=len;i++) dl[i]=( i-1 )%len+1;
	}
	int cnt[N],sum=0;
	void in(int x) { if(!cnt[x]) sum++; cnt[x]++; }
	void out(int x) { cnt[x]--; if(!cnt[x]) sum--; }
	void doo() {
		sort(q+1,q+1+nas,cmp);
		for(int i=0;i<=n;i++) cnt[i]=0;
		int l=1,r=0; sum=0;
		for(int i=1;i<=nas;i++) {
			int L=q[i].l,R=q[i].r;
//			printf("%d %d %d\n",q[i].id,L,R);
			while(R>r) in(p[++r]);//,cout<<r<<" ";
//			puts("");
			while(l>L) in(p[--l]);//,cout<<l<<" ";
//			puts("");
			while(l<L) out(p[l++]);//,cout<<l<<" ";
//			puts("");
			while(r>R) out(p[r--]);//,cout<<r<<" ";
//			puts("");
//			cout<<l<<" " <<r<<endl;
//			puts("");
			nut[q[i].id]=sum;
		}
	}
}md;
void indoo() { //p[tot+1]=p[tot];
	for(int i=1;i<=n;i++) { 
		wh[i].push_back(tot+1);
		for(int j=0;j<(int)wh[i].size()-1;j++) {
			q[++nas]=(query) { wh[i][j], wh[i][j+1]-1, wh[i][j] };
		}
	} md.doo(); ditans();
}
signed main() {
//	freopen("ex_manage3.in","r",stdin);
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=m;i++) {
//		scanf("%d",&a[i]);
		a[i]=read();
		if(a[i]!=a[i-1]) p[++tot]=a[i];
	} for(int i=1;i<=tot;i++) wh[p[i]].push_back(i);
	if(n<=10000) {
		for(int i=1;i<=n;i++) { wh[i].push_back(tot+1);
			for(int j=0;j<(int)wh[i].size()-1;j++) {
				int now=wh[i][j], net=wh[i][j+1];
				for(int k=1;k<=n;k++) vit[k]=false;
				for(int k=now;k<net;k++) vit[p[k]]=true;//, cout<<k<<"  "<<p[k]<<"\n"; 
//				puts("\n");
				int anp=0; for(int k=1;k<=n;k++) anp+=vit[k];//, cout<<k<<" "<<vit[k]<<"\n";
//				cout<<now<<" "<<net<<" "<<anp<<endl; 
				nut[now]=anp;
			}
		}
		ditans(); return 0;
	}/**/
	indoo();
	return 0;
}
