#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
int n;
int a[23];
int ans,p[23];
void dfs(int x){
	if(x==n+1){
		vector<int> pos;
		int sum=0,cnt=0,po=0;
		for(int i=1;i<=n;i++)if(p[i])pos.push_back(a[i]),sum+=a[i];
		cnt=pos.size();if(!cnt)return;
		for(int i=0;i<cnt;i++)if(pos[i]>sum/1.0/cnt)po++;
		ans=max(ans,po);
		return;
	}
	p[x]=1;dfs(x+1);
	p[x]=0;dfs(x+1);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.ans","w",stdout);
	n=rd();for(int i=1;i<=n;i++)a[i]=rd();
	dfs(1);
	cout<<ans;
	return 0;
}

