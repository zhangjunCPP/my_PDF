#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],dp[1010][1<<10];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n>>m;
	for(int i=1,k,p;i<=n;i++)
	for(cin>>k;k--;)cin>>p,a[i]|=1<<p-1;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int v=0;v<(1<<m);v++)
	for(int x=a[i];x<(1<<m);x++)
	if(!(v&x))dp[i][x|v]|=dp[i-1][v];
	for(int i=0;i<(1<<m);i++)
	if(dp[n][i]){
		for(int x=m-1;x>=0;x--)putchar('0'+(i>>x&1));
		return 0;
	}
	cout<<-1;
	return 0;
}
