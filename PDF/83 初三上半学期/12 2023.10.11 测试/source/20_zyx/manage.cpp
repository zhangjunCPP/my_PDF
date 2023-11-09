#include<bits/stdc++.h>
using namespace std;
int n,m,l=1,r,tot,sum,b,a[500001],cnt[500001],ans[500001],id[500001];
vector <int> G[500001];
struct node{
	int l,r,d;
	node(int l=0,int r=0,int d=0):l(l),r(r),d(d){}
	bool operator<(const node &k)const{
		if(l/b==k.l/b){
			if((l/b)&1) return r<k.r;
			else return r>k.r;
		}
		else return l<k.l;
	}
}q[500001];
struct tree{
	int t[500001];
	void add(int x,int v){
		for(int i=x;i<=n;i+=i&-i) t[i]+=v;
	}
	int ask(int x){
		int res=0;
		for(int i=x;i>=1;i-=i&-i) res+=t[i];
		return res;
	}
}t;
void add(int x){
	if(!cnt[x]) sum++;
	cnt[x]++;
}
void del(int x){
	cnt[x]--;
	if(!cnt[x]) sum--;
}
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout); 
	
	scanf("%d%d",&n,&m),b=sqrt(m);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]),G[a[i]].push_back(i);
	for(int i=1;i<=n;i++) for(int j=1;j<G[i].size();j++) if(G[i][j-1]+1<G[i][j]) id[G[i][j]]=++tot,q[tot]=node(G[i][j-1]+1,G[i][j]-1,tot);
	sort(q+1,q+1+tot);
	for(int i=1;i<=tot;i++){
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		ans[q[i].d]=sum;
	}
	for(int i=1;i<=n;i++){
		if(G[i].size()) t.add(1,1);
		for(int j=1;j<G[i].size();j++) if(G[i][j-1]+1<G[i][j]) t.add(1,1),t.add(ans[id[G[i][j]]]+1,-1);
	}
	for(int i=1;i<=n;i++) printf("%d ",t.ask(i));
	return 0;
}
