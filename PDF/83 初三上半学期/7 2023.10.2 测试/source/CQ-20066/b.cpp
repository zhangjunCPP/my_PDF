#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
#define int long long
const int N=2005;
int n,a[N];
std::vector<int> st;
int calc(){
	int sum=0,cnt=0;
	for(auto i:st) sum+=i;
	for(auto i:st) if(sum<i*(int)st.size()) cnt++;
	return cnt;
}
int ans;
void dfs(int step){
	if(step>n){
		ans=std::max(ans,calc());
		return ;
	}
	dfs(step+1);
	st.emplace_back(a[step]);
	dfs(step+1);
	st.pop_back();
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	_(n);
	for(int i=1;i<=n;i++) _(a[i]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}

