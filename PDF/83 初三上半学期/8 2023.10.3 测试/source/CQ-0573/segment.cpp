#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=2e5+5;using ll=long long;
int n,a[N],ans=2e9;
struct node{
	int id,mn,mx;
	bool operator<(const node&b){
		return id==b.id?(mn==b.mn?mx<b.mx:mn<b.mx):id<b.id;
	}
};
map<node,int> mp;
void dfs(int x,int mn,int mx){
//	if(mp.count({x,mn,mx}))return mp[];
	if(x==n+1){
		ans=min(ans,mx-mn);
		return;
	}
	if(x==n){
		dfs(x+1,min(mn,a[x]),max(mx,a[x]));
		return;
	}
	dfs(x+1,min(mn,a[x]),max(mx,a[x]));
	dfs(x+2,min(mn,a[x]+a[x+1]),max(mx,a[x]+a[x+1]));
}
/*int dfs1(int x,int mn,int mx){
	node k={x,mn,mx};
	if(mp.count(k))return mp[k];
	if(x==n+1){
		return mx-mn;
	}
	if(x==n){
		if(!mp.count(k))
		mp[k]=dfs1(x+1,min(mn,a[x]),max(mx,a[x]));
		else
		mp[k]=min(dfs1(x+1,min(mn,a[x]),max(mx,a[x])),mp[k]);
		return mp[k];
	}
	if(!mp.count(k))
	mp[k]=min(dfs1(x+1,min(mn,a[x]),max(mx,a[x])),dfs1(x+2,min(mn,a[x]+a[x+1]),max(mx,a[x]+a[x+1])));
	else
	mp[k]=min({mp[k],
	dfs1(x+1,min(mn,a[x]),max(mx,a[x])),dfs1(x+2,min(mn,a[x]+a[x+1]),max(mx,a[x]+a[x+1]))
	});
	return mp[k];
}*/
int c[N],pos[N],la;
int dp[N][2],f; 
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)a[i]=rd(),f&=(a[i]<=10),la=max(la,a[i]);
	if(n<=18){
		dfs(1,2e9,0);
		printf("%d",ans);
		return 0;
	}if(f){
//		for(int mn=1;mn<=20;mn++){
//			vector<int> nd;
////			for(int i=1;i<n;i++)
////			if(a[i]<mn)nd.push_back(i);
//			for(int i=2;i<=n;i++){
//				if(a[i]<mn){
//					dp[i][0]=max(dp[i-1][0],a[i-1]+a[i]);
//				}
//			}
//			
//		}
		for(int i=n;i;i--)dfs(i,2e9,0);
		
	} 
	srand(time(0));
	double T=0.98,eps=1e-15,now=1;
	int mx=0,mn=1e9,aa;
	for(int i=1;i<=n;i++)mn=min(a[i],mn),mx=max(a[i],mx);
	ans=aa=mx-mn;
	while(now>eps){
//		int tmp=now*n/2;
		aa=min(aa,ans);
		for(int i=2;i<=n;i++){
			pos[i]=c[i]^(rand()/1.0/RAND_MAX*now*pow(1.0/a[i],11)*1/eps>1);
			if(pos[i-1])pos[i]=0;
		}
		mx=0,mn=1e9;
		for(int i=1;i<=n;i++)if(c[i+1])mx=max(a[i]+a[i+1],mx),mn=min(mn,a[i]+a[i+1]),i++;
		else mx=max(a[i],mx),mn=min(mn,a[i]);
		if(mx-mn<ans){
			ans=mx-mn;
			for(int i=1;i<=n;i++)c[i]=pos[i];
		}else{
			int der=mx-mn-ans;
			double d=der/1.0/1e8;
			if(d<rand()/1.0/RAND_MAX){
				ans=mx-mn;
				for(int i=1;i<=n;i++)c[i]=pos[i];
			}
		}now*=T;
//		for(int i=1;i<=n;i++)cout<<c[i];
//		cout<<endl;
	}cout<<aa<<endl;
	return 0;
}

