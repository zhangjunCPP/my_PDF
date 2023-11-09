#include<bits/stdc++.h>
using namespace std;
int n,tot,a[700001],root[700001],lc[56000001],rc[56000001],dat[56000001];
long long ans;
int build(int l,int r){
	int p=++tot,mid=(l+r)>>1;
	if(l==r) return p;
	lc[p]=build(l,mid);
	rc[p]=build(mid+1,r);
	return p;
}
int insert(int p,int l,int r,int x){
	int q=++tot,mid=(l+r)>>1;
	dat[q]=dat[p]+1,lc[q]=lc[p],rc[q]=rc[p];
	if(l==r) return q;
	if(x<=mid) lc[q]=insert(lc[p],l,mid,x);
	else rc[q]=insert(rc[p],mid+1,r,x);
	return q;
}
int query(int p,int l,int r,int L,int R){
	if(L<=l&&r<=R) return dat[p];
	int mid=(l+r)>>1,sum=0;
	if(L<=mid) sum+=query(lc[p],l,mid,L,R);
	if(R>mid) sum+=query(rc[p],mid+1,r,L,R);
	return sum;
}
void solve(int x,int y){
	if(x>=y) return;
	ans+=y-x+1;
	int c=(y-x+2)/2,l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(query(root[mid],1,n,x,y)<c) l=mid+1;
		else r=mid;
	}
	solve(x,a[l]-1);
	solve(a[l]+1,y);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	root[0]=build(1,n);
	for(int i=1;i<=n;i++) root[i]=insert(root[i-1],1,n,a[i]);
	solve(1,n);
	printf("%lld",ans);
	return 0;
}
/*
void I_am_joker(int l,int r){
	if(l>=r) return;
	ans+=r-l+1;
	int _86_=(r-l+2)/2,start;
	for(int i=1,Genshin=0;i<=n;i++){
		if(a[i]>=l&&a[i]<=r){
			Genshin++;
			if(_86_==Genshin){
				start=a[i];
				break;
			}
		}
	}
	I_am_joker(l,start-1);
	I_am_joker(start+1,r);
}
*/
