#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
}
const int N=1e5+5;
int n,cnt,sum,ans;
int a[N];
int b[N];
bool vis[N];
inline void dfs(int pos){
	if(pos>n){
		cnt=0;sum=0;
		for(int i=1;i<=n;++i){
			if(vis[i]){
				b[++cnt]=a[i];
				sum+=a[i];
			}
		}
		int tot=0;
		for(int i=1;i<=cnt;++i){
			if(b[i]*cnt>sum)tot++;
		}
		ans=max(ans,tot);
		return;
	}
	vis[pos]=0;
	dfs(pos+1);
	vis[pos]=1;
	dfs(pos+1);
	vis[pos]=0;
}
inline bool check(int mid){
	int tot=mid;int sum=0;int vl;
	for(int i=n;i>=n-mid+1;--i){
		sum+=a[i];
		if(i==n-mid+1)vl=a[i];
	}
	for(int i=1;i<=n-mid;++i){
		sum+=a[i];
		tot++;
		if(vl*tot>sum)return 1;
	}
	return 0;
}
int main(){
	FRE();
	n=rd();
	for(int i=1;i<=n;++i)a[i]=rd();
	if(n<=30){
		dfs(1);
		wr(ans);
	}
	else{
		sort(a+1,a+n+1);
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid)) l=mid;
			else r=mid-1;	
		}
		wr(l);
	}
}
