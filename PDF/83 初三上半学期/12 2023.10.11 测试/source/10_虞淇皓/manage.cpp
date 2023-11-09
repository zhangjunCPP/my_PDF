/*
我们从小到大枚举k，当前我们已经维护出了k-1时的操作序列 
我们发现当k增加1时，原来的一些删除操作就可以不用做
比如说a=1 2 4 3 2 3 4 1 5 2,k=1
然后操作序列为:(add x y表示在x位置插入y元素,del x y表示在x位置删除y元素) 
add 1 1 	1 
del 1 1 add 1 2  	2 
del 1 2 add 1 4		4 
……
k=2:
add 1 1		1 0 
add 2 2		1 2 
del 1 1 add 1 4		2 4 
del 2 2 add 2 3		4 3 
ael 1 4 add 1 2

我们发现减少了3 2 3中后一个3的插入操作 
我们发现i点时的序列，一定是由从i往前k个不同的数组成的 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],vis[N],q[N];  
pair<int,int> tr[N*4];
#define ls k<<1,l,mid
#define rs k<<1|1,mid+1,r
void build(int k,int l,int r){
	tr[k]={1e9,0};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(ls);build(rs);
}
void ddxg(int k,int l,int r,int x,int y){
	if(l==r){
		tr[k].first=x;tr[k].second=l;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)ddxg(ls,x,y);
	else ddxg(rs,x,y);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
	if(tr[k<<1].first<tr[k<<1|1].first)tr[k]=tr[k<<1];
	else tr[k]=tr[k<<1|1];
}
pair<int,int> qjcx(int k,int l,int r,int x,int y){
	if(l>=x&&r<=y){return tr[k];}
	int mid=(l+r)>>1;
	pair<int,int>ans={1e9,0};
	if(x<=mid){
		pair<int,int>z=qjcx(ls,x,y);
		if(z.first<ans.first){
			ans=z;
		}
	}
	if(y>mid){
		pair<int,int>z=qjcx(rs,x,y);
		if(z.first<ans.first){
			ans=z;
		}
	}
	return ans;
}
int get(int k){
	int ans=0;
	for(int i=1;i<=n;i++)vis[i]=0,q[i]=0;
	build(1,1,k);
	int tt=0;
	for(int i=1;i<=m;i++){
		int x=a[i];
//		cout<<x<<" "<<vis[x]<<"    ";
		if(vis[x]){
			ddxg(1,1,k,vis[x],i);
		}
		else{
			if(tt<k){
				tt++;
				ddxg(1,1,k,tt,i);
				ans++;
				q[tt]=x;
				vis[x]=tt;
//			cout<<i<<" "<<tt<<" "<<x<<"   ";
				continue;
			}
			pair<int,int>y=qjcx(1,1,k,1,k);
			vis[q[y.second]]=0;
			q[y.second]=x;
			vis[x]=y.second;
			ddxg(1,1,k,vis[x],i);
			ans++;
//			cout<<i<<" "<<y.second<<" "<<x<<"   ";
		}
	}
//	cout<<endl;
	return ans;
}
int c[N];
int get2(int k){
	int ans=0;
	for(int i=1;i<=n;i++)vis[i]=0,q[i]=0,c[i]=0;
	int tt=0;
	for(int i=1;i<=m;i++){
		int x=a[i];
		if(vis[x]){
			c[x]=i;
		}
		else{
			if(tt<k){
				tt++;
				q[tt]=x;
				vis[x]=tt;
				ans++;
				c[x]=i;
				continue;
			}
			int y=1;
			for(int j=1;j<=k;j++){
				if(c[q[j]]<c[q[y]])y=j;
			}
			vis[q[y]]=0;
			q[y]=x;
			vis[x]=y;
			ans++;
		}
		c[x]=i;
	}
	return ans;
}
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		int x;
		if(n<=500)x=get2(k);
		else x=get(k);
		printf("%d\n",x);
	}
	return 0;
}
