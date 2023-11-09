#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
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
	return x*f;
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
int n,Q,a[100005],dp[100005],ans[100005],sum,q[100005],cnt[100005],mx;
vector<int> g[100005];
set<int> h[100005],cf;
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		h[a[i]].insert(i);
		mx=max(mx,a[i]);
	}
	for(int i=0;i<=n;i++){
		h[i].insert(n+1);
	}
	Q=read();
	if((double)n*Q*log2(n)<=1e8){
		while(Q--){
			cf.clear(); 
			for(int i=0;i<=n;i++){
				cnt[i]=0;
				cf.insert(i);
			}
			cf.insert(n+1);
			int k=read(),ans=0,sum=0;
			for(int i=n;i>=n-k+1;i--){
				if(!cnt[a[i]])
					cf.erase(a[i]);
				cnt[a[i]]++;
			}
			while(cnt[ans]){
				ans++;
			}
			sum=ans;
			for(int i=n-k;i;i--){
				if(cnt[a[i+k]]==1&&a[i+k]<sum)
					sum=a[i+k];
				if(cnt[a[i+k]]==1)
					cf.insert(a[i+k]);
				cnt[a[i+k]]--;
				if(!cnt[a[i]]&&a[i]==sum)
					sum=(*(cf.upper_bound(sum)));
				if(!cnt[a[i]])
					cf.erase(a[i]);
				cnt[a[i]]++;
				ans=max(ans,sum);
			}
			work(ans);
			putchar('\n');
		} 
		return 0;
	}
	for(int i=1;i<=Q;i++){
		q[read()]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i]=(!a[i]);
		sum=max(sum,dp[i]);
		auto p=h[dp[i]].upper_bound(i);
		if((*p)!=n+1)
			g[(*p)-i+1].emplace_back(i);
	}
	ans[q[1]]=sum;
	for(int i=2;i<=n;i++){
		for(auto j:g[i]){
			int now=dp[j]+1;
			auto p=h[dp[j]].upper_bound(j);
			while(*(p=h[now].upper_bound(j-1))<=j+i-1){
				now++;
			}
			dp[j]=now;
			if((*p)!=n+1)
				g[(*p)-j+1].emplace_back(j);
			sum=max(sum,dp[j]);
		}
		g[i].clear();
		ans[q[i]]=sum;
		if(sum==mx+1){
			for(int j=i+1;j<=n;j++){
				ans[q[j]]=sum;
			}
			break;
		}
	}
	for(int i=1;i<=Q;i++){
		work(ans[i]);
		putchar('\n');
	}
	return 0;
}
