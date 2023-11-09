#include<bits/stdc++.h>
#define ll long long
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
//分两种情况p[1]=1和p[1]!=1计算
//p[1]!=1时可以有p[1]<Q(p)[1],但是同样可以p[1]=Q(p)[1],这时是两个数的位置交换的时候,相当于dp[i-2]的情况
//时间复杂度O(n^2),这样我们就拿到了70分
//考虑优化sum((i-k))*jc[i-2],做一个等差数列即可
//时间复杂度O(n)
ll n,mod,ans,dp[10000005],jc[10000005];
int main(){
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
	n=read();
    mod=read();
    dp[3]=1;
    jc[0]=1;
    for(ll i=1;i<=n;i++){
        jc[i]=jc[i-1]*i%mod;
    }
    for(ll i=4;i<=n;i++){
        // if(n<=2000){
        //     dp[i]=dp[i-1];
        //     for(ll k=2;k<=i;k++){
        //         ll p=i-k;
        //         dp[i]+=p*jc[i-2]%mod;
        //         dp[i]%=mod;
        //         dp[i]+=dp[i-2];
        //         dp[i]%=mod;
        //     }
        // }
        dp[i]=(dp[i-1]+(i-1)*(i-2)/2%mod*jc[i-2]%mod+(i-1)*dp[i-2]%mod);
        dp[i]%=mod;
        ans^=dp[i];
    }
    work(ans^1ll);
	return 0;
}