#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
int a[N],dp[N],pos[N];
int v[21];
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[1]=(a[1]==0);
	v[a[1]]=1;
	for(int i=2;i<=n;i++){
		int vis[21]={0},p=0;
		vis[a[i]]=v[a[i]]=1;
		for(int j=i-1;j>=max(0,i-1000);j--){
			while(vis[p])p++;
			if(dp[i]<dp[j]+p){
				dp[i]=dp[j]+p;
				pos[i]=j;
			}
			vis[a[j]]=1;
		}
		p=0;
		while(v[p])p++;
		if(p>dp[i]){
			dp[i]=p;
			pos[i]=0;
		}
	}
	int now=n;
	stack<int> s;
	while(now!=0)now=pos[now],s.push(now);
	printf("%d %d\n",dp[n],s.size());
	for(;s.size();)printf("%d ",s.top()+1),s.pop();
	return 0;
}
