#include<bits/stdc++.h>
using namespace std;
int n,tot,a[500001],lg[500001],dp[500001],fr[500001],ans[500001],cnt[21],lst[500001][21];
bitset <25> s,st[500001][21];
int get(int l,int r){
	int k=lg[r-l+1];
	s=st[l][k]|st[r-(1<<k)+1][k];
	for(int i=0;i<=21;i++) if(!s[i]) return i;
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=0;i<=20;i++) cnt[i]=1;
	for(int i=1;i<=n;i++){
		cnt[a[i]=read()]=i;
		for(int j=0;j<=20;j++) lst[i][j]=cnt[j];
	}
	for(int i=2;i<=500000;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) st[i][0][a[i]]=1;
	for(int k=1;k<=lg[n];k++) for(int i=1;i+(1<<k)-1<=n;i++) st[i][k]=st[i][k-1]|st[i+(1<<(k-1))][k-1];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=20;j++){
			int val=get(lst[i][j],i);
			if(dp[i]<dp[lst[i][j]-1]+val){
				dp[i]=dp[lst[i][j]-1]+val;
				fr[i]=lst[i][j]-1;
			}
		}
	}
	int now=n;
	while(now) now=fr[now],ans[++tot]=now+1;
	printf("%d %d\n",dp[n],tot);
	for(int i=tot;i>=1;i--) printf("%d ",ans[i]);
	return 0;
}
