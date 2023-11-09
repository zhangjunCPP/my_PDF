#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; char ch=getchar(); bool f=0;
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
using ll=long long;
const int N=2e5+5;
int id,op,n,p[N],q;
void kb(int &l,int &r,int &k,ll lstans,int testop){
	lstans%=19260817;
	if(testop){
		l^=lstans; l=(l%n+n)%n+1;
		r^=lstans; r=(r%n+n)%n+1;
		if(l>r) swap(l,r);
		k^=lstans;
		k=(k%min(r-l+1,100))+1; 
	}
}
struct node{
	int to;
	ll val;
	node(int _to=0,ll _val=0):to(_to),val(_val){}
};
vector<node> e[N];
namespace sub1{//n<=8
	vector<int> st,now;
	int kk;
	ll ans;
	bool tag[N];
	ll calc(){
		ll res1=0,res2=0;
		for(int i=1;i<=n;i++) tag[i]=0;
		for(auto u:now) tag[u]=1;
		for(auto u:now){
			for(auto i:e[u]){
				int v=i.to; ll w=i.val;
				if(tag[v]) res1+=w;
				else res2+=w;
			}
		}
		return res1/2ll/*+res2*/;
	}
	void dfs(int step){
		if((int)now.size()==kk){
//			for(auto u:now) printf("%d ",u);
//			puts("");
			ans=max(ans,calc());
			return ;
		}
		if(step>(int)st.size()) return ;
		dfs(step+1);
		now.push_back(st[step-1]);
		dfs(step+1);
		now.pop_back();
	}
	ll work(int l,int r,int k){
		ans=0;
		now.clear();
		st.clear();
		for(int i=l;i<=r;i++) st.push_back(p[i]);
		kk=k;
		dfs(1);
		return ans;
	}
}
signed main(){
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout);
	_(id),_(op),_(n);
	for(int i=1;i<n;i++){
		int u,v; ll w; _(u),_(v),_(w);
		e[u].push_back(node(v,w));
		e[v].push_back(node(u,w));
	}
	for(int i=1;i<=n;i++) _(p[i]);
	_(q);
	ll lstans=0;
	while(q--){
		int l,r,k; _(l),_(r),_(k); kb(l,r,k,lstans,op);
//		if(id<=2){
			lstans=sub1::work(l,r,k);
			printf("%lld\n",lstans);
//		}
		
	}
	
	return 0;
}
/*
0
0 8
2 1 168841147
3 2 185715402
4 3 225620062
5 2 229186192
6 1 56387677
7 1 912381225
8 6 897978762
6 8 4 1 3 2 5 7
10
1 4 1
3 8 4
1 3 2
2 8 3
3 4 1
1 5 5
1 6 1
3 7 2
3 6 4
1 4 3
*/
