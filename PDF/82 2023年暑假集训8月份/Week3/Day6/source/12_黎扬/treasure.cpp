#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
int n,val[30],sum[4],vis[30],d[30],ans=1e9,cnt[10000005];
vector<int> q[10000005];
void dfs(int k){
	if(k>n){
		if(ans>max({sum[1],sum[2],sum[3]})-min({sum[1],sum[2],sum[3]})){
			ans=max({sum[1],sum[2],sum[3]})-min({sum[1],sum[2],sum[3]});
			memcpy(d,vis,sizeof(vis));
		}
		return ;
	}
	if(vis[k]){
		dfs(k+1);
		return ;
	}
	for(int i=1;i<=3;i++){
		sum[i]+=val[k];
		vis[k]=i;
		dfs(k+1);
		sum[i]-=val[k];
		vis[k]=0;
	}
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		val[i]=read();
		if(val[i]>=0){
			q[val[i]].emplace_back(i);
			cnt[val[i]]++;
		}
	}
	for(int i=0;i<=1e7;i++){
		int now=0;
		while(cnt[i]>=3){
			vis[q[i][now]]=1;
			vis[q[i][now+1]]=2;
			vis[q[i][now+2]]=3;
			cnt[i]-=3;
			now+=3;
		}
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		work(d[i]);
		putchar(' ');
	}
	return 0;
}
