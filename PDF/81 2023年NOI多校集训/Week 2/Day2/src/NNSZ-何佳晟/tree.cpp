#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000005,INF=0x3f3f3f3f,mod=1e9+7;
int _;
int n;
int c[maxn];
vector<int>g[maxn];


int main(){
    ios::sync_with_stdio(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
	bool f1=1,f2=1;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y); 
		g[y].push_back(x); 
		if(!(x==1 or y==1))f1=0;
		if(!((x==i and y==i+1) or (y==i and x==i+1)))f2=0;
	}
	
	if(n==2){
		cout<<2<<endl;
		return 0;
	}
	if(n==3){
		cout<<12<<endl;
		return 0;
	}
	
	if(f1){
		if(n==4){
			cout<<28<<endl;
			return 0;
		}
		cout<<"!"<<endl; 
		c[0]=1;
		ll sum=2;
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]*(n-i+1)/i;
			cout<<i<<" "<<c[i]<<endl;
		}
		if(n&1){
			(sum+=2*n)%mod;
			(sum+=(n-1+2*(c[2]-n+1)%mod)%mod)%=mod;
			for(int i=3;i<=n/2;i++){
				(sum+=4*c[i]%mod)%=mod;
			}
			sum<<=1;
		}
		else {
			(sum+=2*n)%mod;
			(sum+=(n-1+2*(c[2]-n+1)%mod)%mod)%=mod;
			for(int i=3;i<n/2;i++){
				(sum+=4*c[i]%mod)%=mod;
			}
			sum<<=1;
			(sum+=4*c[n/2]%mod)%=mod;
		}
		cout<<sum<<endl;
	}
	else if(f2){
		
	}
	

    return 0;
}

