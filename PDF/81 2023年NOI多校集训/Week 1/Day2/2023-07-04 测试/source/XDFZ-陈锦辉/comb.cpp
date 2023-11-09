//the code is from chenjh
#include<cstdio>
#include<algorithm>
#include<vector>
#define MAXN 500005
int n;
int a[MAXN];
int ans=0;
void dfs(int pos,std::vector<int>&v){
	if(pos>n){
		if(!v.empty() && !(v.size()&3)){
			int size=v.size();
			for(int i=0;i<size;i++)if(v[i]!=v[i|2] || v[i|1]!=v[i|3])return;
			ans=std::max(ans,size);
		}
		return;
	}
	dfs(pos+1,v);
	v.push_back(a[pos]);
	dfs(pos+1,v);
	v.pop_back();
}
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::vector<int> v;
	dfs(1,v);
	printf("%d\n",ans);
	return 0;
}

