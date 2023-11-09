#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,mod=998244353,M=2e4+10;
struct node{
	int l,r,op;
}q[N];
int a[N];
int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y);
}
ll an[20][20];
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=17){
		while(m--){
			int l,r;scanf("%d%d",&l,&r);
			if(!an[l][r]){
				int len=r-l+1;ll ans=1;
				for(int s=0;s<(1<<len);s++){
					int sum=0;
					for(int i=l;i<=r;i++)if(s&(1<<(i-l))){
						if(!sum)sum=a[i];
						else sum=gcd(sum,a[i]);
					}
					if(sum)ans=ans*sum%mod;
				}
				an[l][r]=ans;
			}
			printf("%lld\n",an[l][r]);
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].op=i;
	}
	
	return 0;
}
