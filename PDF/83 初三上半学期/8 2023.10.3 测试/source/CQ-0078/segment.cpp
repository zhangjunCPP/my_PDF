/*
题目=把两个合在一起 
我们并不关心除最大小值外的东西，我们只需要保证>=最小值<=最大值
我们枚举最大值 O(n+n-1)=O(2n-1)
保证比单个的大。
只需要保证比单个的小
如果比单个的大，那就钦定这两个必须和在一起
且和比最小值大，最大值小。
如果几个连续的情况就从小到大依次来 
有矛盾就GG，就把最小值调小一点，否则相反。
f**kf**kf**kf**kf**kf**kf**kf**k
*/
#include<bits/stdc++.h>
void read(int &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int tot=0;
	do stk[++tot]=x%10+48,x/=10;while(x);
	for(;tot;tot--)putchar(stk[tot]);
}
int max(const int x,const int y){return x>y?x:y;}
int min(const int x,const int y){return x<y?x:y;}

#define inf 0x3f3f3f3f
const int maxn=2004;
int n,a[maxn],maxx,ans=inf,id,id2;
int vis[maxn];
int lp,xx,yy;
bool check(int mid){
	memset(vis,0,sizeof(vis));
	if(xx!=-1)vis[xx]=vis[xx+1]=-1;
	else vis[id]=-1;
//	if(yy!=-1)vis[yy]=vis[yy+1]=-1;
//	else vis[id2]=-1;
	for(int i=1;i<=n;++i)
		if(vis[i]!=-1&&mid>a[i])
			vis[i]=1;
	for(int i=1;i<n;++i)
		if(vis[i]==1){
			if(vis[i+1]!=-1&&a[i]+a[i+1]>=mid&&a[i]+a[i+1]<=lp)vis[i]=vis[i+1]=0;
			else return 0;
		}
	if(vis[n]==1)return 0;
	return 1;
}
void solve(){//lp为最大值 
	if(check(lp-248))write('*');
	for(int i=1;i<=n;++i)
		if(i!=xx&&i!=xx+1){
			yy=-1;id2=i;
			if(check(a[i]))ans=min(ans,lp-a[i]);
		}
	for(int i=1;i<n;++i){
		if(i!=xx+1&&i!=id&&a[i]+a[i+1]<=lp){
			yy=i;
			if(check(a[i]+a[i+1]))ans=min(ans,lp-a[i]-a[i+1]);
		}
	}
}
signed main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)read(a[i]),maxx=max(maxx,a[i]);
	//接下来为单个为最大值
	for(int i=1;i<=n;++i)
		if(a[i]==maxx){
			lp=maxx;xx=-1;id=i;
			solve();
		}
	//接下来为双个为最大值 
	for(int i=1;i<n;++i){
		xx=i;id=-1;
		lp=a[i]+a[i+1];
		if(lp>=maxx)solve();
	}
	write(ans);
	return 0;
}
