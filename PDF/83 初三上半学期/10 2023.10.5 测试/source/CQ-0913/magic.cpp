#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e3+10;
void Freopen(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
}
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
} 
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
int n;
struct node{
	int l,r,c,id;
}a[MAXN];
bool vis[MAXN];
int tree[MAXN],ans=0;
inline int lowbit(int x){return x&(-x);}
inline void update(int x,int val){for(;x<=n;x+=lowbit(x)) tree[x]+=val;}
inline int query(int x){int ans=0; for(;x;x-=lowbit(x)) ans+=tree[x]; return ans;}
void dfs(int k,int sum){
	if(k==n+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		update(i,1);
		int cnt=query(a[i].r)-query(a[i].l-1);
		dfs(k+1,sum+max((a[i].r-a[i].l+1-cnt),0ll)*a[i].c);
		vis[i]=false;
		update(i,-1);
	}
}
signed main(){
	Freopen();
	read(n);
	int maxn=0;
	for(int i=1;i<=n;i++){
		read(a[i].l,a[i].r,a[i].c); a[i].id=i;
		maxn=max({i-a[i].l,a[i].r-i,maxn});
	} 
//	printf("maxn:%d\n",maxn);
	if(maxn<=0){printf("0"); return 0;}
	if(n<=11){dfs(1,0); printf("%lld\n",ans); return 0;}
//	if(maxn<=1){}
	sort(a+1,a+n+1,[](const node &x,const node &y){
		int len1=x.r-x.l+1,len2=y.r-y.l+1,w1=len1*x.c,w2=len2*y.c;
		if(x.id>=x.l && x.id<=x.r) w1-=x.c;
		if(y.id>=y.l && y.id<=y.r) w2-=y.c; 
		if(len1==len2) return x.c>y.c;
		return w1>w2;
	});
//	for(int i=1;i<=n;i++){
//		printf("id:%d l:%d r:%d c:%d\n",a[i].id,a[i].l,a[i].r,a[i].c);
//	}
	for(int i=1;i<=n;i++){
		vis[a[i].id]=true;
		for(int j=a[i].l;j<=a[i].r;j++){
			if(vis[j]) continue;
			ans+=a[i].c;
		}
	}
	printf("%lld",ans);
	return 0;
} 
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5

12
1 3 861
2 4 822
1 3 286
2 4 236
5 6 335
4 9 837
3 11 469
7 12 846
9 12 258
6 12 139
7 12 932
12 12 411

11
1 7 1
2 8 1
3 9 1
4 10 1
5 11 1
6 12 1
7 12 1
8 12 1
9 12 1
10 12 1
11 12 1
*/
