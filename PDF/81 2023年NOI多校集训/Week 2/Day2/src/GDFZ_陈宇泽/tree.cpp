#include <bits/stdc++.h>
using namespace std;
int n,mod=100000008;
int qpow(int x,int y)
{
    int ret=1;
    for(;y;y>>=1,x=x*x%mod)
    {
        if(y&1)
            ret=ret*x%mod;
    }
    return ret;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
    }
    printf("%d\n",qpow(2,n+1));
}
