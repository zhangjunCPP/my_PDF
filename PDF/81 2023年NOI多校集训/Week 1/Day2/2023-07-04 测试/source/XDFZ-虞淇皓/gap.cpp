#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353,N=2010;
int n,a[N],l[N],r[N],tot,ans,vis[N];
int st[N],ed[N];
void dfs(int k){
	if(k>tot){
		ans=(ans+1)%mod;
//		for(int i=1;i<=tot;i++){
//			cout<<st[i]<<' '<<ed[i]<<"    ";
//		}
//		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(k>1&&st[k-1]<=ed[k-1]&&i==ed[k-1]+1)continue;
		if(k>1&&st[k-1]>=ed[k-1]&&i==ed[k-1]-1)continue;
		if(i+(r[k]-l[k])<=n){
			int fl=0;
			for(int j=i;j<=i+r[k]-l[k];j++){
				if(vis[j]){
					fl=1;
					break;
				}
			}
			if(fl)continue;
			st[k]=i,ed[k]=i+r[k]-l[k];
			for(int j=i;j<=i+r[k]-l[k];j++){
				vis[j]=1;
			}
			dfs(k+1);
			st[k]=ed[k]=0;
			for(int j=i;j<=i+r[k]-l[k];j++){
				vis[j]=0;
			}
		}
		if(i-(r[k]-l[k])>=1&&l[k]!=r[k]){
			int fl=0;
			for(int j=i-r[k]+l[k];j<=i;j++){
				if(vis[j]){
					fl=1;
					break;
				}
			}
			if(fl)continue;
			st[k]=i,ed[k]=i-(r[k]-l[k]);
			for(int j=i-(r[k]-l[k]);j<=i;j++){
				vis[j]=1;
			}
			dfs(k+1);
			st[k]=ed[k]=0;
			for(int j=i-(r[k]-l[k]);j<=i;j++){
				vis[j]=0;
			}
		}
	}
}
signed main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		l[++tot]=i;
		r[tot]=i+a[i]-1;
		i=r[tot];
	}
	dfs(1);
	cout<<ans%mod;
	return 0;
}
