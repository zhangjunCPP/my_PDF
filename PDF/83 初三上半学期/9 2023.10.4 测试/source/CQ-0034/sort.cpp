#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e6+10;
using namespace std;

ll n,m;
ll a[N];

ll A[100]={0, 0,0,0,2,30,326,3234,31762,321294,3422702,38879082,473708154};

void mian(){
	
	scanf("%lld",&n);
	scanf("%lld",&m);
	printf("%lld\n",a[n]%m);
	
}

int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)mian();
	return 0;
}
