#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
    putchar(k%10+'0');
}
//放弃
int n,w[500005],first[500005],cnt,vis[500005],dp[500005],b[500005];
struct q1{
    int u,w,nex;
}a[1000005];
void add(int u1,int w1){
    a[++cnt]={u1,w1,first[u1]};
    first[u1]=cnt;
}
vector<int> q;
struct node{
    int val[2000005];
    void build(int k,int l,int r){
        if(l==r){
            val[k]=-1e9;
            return ;
        }
        int mid=(l+r)>>1;
        build(2*k,l,mid);
        build(2*k+1,mid+1,r);
        val[k]=max(val[2*k],val[2*k+1]);
    }
    void change(int k,int l,int r,int x,int v){
        if(l>x||r<x)
            return ;
        if(l==r&&l==x){
            val[k]=max(val[k],v);
            return ;
        }
        int mid=(l+r)>>1;
        change(2*k,l,mid,x,v);
        change(2*k+1,mid+1,r,x,v);
        val[k]=max(val[2*k],val[2*k+1]);
    }
    int query(int k,int l,int r,int x,int y){
        if(l>y||r<x)
            return -1e9;
        if(l>=x&&r<=y)
            return val[k];
        int mid=(l+r)>>1;
        return max(query(2*k,l,mid,x,y),query(2*k+1,mid+1,r,x,y));
    }
}tree;
void dfs(int u,int dad,int del){
    vis[u]=1;
    dp[u]=tree.query(1,1,n,1,w[u]-1)+1;
    tree.change(1,1,n,w[u],dp[u]);
    for(int i=first[u];i;i=a[i].nex){
        if(a[i].w==dad||a[i].w==del)
            continue;
        dfs(a[i].w,u,del);
    }
}
int main(){
	freopen("lis.in","r",stdin);
    freopen("lis.out","w",stdout);
    srand(time(0));
    n=read();
    for(int i=1,x,y;i<n;i++){
        x=read();
        y=read();
    }
    for(int i=1;i<=n;i++){
        w[i]=read();
        b[i]=w[i];
    }
    sort(b+1,b+n+1);
    int len=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++){
        w[i]=lower_bound(b+1,b+len+1,w[i])-b;
    }
    work(rand()%n+1);
	return 0;
}