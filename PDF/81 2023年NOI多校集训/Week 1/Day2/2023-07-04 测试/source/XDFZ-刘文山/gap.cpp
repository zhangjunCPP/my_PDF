#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=2005;
int a[maxn];
int ans=0;
const int mod=998244353;
int v[maxn],b[maxn];
inline void dfs(int now){
	if(now==n+1){
		for(int i=1;i<=n;i++){
			int l=0,r=0,l2=0,r2=0;
			for(int j=i-1;j>=1;j--){
				if(b[j+1]-b[j]==1){
					l++;
				}
				else break;
			}
			for(int j=i+1;j<=n;j++){
				if(b[j]-b[j-1]==1){
					r++;
				}
				else break;
			}
			for(int j=i-1;j>=1;j--){
				if(b[j+1]-b[j]==-1){
					l2++;
				}
				else break;
			}
			for(int j=i+1;j<=n;j++){
				if(b[j]-b[j-1]==-1){
					r2++;
				}
				else break;
			}
			if(max(l+r+1,l2+r2+1)!=a[i]) return ;
		}
		ans++;
		if(ans>mod) ans-=mod;
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			b[now]=i;
			dfs(now+1); 
			v[i]=0;
		}
	}
}
int main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
 
