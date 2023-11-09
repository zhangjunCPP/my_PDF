#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
const int INF=0x3f3f3f3f;
int t,n; 
vector<int>p;
int mu[maxn],prime[maxn],tot,vis[maxn],out[maxn];
void init(int mx){
	mu[1]=1;
	for(int i=2;i<=mx;i++){
		if(!vis[i])prime[++tot]=i,mu[i]=-1;
		vis[i]=1;
		for(int j=1;j<=tot&&i*prime[j]<=mx;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=mu[i]*mu[prime[j]];
		}
	}
}
int solve(int x){
	int sum=0;
	if(x==1)return 1;
	for(int i=1;i<=x;i++){
		int val=0;
//		int pos=x/i;
//		for(int l=1,r;l<=pos;l=r+1){
//			r=pos/(pos/l);
//			int v=(pos/l)*(pos/l)*(l+r)*(r-l+1)/2;
//			val+=v;
//		}
		for(int j=1;j*i<=x;j++){
			val=(val+j*(x/(i*j))*(x/(i*j)));
		}
		sum=sum+val*mu[i];
	}
	return sum;
}
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	int sum=0,mmx=0;
	while(t--){
		int x;cin>>x;
		sum+=x;mmx=max(mmx,x);
		p.push_back(x);
	}
	if(sum<=10000){
		for(auto k:p){
			int ans=0;
			for(int i=1;i<=k;i++){
				for(int j=1;j<=k;j++)ans+=__gcd(i,j);
			}
			cout<<ans*2-k*k<<"\n";
		}
	}
	else{
		init(1e6);
		for(auto k:p){
			if(!out[k])out[k]=solve(k);
			cout<<out[k]*2-k*k<<"\n";
		}
	}
	return 0;
}

