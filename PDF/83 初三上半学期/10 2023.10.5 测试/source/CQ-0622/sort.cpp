#include<bits/stdc++.h>
using namespace std;
int n,p[700010],ip[700010],root[700010],tot;
struct node{int ls,rs,c;}t[700010*35];
int ins(int u,int l,int r,int p){
	int v=++tot;t[v]=t[u];t[v].c++;
	if(l==r)return v;
	int mid=l+r>>1;
	if(p<=mid)t[v].ls=ins(t[u].ls,l,mid,p);
	else t[v].rs=ins(t[u].rs,mid+1,r,p);
	return v;
}
int kth(int lt,int rt,int l,int r,int k){
	if(l==r)return l;
	int mid=l+r>>1,lc=t[t[rt].ls].c-t[t[lt].ls].c;
	if(k<=lc)return kth(t[lt].ls,t[rt].ls,l,mid,k);
	else return kth(t[lt].rs,t[rt].rs,mid+1,r,k-lc);
}
long long ans=0;
void solve(int l,int r){
	if(l>=r)return;
	ans+=r-l+1;
	int mid=p[kth(root[l-1],root[r],1,n,r-l+2>>1)];
	solve(l,mid-1),solve(mid+1,r);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++)scanf("%d",&p[i]),ip[p[i]]=i;
	for(int i=1;i<=n;i++)root[i]=ins(root[i-1],1,n,ip[i]);
	solve(1,n);cout<<ans;
	return 0;
}
