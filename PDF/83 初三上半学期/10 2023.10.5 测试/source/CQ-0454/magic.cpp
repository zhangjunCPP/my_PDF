#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=1e3+5;
int n;
struct point{
	int u,out,in;
	friend bool operator < (point a,point b){
		if(a.out-a.in==b.out-b.in) return a.u>b.u;
		return a.out-a.in>b.out-b.in;
	}
};
set<point> st;
int a[N],b[N],c[N];
vector<int> e[N],g[N];
int ans;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	_(n);
	for(int i=1;i<=n;i++){
		int l,r; _(l),_(r),_(c[i]);
		for(int j=l;j<=r;j++){
			if(i==j) continue;
			e[i].emplace_back(j);
			g[j].emplace_back(i);
			a[i]+=c[i];
			b[j]+=c[i];
		}
	}
	for(int i=1;i<=n;i++) st.emplace((point){i,a[i],b[i]});
	while(!st.empty()){
		auto u=*st.begin();
		st.erase(u);
		ans+=u.out;
		for(auto i:e[u.u]){
			auto v=st.lower_bound((point){i,a[i],b[i]});
			if(i!=v->u||a[i]!=v->out||b[i]!=v->in) continue;
			st.erase(v);
			auto j=*v;
			b[i]-=c[u.u];
			j.in-=c[u.u];
			st.emplace(j);
		}
		for(auto i:g[u.u]){
			auto v=st.lower_bound((point){i,a[i],b[i]});
			if(i!=v->u||a[i]!=v->out||b[i]!=v->in) continue;
			st.erase(v);
			auto j=*v;
			a[i]-=c[i];
			j.out-=c[i];
			st.emplace(j);
		}
	}
	printf("%d",ans);
	return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/
