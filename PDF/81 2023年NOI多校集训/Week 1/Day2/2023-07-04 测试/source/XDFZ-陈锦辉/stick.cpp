//the code is from chenjh
#include<cstdio>
#include<cstring>
int n,m,e;
int f1(int x,int r){return x-1+(r-x+1)*(r-x+1);}
int f2(int x,int r){
	int q=r/x,t=r%x;
	return (x-t)*q*q+t*(q+1)*(q+1);
}
bool dfs(int x,int p,int lt,int s,int sum){
//	printf("%d %d %d %d %d\n",x,p,lt,s,sum);
	if(x>p) return /*printf("%d %d\n",sum,e),*/sum==e;
	if(n-s<p-x+1 || sum+f2(p-x+1,n-s)>e || sum+f1(p-x+1,n-s)<e) return 0;
	for(int i=lt,mi=n-s;i<=mi;i++){
		if(dfs(x+1,p,i,s+i,sum+i*i)) return 1;
	}
	return 0;
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int Q;scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&n,&m);
		if(!m || m==((n*(n-1))>>1)){puts("1");continue;}
		if(m>((n*(n-1))>>1) || n*n-(m<<1)<0){puts("0");continue;}
		int l;
		for(l=1,e=n*n-(m<<1);l<=n && !dfs(1,l,1,0,0);++l);
		putchar('0'|(l<=n));putchar('\n');
	}
	return 0;
}
/*
//the code is from chenjh
#include<cstdio>
#include<cstring>
#include<algorithm>
int n,m;
int a[505<<2];
#define lson rt<<1
#define rson rt<<1|1
void update(int rt,int l,int r,int pos,int val){
	if(l==r && l==pos){a[rt]+=val;return;}
	int mid=(l+r)>>1;
	if(pos<=mid) update(lson,l,mid,pos,val);
	else update(rson,mid+1,r,pos,val);
	a[rt]=a[lson]+a[rson];
}
int query(int rt,int l,int r,int L,int R){
	if(L<=l && r<=R) return a[rt];
	int mid=(l+r)>>1,ret=0;
	if(L<=mid) ret+=query(lson,l,mid,L,R);
	if(mid<R) ret+=query(rson,mid+1,r,L,R);
	return ret;
}
int f(const int r,const int p){//r£ºÊ£ÓàÄ¾°ôÊýÁ¿¡£ 
	if(p<1) return r;
	int ret=n;
	int sum=query(1,1,n,1,p);
	for(int i=1;i<=p;i++) ret=std::min(ret,sum-query(1,1,n,i,i));
	return ret*r;
}
bool dfs(const int x,const int p,const int sum){
	if(x>n) return sum==m;
	if(sum+f(n-x+1,p)>m) return 0;
	int Sum;
	for(int i=1;i<=p;i++){
		update(1,1,n,i,1);
		Sum=sum;
		if(1<i) Sum+=query(1,1,n,1,i-1);
		if(i<p) Sum+=query(1,1,n,i+1,p);
		if(dfs(x+1,p,Sum)) return 1;
		update(1,1,n,i,-1);
	}
	update(1,1,n,p+1,1);
	Sum=sum;
	if(1<=p) Sum+=query(1,1,n,1,p);
	if(dfs(x+1,p+1,Sum)) return 1;
	update(1,1,n,p+1,-1);
	return 0;
}
int main(){
//	freopen("stick.in","r",stdin);
//	freopen("stick.out","w",stdout);
	int Q;scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&n,&m);
		if(!m || m==((n*(n-1))>>1)){puts("1");continue;}
		if(m>((n*(n-1))>>1)){puts("0");continue;}
		memset(a,0,sizeof a);
		putchar('0'|dfs(1,0,0));putchar('\n');
	}
	return 0;
}
*/
