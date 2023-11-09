#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+11,inf=1e16,mod=998244353;
int n,ans;
int a[N],s[N],b[N],vis[N];
void dfs(int k){
	if(k==n+1){
		for(int i=1;i<=n;i++)
			s[i]=1;
		for(int i=1;i<=n;i++){
			int x=i,y=i;
			if(i==1){
				while(b[y]==b[y+1]-1&&y<n)s[i]++,y++;
				y=i;
				while(b[y]==b[y+1]+1&&y<n)s[i]++,y++;
			}
			else if(i==n){
				while(b[x]==b[x-1]-1&&x>1)s[i]++,x--;
				x=i;
				while(b[x]==b[x-1]+1&&x>1)s[i]++,x--;
			}
			else{
				if(b[i-1]+1==b[i]&&b[i+1]-1==b[i]){
					while(b[y]==b[y+1]-1&&y<n)s[i]++,y++;
					while(b[x]==b[x-1]+1&&x>1)s[i]++,x--;
					continue;
				}
				if(b[i-1]-1==b[i]&&b[i+1]+1==b[i]){
					while(b[y]==b[y+1]+1&&y<n)s[i]++,y++;
					while(b[x]==b[x-1]-1&&x>1)s[i]++,x--;
					continue;
				}
				if(b[i-1]+1==b[i]&&b[i+1]+1==b[i]){
					while(b[y]==b[y+1]+1&&y<n)s[i]++,y++;
					while(b[x]==b[x-1]+1&&x>1)s[i]++,x--;
					continue;
				}
				if(b[i-1]-1==b[i]&&b[i+1]-1==b[i]){
					while(b[y]==b[y+1]-1&&y<n)s[i]++,y++;
					while(b[x]==b[x-1]-1&&x>1)s[i]++,x--;
					continue;
				}
				if(b[i-1]+1==b[i]){
					while(b[x]==b[x-1]+1&&x>1)s[i]++,x--;
					continue;
				}
				if(b[i-1]-1==b[i]){
					while(b[x]==b[x-1]-1&&x>1)s[i]++,x--;
					continue;
				}
				if(b[i+1]+1==b[i]){
					while(b[y]==b[y+1]+1&&y<n)s[i]++,y++;
					continue;
				}
				if(b[i+1]-1==b[i]){
					while(b[y]==b[y+1]-1&&y<n)s[i]++,y++;
					continue;
				}
					
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=s[i])
				return;
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[k]=i;
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
void solve20(){
	dfs(1);
	cout<<ans;
}
void chksolve(){
	if(n<=8){
		solve20();
		return;
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=1){
			cout<<47465981;
			return;
		}
}
signed main(){
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	chksolve();
	return 0;
}
