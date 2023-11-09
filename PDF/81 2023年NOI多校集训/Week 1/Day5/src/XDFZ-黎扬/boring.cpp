#include<bits/stdc++.h>
#define ll __int128
using namespace std;
inline ll read(){
	char ch=getchar();
	ll f=1,x=0;
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
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
    putchar(k%10+'0');
}
//__gcd(a,b)%mod
const ll mod=998244353;
int n,q;
ll a[100005];
int main(){
    freopen("boring.in","r",stdin);
    freopen("boring.out","w",stdout);
	n=read();
    q=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    while(q--){
        int k=read();
        ll ans=1;
        for(int i=1,l,r;i<=k;i++){
            l=read();
            r=read();
            ll sum=1;
            for(int j=l;j<=r;j++){
                sum=sum/__gcd(sum,a[j])*a[j];
            }
            ans=ans/__gcd(ans,sum)*sum;
        }
        work(ans%mod);
        putchar('\n');
    }
	return 0;
}