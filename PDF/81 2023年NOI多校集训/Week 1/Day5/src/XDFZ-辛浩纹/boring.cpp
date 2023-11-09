#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
inline int read(){
    char ch=getchar();int sum=0,f=1;
    while(!isdigit(ch))f=(ch=='-')?-1:1,ch=getchar();
    while(isdigit(ch))sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();
    return sum*f;
}
const int mod=998244353;
int n,q,a[100004];
int slow__(int x,int y){
	int res=0;
	for(;y;y>>=1,x=x*2%mod)if(y&1)res=(res+x)%mod;
	return res;
}
int fast_pow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=slow__(x,x)%mod)if(y&1)res=slow__(res,x)%mod;
	return res;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int LCM(int x,int y){
	return slow__(slow__(x,y),fast_pow(gcd(x,y),mod-2));
}
struct ST{
 	int lcm[100004][20],log[100004];
    ST(){}
    void build(int *a,int n){
        log[0]=-1;
        for(int i=1;i<=n;++i)lcm[i][0]=a[i],log[i]=log[i/2]+1;
        for(int j=1;j<=log[n];++j)
            for(int i=1;i+(1<<j)-1<=n;++i)
            	lcm[i][j]=LCM(lcm[i][j-1],lcm[i+(1<<(j-1))][j-1]);
    }
    int ask(int l,int r){
        int p=log[r-l+1];
        return LCM(lcm[l][p],lcm[r-(1<<p)+1][p]);
    }
}f;
signed main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	f.build(a,n);
	while(q--){
		int k=read(),ans=1;
		for(int i=1;i<=k;++i){
			int xx=read(),yy=read();
			ans=LCM(ans,f.ask(xx,yy));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

