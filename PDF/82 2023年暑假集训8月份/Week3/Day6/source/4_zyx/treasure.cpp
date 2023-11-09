#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll c1,c2,a,b,c,f;
	node(ll k1=0,ll k2=0,ll k3=0,ll k4=0,ll k5=0,ll k6=0){c1=k1,c2=k2,a=k3,b=k4,c=k5,f=k6;}
	bool operator<(const node &k)const{
		if(c1!=k.c1) return c1<k.c1;
		else return c2<k.c2;
	}
}a1[1594324],a2[1594324];
int n,t1,t2,id,len,a[26],w[26];
ll ans1,ans2,ans=1e16,sum;
void dfs1(int pos,ll sa,ll sb,ll sc,ll s){
	if(pos==(n+1)/2+1){
		a1[++t1]=node(0,0,sa,sb,sc,s);
		return;
	}
	dfs1(pos+1,sa+a[pos],sb,sc,s*3);
	dfs1(pos+1,sa,sb+a[pos],sc,s*3+1);
	dfs1(pos+1,sa,sb,sc+a[pos],s*3+2);
}
void dfs2(int pos,ll sa,ll sb,ll sc,ll s){
	if(pos==n+1){
		a2[++t2]=node(0,0,sa,sb,sc,s);
		return;
	}
	dfs2(pos+1,sa+a[pos],sb,sc,s*3);
	dfs2(pos+1,sa,sb+a[pos],sc,s*3+1);
	dfs2(pos+1,sa,sb,sc+a[pos],s*3+2);
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	sum/=3ll;
	dfs1(1,0,0,0,0);
	dfs2((n+1)/2+1,0,0,0,0);
	for(int i=1;i<=t1;i++) a1[i].c1=a1[i].a-a1[i].b,a1[i].c2=a1[i].c;
	sort(a1+1,a1+1+t1);
	for(int i=1;i<=t2;i++){
		id=lower_bound(a1+1,a1+1+t1,node(a2[i].b-a2[i].a,sum-a2[i].c))-a1;
		for(int j=max(1,id-10);j<=min(t1,id+10);j++){
			ll sa=a1[j].a+a2[i].a,sb=a1[j].b+a2[i].b,sc=a1[j].c+a2[i].c;
			if(max({sa,sb,sc})-min({sa,sb,sc})<ans) ans=max({sa,sb,sc})-min({sa,sb,sc}),ans1=a1[j].f,ans2=a2[i].f;
		}
		id=upper_bound(a1+1,a1+1+t1,node(a2[i].b-a2[i].a,sum-a2[i].c))-a1;
		for(int j=max(1,id-10);j<=min(t1,id+10);j++){
			ll sa=a1[j].a+a2[i].a,sb=a1[j].b+a2[i].b,sc=a1[j].c+a2[i].c;
			if(max({sa,sb,sc})-min({sa,sb,sc})<ans) ans=max({sa,sb,sc})-min({sa,sb,sc}),ans1=a1[j].f,ans2=a2[i].f;
		}
	}
	for(int i=1;i<=t1;i++) a1[i].c1=a1[i].a-a1[i].c,a1[i].c2=a1[i].b;
	sort(a1+1,a1+1+t1);
	for(int i=1;i<=t2;i++){
		id=lower_bound(a1+1,a1+1+t1,node(a2[i].c-a2[i].a,sum-a2[i].b))-a1;
		for(int j=max(1,id-10);j<=min(t1,id+10);j++){
			ll sa=a1[j].a+a2[i].a,sb=a1[j].b+a2[i].b,sc=a1[j].c+a2[i].c;
			if(max({sa,sb,sc})-min({sa,sb,sc})<ans) ans=max({sa,sb,sc})-min({sa,sb,sc}),ans1=a1[j].f,ans2=a2[i].f;
		}
		id=upper_bound(a1+1,a1+1+t1,node(a2[i].c-a2[i].a,sum-a2[i].b))-a1;
		for(int j=max(1,id-10);j<=min(t1,id+10);j++){
			ll sa=a1[j].a+a2[i].a,sb=a1[j].b+a2[i].b,sc=a1[j].c+a2[i].c;
			if(max({sa,sb,sc})-min({sa,sb,sc})<ans) ans=max({sa,sb,sc})-min({sa,sb,sc}),ans1=a1[j].f,ans2=a2[i].f;
		}
	}
	for(int i=1;i<=t1;i++) a1[i].c1=a1[i].b-a1[i].c,a1[i].c2=a1[i].a;
	sort(a1+1,a1+1+t1);
	for(int i=1;i<=t2;i++){
		id=lower_bound(a1+1,a1+1+t1,node(a2[i].c-a2[i].b,sum-a2[i].a))-a1;
		for(int j=max(1,id-10);j<=min(t1,id+10);j++){
			ll sa=a1[j].a+a2[i].a,sb=a1[j].b+a2[i].b,sc=a1[j].c+a2[i].c;
			if(max({sa,sb,sc})-min({sa,sb,sc})<ans) ans=max({sa,sb,sc})-min({sa,sb,sc}),ans1=a1[j].f,ans2=a2[i].f;
		}
		id=upper_bound(a1+1,a1+1+t1,node(a2[i].c-a2[i].b,sum-a2[i].a))-a1;
		for(int j=max(1,id-10);j<=min(t1,id+10);j++){
			ll sa=a1[j].a+a2[i].a,sb=a1[j].b+a2[i].b,sc=a1[j].c+a2[i].c;
			if(max({sa,sb,sc})-min({sa,sb,sc})<ans) ans=max({sa,sb,sc})-min({sa,sb,sc}),ans1=a1[j].f,ans2=a2[i].f;
		}
	}
	for(int i=1;i<=(n+1)/2;i++) w[++len]=ans1%3+1,ans1/=3;
	for(int i=len;i>=1;i--) printf("%d ",w[i]);
	len=0;
	for(int i=(n+1)/2+1;i<=n;i++) w[++len]=ans2%3+1,ans2/=3;
	for(int i=len;i>=1;i--) printf("%d ",w[i]);
	return 0;
}
