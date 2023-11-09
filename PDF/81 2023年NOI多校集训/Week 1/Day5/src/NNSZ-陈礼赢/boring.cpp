#include<bits/stdc++.h>
using namespace std;

const int mo=998244353;
const int MAXN=2e5+10;
int n,q;
int a[MAXN];
bool tong [MAXN];

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int lcm(int *b,int l,int r)
{
    if(l==r)
    {
        return b[l];
    }
    int g=gcd(b[l],b[l+1]);
    for(int i=l+2;i<=r;++i)
    {
        if(l+2<=r)
        {
            g=gcd(g,b[i])%mo;
        }
    }
    long long pre=1;
    for(int i=l;i<=r;++i)
    {
        pre=(1ll*pre*b[i]%mo)%mo;
    }
    return pre/g;
}

int main()
{
    freopen("boring.in","r",stdin);
    freopen("boring.out","w",stdout);

    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=q;++i)
    {
        for(int i=1;i<=MAXN;++i)
        {
            tong[i]=0;
        }
        int b[MAXN];
        int tot=0;
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;++j)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int p=lcm(a,l,r);
            if(!tong[p])
            {
                tong[p]=1;
                ++tot;
                b[tot]=p;
            }
        }
        cout<<lcm(b,1,tot)<<endl;
    }

    return 0;
}
