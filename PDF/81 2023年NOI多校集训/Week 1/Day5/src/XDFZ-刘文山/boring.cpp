#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[2005],shu[2005][2005],c[2005],l[4500],r[4500],b[2005],cnt[2005];
const long long mod=998244353;
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=2;j*j<=a[i];j++){
			while(a[i]%j==0){
				shu[i][j]++;
				a[i]/=j;
				maxx=max(maxx,j);
			}
		}
		if(a[i]!=1) shu[i][a[i]]++;
	 maxx=max(maxx,a[i]);
	}
	while(q--){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>l[i]>>r[i];
			c[l[i]]++; c[r[i]+1]--;
		}
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]+c[i];
			if(b[i]){
				for(int j=1;j<=maxx;j++){
					cnt[j]=max(cnt[j],shu[i][j]);
				}
			}
		}
		for(int i=1;i<=k;i++){
			c[l[i]]--; c[r[i]+1]++;
		}
		long long ans=1ll;
		for(int i=1;i<=maxx;i++){
			if(cnt[i]){
				while(cnt[i]){
					ans=ans*(long long)i%mod;
					cnt[i]--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
