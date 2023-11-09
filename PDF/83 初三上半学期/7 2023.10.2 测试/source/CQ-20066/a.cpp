#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
//template<int N> class BIT{
//private:
//	int c[N][N],n;
//	int lowbit(int x){ return x&(-x); }
//	void update(int x,int y,int val){
//		for(int i=x;i<=n;i+=lowbit(i)) for(int j=y;j<=n;j+=lowbit(j))
//			c[x][y]+=val;
//	}
//	int ask(int x,int y){
//		int res=0;
//		for(int i=x;i;i-=lowbit(i)) for(int j=y;j;j-=lowbit(j))
//			res+=c[x][y];
//		return res;
//	}
//public:
//	void init(int nn){ n=nn; }
//	void modify(int xl,int yl,int xr,int yr,int val){
//		update(xr,yr,val),update(xl-1,yr-1,val);
//		update(xr,yl-1,-val),update(xl-1,yr,-val);
//	}
//	int query(int xl,int yl,int xr,int yr){
//		return ask(xr,yr)+ask(xl-1,yl-1)-ask(xr,yl-1)-ask(xl-1,yr);
//	}
//};
const int N=25e4+5;
const pair<int,int> dxy[8]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
int n,m,q;
int xl[N],yl[N],xr[N],yr[N];
namespace sub1{
	const int lim=1025;
	int cnt[1005][1005];
	void work(){
		for(int i=1;i<=n;i++){
			for(int j=xl[i];j<=xr[i];j++) for(int k=yl[i];k<=yr[i];k++) cnt[j][k]++;
		}
		while(m--){
			int v,r,d; _(v),_(r),_(d);
			int dx=dxy[v].first,dy=dxy[v].second;
			for(int i=1;i<=d;i++){
				xl[r]+=i*dx,yl[r]+=i*dy,xr[r]+=i*dx,yr[r]+=i*dy;
				for(int j=xl[r];j<=xr[r];j++) for(int k=yl[r];k<=yr[r];k++) cnt[j][k]++;
			}
		}
		while(q--){
			int px,py; _(px),_(py);
			printf("%d\n",cnt[px][py]);
		}
	}
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	_(n),_(m),_(q);
	for(int i=1;i<=n;i++) _(xl[i]),_(yl[i]),_(xr[i]),_(yr[i]);
	sub1::work();
	return 0;
}

