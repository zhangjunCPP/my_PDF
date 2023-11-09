#include<bits/stdc++.h>
using namespace std;
int p[501],cnt,n,m,f,c;
void dfs(int step,int sum){
	if(f)return;
	if(sum+(n+step-1)*(n-step)/2<m)return;
	c++;
	if(c>=28000000){
		f=-1;
		puts("0");
		return;
	}
	if(step==n){
		if(sum==m){
			f=1;
		}
		return;
	}
	if(sum>m)return;
	for(int i=1;i<=cnt;i++){
		p[i]++;
		dfs(step+1,sum+step-p[i]+1);
		if(f)return;
		p[i]--;
	}
	p[++cnt]=1;
	dfs(step+1,sum+step);
	p[cnt--]=0;
}
void solve(){
	scanf("%d%d",&n,&m);
	c=0;
	if(m==0)return void(puts("1"));
	if(m<n-1)return (void)puts("0");
	if(n*(n-1)/2<m)return (void)puts("0");
	cnt=f=0;
	for(int i=1;i<=n;i++)p[i]=0;
	dfs(0,0);
	if(f==1)puts("1");
	if(f==0) puts("0");
	return;
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int Q;
	scanf("%d",&Q);
	while(Q--)solve();
	return 0;
}

