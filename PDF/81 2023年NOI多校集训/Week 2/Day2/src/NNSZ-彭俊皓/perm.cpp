#include<iostream>
#define ll long long
using namespace std;
const int MAXN=200005;
int a,b,c;
inline int read()
{
    char x=getchar();int t=0;
    while(!isdigit(x))x=getchar();
    while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
    return t;
}
ll ksm(ll x,int y)
{
    ll ans=1,query=1;
    while(y)
    {
        if(y&1)(ans*=query)%=b;
        y>>=1,(query*=query)%=b;
    }
    return ans%b;
}
int main()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    a=read();b=read();
    ll query=0;
    for(int i=1;i<=a;++i)
    {
        query+=(i-1)/2;
        if(query>b)query-=b;
    }
    query/=(a-1)/2;
    ll sum=ksm(query,n-2);
    printf("%lld",sum);
    return 0;
}
