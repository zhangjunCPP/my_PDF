#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; char ch=getchar(); bool f=0;
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=5e5+5;
int n,m,a[N];
struct node{
	int vl,tm;
	node(int _vl=0,int _tm=0):vl(_vl),tm(_tm){}
	friend bool operator < (node a,node b){
		if(a.tm==b.tm) return a.vl<b.vl;
		return a.tm<b.tm;
	}
};
set<node> st;
int tim[N];
int ans[N];
signed main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	_(n),_(m);
	for(int i=1;i<=m;i++) _(a[i]);
	for(int k=1;k<=n;k++){
		memset(tim+1,0,sizeof(int)*n);
		st.clear();
		int tm=0;
		for(int i=1;i<=m;i++){
			if(tim[a[i]]){
				auto x=*st.lower_bound(node(a[i],tim[a[i]]));
				st.erase(x);
				x.tm=tim[a[i]]=++tm;
				st.insert(x);
			}else{
				if((int)st.size()==k){
					tim[st.begin()->vl]=0;
					st.erase(st.begin());
				}
				tim[a[i]]=++tm;
				st.insert(node(a[i],tm));
				ans[k]++;
			}
		}
	}
	for(int k=1;k<n;k++) printf("%d ",ans[k]);
	printf("%d",ans[n]);
	return 0;
}
