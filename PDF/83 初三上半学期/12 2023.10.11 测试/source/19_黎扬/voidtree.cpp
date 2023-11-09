#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
int id,op,n,q,cnt,first[200005],tot,p[200005],h[200005],g[200005],flag,vis[200005];
ll last,sum1,ans,dp[1005][105],f[1005][105];
struct q1{
	int u,w,v,nex;
}a[400005];
void add(int u1,int w1,int v1){
	a[++cnt]={u1,w1,v1,first[u1]};
	first[u1]=cnt;
}
void decode(int &l,int &r,int &k,ll las){
	las%=19260817;
	l^=las;
	l=(l%n+n)%n+1;
	r^=las;
	r=(r%n+n)%n+1;
	if(l>r)
		swap(l,r);
	k^=las;
	k=(k%min(r-l+1,100))+1;
}
struct node{
	int val[4000005],L[4000005],R[4000005],root[200005];
	ll s[4000005];
	void change(int &k,int l,int r,int x,int v,int pre){
		k=++tot;
		val[k]=val[pre]+1;
		s[k]=s[pre]+v;
		L[k]=L[pre];
		R[k]=R[pre];
		if(l==r)
			return ;
		int mid=(l+r)>>1;
		if(x<=mid)
			change(L[k],l,mid,x,v,L[pre]);
		else
			change(R[k],mid+1,r,x,v,R[pre]);
	}
	int query_val(int k,int l,int r,int pre,int now){
		if(l==r)
			return l;
		int mid=(l+r)>>1,sum=val[R[k]]-val[R[pre]];
		if(sum>=now)
			return query_val(R[k],mid+1,r,R[pre],now);
		return query_val(L[k],l,mid,L[pre],now-sum);
	}
	ll query_sum(int k,int l,int r,int x,int y,int pre){
		if(l>y||r<x)
			return 0;
		if(l>=x&&r<=y)
			return s[k]-s[pre];
		int mid=(l+r)>>1;
		return query_sum(L[k],l,mid,x,y,L[pre])+query_sum(R[k],mid+1,r,x,y,R[pre]);
	}
}tree;
bool getans(int u,int dad){
	int flag=vis[u];
	for(int i=first[u];i;i=a[i].nex){
		if(a[i].w==dad)
			continue;
		if(getans(a[i].w,u)){
			sum1+=a[i].v;
			flag=1;
		}
	}
	return flag;
}
void dfs(int r,int k,int now,int num1){
	if(now>r){
		if(num1!=k)
			return ;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum1=0;
				getans(i,0);
				ans=max(ans,sum1);
				return ;
			}
		}
		return ;
	}
	dfs(r,k,now+1,num1);
	vis[p[now]]=1;
	dfs(r,k,now+1,num1+1);
	vis[p[now]]=0;
}
void dfs1(int u,int dad,int k){
	for(int j=0;j<=k;j++){
		f[u][j]=dp[u][j]=-1e18;
	}
	if(vis[u])
		dp[u][1]=f[u][1]=0;
	for(int i=first[u];i;i=a[i].nex){
		if(a[i].w==dad)
			continue;
		dfs1(a[i].w,u,k);
		for(int j=k;j;j--){
			if(dp[u][j]<dp[a[i].w][j]){
				dp[u][j]=dp[a[i].w][j];
				f[u][j]=f[a[i].w][j]+a[i].v;
			}
			if(vis[u]){
				if(dp[u][j]<dp[a[i].w][j-1]+f[a[i].w][j-1]+a[i].v){
					dp[u][j]=dp[a[i].w][j-1]+f[a[i].w][j-1]+a[i].v;
					f[u][j]=0;
				}
			}
			for(int gg=1;gg<j;gg++){
				if(dp[u][j]<dp[a[i].w][gg]+dp[u][j-gg]+f[u][j-gg]+f[a[i].w][gg]+a[i].v){
					dp[u][j]=dp[a[i].w][gg]+dp[u][j-gg]+f[u][j-gg]+f[a[i].w][gg]+a[i].v;
					f[u][j]=0;
				}
			}
		}
	}
}
int main(){
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout);
	id=read();
	op=read();
	n=read();
	for(int i=1,x,y,z;i<n;i++){
		x=read();
		y=read();
		z=read();
		if(x==1)
			h[y]=z;
		else if(y==1)
			h[x]=z;
		if(x==1||y==1)
			flag++;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;i++){
		g[i]=h[i];
	}
	sort(g+1,g+n+1);
	int len=unique(g+1,g+n+1)-g;
	for(int i=1;i<=n;i++){
		p[i]=read();
		tree.change(tree.root[i],1,n,lower_bound(g+1,g+len+1,h[p[i]])-g,h[p[i]],tree.root[i-1]);
	}
	q=read();
	while(q--){
		int l,r,k;
		l=read();
		r=read();
		k=read();
		if(op)
			decode(l,r,k,last);
		if(flag==n-1){
			if(k==1){
				work(0);
				putchar('\n');
				continue;
			}
			ll now=tree.query_val(tree.root[r],1,n,tree.root[l-1],k);
			work(last=tree.query_sum(tree.root[r],1,n,now,n,tree.root[l-1]));
			putchar('\n');
			continue;
		}
		if(n<=8){
			ans=0;
			dfs(r,k,l,0);
			work(last=ans);
			putchar('\n');
			continue;
		}
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		for(int i=l;i<=r;i++){
			vis[p[i]]=1;
		}
		dfs1(1,0,k);
		work(dp[1][k]);
		putchar('\n');
	}
	return 0;
}
/*
0
0 7
1 2 789236
1 3 5734892
1 4 5437959
1 5 574895
1 6 89347985
1 7 56734
1 2 5 7 4 6 3
4
1 2 2
2 5 3
3 7 3
3 7 4
*/
