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
//只有平行不相交
//每根之间都不平行的情况就有sum=n*(n-1)/2
//那么我们假设有几个平行组,个数为a[1],a[2]...a[k](sum(a[i])=n)
//此时相交点数就有ans=sum-a[1]*(a[1]-1)/2-...-a[k]*(a[k]-1)/2
//题目就是让我们构造ans=m的方案
//通过移项可得2*sum-2*m=a[1]^2+a[2]^2...+a[k]^2-a[1]-a[2]-...-a[k]
//2*sum-2*m+n=a[1]^2+a[2]^2+...+a[k]^2,暴力复杂度不知道飞哪去了
//dp[i][j]为使用i根木棍后和为j的最少使用的桶
//复杂度O(n^4)
ll t,n,m,num,dp[55][2505];
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    srand(time(0));
    memset(dp,127,sizeof(dp));
    dp[0][0]=0;
    for(ll i=1;i<=54;i++){
        for(ll j=1;j<=54*54;j++){
            for(ll k=i-1;k>=0&&(i-k)*(i-k)<=j;k--){
                dp[i][j]=min(dp[i][j],dp[k][j-(i-k)*(i-k)]+1);
                if(dp[i][j]<=i)
                    break;
            }
        }
    }
	t=read();
    while(t--){
        n=read();
        m=read();
        num=n*n-2*m;
        if(num<=0){
            printf("0\n");
            continue;
        }
        if(n<=54)
            work(dp[n][num]<=n);
        else
            work((rand()+dp[rand()%50][rand()%2500])&1);
        putchar('\n');
    }
	return 0;
}