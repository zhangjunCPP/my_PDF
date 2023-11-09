#include<bits/stdc++.h>
using namespace std;
int n,m,tot,lg[3001],a[500001],c[500001],dp[500001];
vector <int> G[500001];
bitset <3001> st[3001][21];
bitset <3001> query(int l,int r){
	if(l>r||r>n) return 0;
	int k=lg[r-l+1];
	return st[l][k]|st[r-(1<<k)+1][k];
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;i++) a[i]=c[i]=read();
	sort(c+1,c+1+n);
	m=unique(c+1,c+1+n)-c-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(c+1,c+1+m,a[i])-c;
	for(int i=1;i<=n;i++) G[a[i]].push_back(i);
	for(int i=1;i<=n;i++) st[i][0][a[i]]=1;
	for(int i=2;i<=3000;i++) lg[i]=lg[i>>1]+1;
	for(int k=1;k<=lg[n];k++){
		for(int i=1;i+(1<<k)-1<=n;i++) st[i][k]=st[i][k-1]|st[i+(1<<(k-1))][k-1];
	}
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
		for(int j=0;j<G[a[i]].size();j++){
			if(G[a[i]][j]<=i) continue;
			int l=G[a[i]][j]+1,r=n+1;
			while(l<r){
				int mid=(l+r)>>1;
				if((query(i+1,G[a[i]][j]-1)&query(G[a[i]][j]+1,mid)).any()) r=mid;
				else l=mid+1;
			}
			if(l!=n+1) dp[l]=max(dp[l],dp[i]+1);
		}
	}
	printf("%lld",4ll*dp[n]);
	return 0;
}
