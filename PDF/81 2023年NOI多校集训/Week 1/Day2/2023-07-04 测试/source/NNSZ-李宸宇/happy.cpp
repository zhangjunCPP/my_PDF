#include<bits/stdc++.h>
typedef long long ll; 
using namespace std;
const int N=1e5+10,M=510;

ll n,K,num[M],cost[M],t[N],q[N],f[N][2],C,a[N],ans[N];

int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
    scanf("%lld%lld",&n,&K);
    for(int i=1;i<=n;i++)scanf("%lld",&t[i]);
    for(int i=1;i<=K;i++)scanf("%lld%lld",&num[i],&cost[i]);
    scanf("%lld",&C);
    memset(f,0x3f,sizeof(f));
    f[0][0]=f[0][1]=0;
    int l=1,r=1;
    q[1]=0;
    for(int k=1;k<=K;k++){
    	l=1,r=1,q[1]=0;
        for(int i=1;i<=n;i++){
            f[i][0]=min(f[i-1][0],f[i-1][1])+C;
            a[i]=min(f[i-1][0],f[i-1][1]);
            while(l<=r&&t[q[l]]+num[k]-1<t[i])l++;
            if(l<=r)f[i][1]=min(f[i][1],a[q[l]]+cost[k]);
            while(l<=r&&a[i]<=a[r])r--;
            q[++r]=i;
        }
    }
    for(int i=1;i<=n;i++)ans[i]=min(f[i][0],f[i][1]);
    for(int i=1;i<=n;i++)printf("%lld\n",ans[i]-ans[i-1]);
    return 0;
}
/*
3 2
10 20 30
90 50
1440 120
20
*/
/*
10 2
13 45 46 60 103 115 126 150 256 516
90 45
450 100
20
*/
