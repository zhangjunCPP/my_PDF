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
//一个无脑的思路,直接dp
//令dp[i]为前i次进入游乐园的代价
//显然dp[i]=min{dp[j]+cost[k](t[j+1]+num[k]-1>=t[i]),dp[i-1]+One}
//暴力O(n^2*k)
//考虑如何优化,贪心思想,如果要购买一张时限票,那么它能包含到的入场次数越多越好
//时间复杂度O(n*k*log2(n)),极限情况8e8左右,还需要优化
ll n,k,t[100005],One,dp[100005],now=1,cnt;
struct node{
    ll num,cost;
    bool operator < (const node&t) const{
        return num<t.num;
    }
}a[505],b[505];
int main(){
    freopen("happy.in","r",stdin);
    freopen("happy.out","w",stdout);
	n=read();
    k=read();
    for(ll i=1;i<=n;i++){
        t[i]=read();
    }
    for(ll i=1;i<=k;i++){
        a[i].num=read();
        a[i].cost=read();
    }
    One=read();
    memset(dp,127,sizeof(dp));
    sort(a+1,a+k+1);
    b[++cnt]=a[1];
    for(int i=2;i<=k;i++){
        if(a[i].num<=b[cnt].num)
            continue;
        b[++cnt]=a[i];
    }
    k=cnt;
    for(int i=1;i<=k;i++){
        a[i]=b[i];
    }
    dp[0]=0;
    //暴力：
    // for(ll i=1;i<=n;i++){
    //     for(ll j=0;j<i;j++){
    //         for(ll p=1;p<=k;p++){
    //             if(t[j+1]+a[p].num-1>=t[i])
    //                 dp[i]=min(dp[i],dp[j]+a[p].cost);
    //         }
    //     }
    //     dp[i]=min(dp[i],dp[i-1]+One);
    // }
    for(ll i=1;i<=n;i++){
        for(ll p=1,nex=i;p<=k;p++){
            ll last=max(t[i]-a[p].num+1,t[1]);
            ll l=1,r=nex+1;
            while(l<r){
                ll mid=(l+r)>>1;
                if(t[mid]<last)
                    l=mid+1;
                else
                    r=mid;
            }
            nex=r;
            dp[i]=min(dp[i],dp[r-1]+a[p].cost);
        }
        dp[i]=min(dp[i],dp[i-1]+One);
    }
    for(ll i=1;i<=n;i++){
        work(dp[i]-dp[i-1]);
        putchar('\n');
    }
	return 0;
}