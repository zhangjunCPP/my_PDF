//the code is from chenjh
#include<cstdio>
#define MAXN 2002
const int mod=998244353;
int n;
int a[MAXN];

#define lson rt<<1
#define rson rt<<1|1
int s[MAXN<<2],lz[MAXN<<2];
void pd(int rt,int l,int r){
	if(!lz[rt]) return;
	int mid=(l+r)>>1;
	s[lson]+=(mid-l+1)*lz[rt],lz[lson]+=lz[rt];
	s[rson]+=(r-mid)*lz[rt],lz[rson]+=lz[rt];
	lz[rt]=0;
}
void update(int rt,int l,int r,int L,int R,int val){
	if(L<=l && r<=R){s[rt]+=(r-l+1)*val,lz[rt]+=val;return;}
	pd(rt,l,r);
	int mid=(l+r)>>1;
	if(L<=mid) update(lson,l,mid,L,R,val);
	if(mid<R) update(rson,mid+1,r,L,R,val);
	s[rt]=s[lson]+s[rson];
}
int query(int rt,int l,int r,int L,int R){
	if(L<=l && r<=R)return s[rt];
	pd(rt,l,r);
	int mid=(l+r)>>1,ret=0;
	if(L<=mid) ret+=query(lson,l,mid,L,R);
	if(mid<R) ret+=query(rson,mid+1,r,L,R);
	return ret;
}
//Ïß¶ÎÊ÷ºÃÉÁ£¬°ÝÐ»Ïß¶ÎÊ÷£¡ 

int ans=0;
#ifdef DEBUG
int A[2002];
#endif
void dfs(int x,int lt,int lt2){
	if(x>n){
		++ans;if(ans>=mod) ans-=mod;
		#ifdef DEBUG
		for(int i=1;i<=n;i++) printf("%d ",A[i]);
		putchar('\n');
		#endif
		return;
	}
	#ifdef DEBUG
//	printf("x = %d\n",x);
//	for(int i=1;i<=n;i++) printf("%d ",query(1,1,n,i,i));
//	putchar('\n');
	#endif
	for(int i=1;i<=n;i++){
		if(i==lt || i==lt2 || query(1,1,n,i,i)) continue;
		if(a[x]==1){
			update(1,1,n,i,i,1);
			#ifdef DEBUG
			A[x]=i;
			#endif
			dfs(x+1,i+1,i-1);
			#ifdef DEBUG
			A[x]=0;
			#endif 
			update(1,1,n,i,i,-1);
			continue;
		}
		if(i+a[x]-1<=n && !query(1,1,n,i,i+a[x]-1)){
			update(1,1,n,i,i+a[x]-1,1);
			#ifdef DEBUG
			for(int j=0;j<a[x];j++) A[x+j]=i+j; 
			#endif
			dfs(x+a[x],i+a[x],0);
			update(1,1,n,i,i+a[x]-1,-1);
			#ifdef DEBUG
			for(int j=0;j<a[x];j++) A[x+j]=0; 
			#endif
		}
		if(i>a[x]-1 && !query(1,1,n,i-a[x]+1,i)){
			update(1,1,n,i-a[x]+1,i,1);
			#ifdef DEBUG
			for(int j=0;j<a[x];j++) A[x+j]=i-j; 
			#endif
			dfs(x+a[x],i-a[x],0);
			update(1,1,n,i-a[x]+1,i,-1);
			#ifdef DEBUG
			for(int j=0;j<a[x];j++) A[x+j]=0; 
			#endif
		}
	}
}
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}

/*
//the code is from chenjh
#include<cstdio>
#include<algorithm>
const int mod=998244353;
int n;
int a[2002],p[2002],b[2002],c[2002];
int main(){
//	freopen("gap.in","r",stdin);
//	freopen("gap.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[i]=i;
	int ans=0;
	do{
//		for(int i=1;i<=n;i++) printf("%d ",p[i]);
//		putchar('\n');
		b[1]=c[n]=1;
		for(int i=2;i<=n;i++) b[i]=p[i-1]+1==p[i]?b[i-1]+1:1;
		for(int i=n-1;i>0;i--) p[i]+1==p[i+1]&&(b[i]=b[i+1]),c[i]=p[i+1]+1==p[i]?c[i+1]+1:1;
		bool f=0;
//		for(int i=1;i<=n;i++) printf("%d ",b[i]);
//		putchar('\n');putchar('\n');
		for(int i=2;i<=n;i++){
			c[i]=p[i-1]==1+p[i]?c[i-1]:c[i];
			b[i]=std::max(b[i],c[i]);
			if(b[i]!=a[i]){f=1;break;}
		}
		if(f) continue;
		++ans;if(ans>=mod) ans-=mod;
	}while(std::next_permutation(p+1,p+n+1));
	printf("%d\n",ans);
	return 0;
}
*/
