#include<bits/stdc++.h> 
using namespace std;
int n,m,tot,block,now;
int a[500005],lst[500005],ans[500005],vis[500005];
struct Node{int l,r;}q[500005];
void Freopen(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
}
void add(int x){now+=(!vis[a[x]]++);}
void del(int x){now-=(!--vis[a[x]]);}
int main(){
	Freopen();
	scanf("%d%d",&n,&m);
	block=max((int)sqrt(n),1);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		if(!lst[a[i]])ans[n]++;
		else q[++tot]=Node{lst[a[i]]+1,i-1};
		lst[a[i]]=i;
	}
	sort(q+1,q+1+tot,[](const Node &a,const Node &b){return a.l/block==b.l/block?(a.l/block)&1?a.r<b.r:a.r>b.r:a.l<b.l;});
	int l=1,r=0;
	for(int i=1;i<=tot;i++){
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(l<q[i].l)del(l++);
		while(r>q[i].r)del(r--);
		++ans[now];
	}
	for(int i=n;i;i--)ans[i]+=ans[i+1];
	for(int i=1;i<n;i++)printf("%d ",ans[i]);
	printf("%d",ans[n]);
}
/*
4 6
2 1 2 2 1 4

*/
