#include<bits/stdc++.h>
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
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
int n,m,vis[500005],ans[500005],num;
struct node{
	int val[2000005];
	void change(int k,int l,int r,int x,int v){
		if(l>x||r<x)
			return ;
		if(l==r&&l==x){
			val[k]+=v;
			return ;
		}
		int mid=(l+r)>>1;
		change(2*k,l,mid,x,v);
		change(2*k+1,mid+1,r,x,v);
		val[k]=val[2*k]+val[2*k+1]; 
	}
	int query(int k,int l,int r,int x,int y){
		if(l>y||r<x)
			return 0;
		if(l>=x&&r<=y)
			return val[k];
		int mid=(l+r)>>1;
		return query(2*k,l,mid,x,y)+query(2*k+1,mid+1,r,x,y);
	}
}tree;
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	n=read();
	m=read();
	for(int i=1,x;i<=m;i++){
		x=read();
		if(!vis[x]){
			num++;
			ans[n]++;
		}
		else//不同元素个数 
			ans[tree.query(1,1,m,vis[x]+1,i)]++;
		if(vis[x])
			tree.change(1,1,m,vis[x],-1);
		vis[x]=i;
		tree.change(1,1,m,vis[x],1);
	}
	for(int i=n;i;i--){
		ans[i]=ans[i]+ans[i+1];
	}
	for(int i=1;i<=n;i++){
		work(ans[i]);
		if(i!=n)
			putchar(' ');
	}
	return 0;
}
