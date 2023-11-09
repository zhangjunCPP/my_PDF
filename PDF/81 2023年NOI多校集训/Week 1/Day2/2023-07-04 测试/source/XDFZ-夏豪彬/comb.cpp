#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
const int maxn=5e5+5;
int n,sum,ans;
int a[maxn],now[maxn];
bool vis[maxn];
inline int Get(int val){
	int sum=0;
	for(int i=0;i<n;++i)if((val>>i)&1)sum++;
	return sum;
}
inline bool check(int val){
	if(Get(val)%4!=0)return 0;
	int cnt=0;
	for(int i=0;i<n;++i){
		if((val>>i)&1)now[++cnt]=a[i+1];
	}
	for(int i=0;i<cnt/4;++i)if(now[4*i+1]!=now[4*i+3]||now[4*i+2]!=now[4*i+4])return 0;
	return 1;
}
inline void solve(){
	for(int i=1;i<=(1<<n)-1;++i){
		if(check(i)){
			ans=max(Get(i),ans);
		}
	}
}
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	solve();
	printf("%d",ans);
}
