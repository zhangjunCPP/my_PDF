#include<iostream>
#include<algorithm>
#include<string.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define sec second
#define mp(x,y) make_pair(x,y)
using namespace std;
const int MAXN=100005,MAXM=220005,modd=998244353;
int a,b,c,tot=0;
int num[MAXN],lct[MAXN];
pii now[MAXM];
ll sum[MAXN];
inline int read()
{
    char x=getchar();int t=0;
    while(!isdigit(x))x=getchar();
    while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
    return t;
}
bool cmp(pii x,pii y){return x.fi==y.fi?x.sec<y.sec:x.fi<y.fi;}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main()
{
    freopen("boring.in","r",stdin);
    freopen("boring.out","w",stdout);
    a=read();b=read();
    for(register int i=1;i<=a;++i)
        (sum[i]=sum[i-1]*(num[i]=read()))%=modd;
    for(register int i=1;i<=b;++i)
    {
        memset(lct,0,sizeof(lct));
        int k=read();
        for(register int j=1;j<=k;++j)
        {
            int x,y;x=read();y=read();
            now[j]=mp(x,y);
        }
        sort(now+1,now+k+1,cmp);
        ll query,Gcd;
        query=Gcd=1;
        for(register int j=1;j<=k;++j)
            lct[now[j].fi]+=1,lct[now[j].sec+1]-=1;
//        for(register int j=1;j<=k;++j)printf("(%d %d)",now[j].fi,now[j].sec);
        int val=0;
        for(register int j=now[1].fi;j<=now[k].sec;++j)
        {
            val+=lct[j];
            if(!val)continue;
//            cout<<gcd(Gcd,num[j])<<"!";
            (Gcd=(Gcd*num[j])%modd/gcd(Gcd,num[j]))%=modd;
//            if(val>1)(query*=num[j])%=modd;
//            printf("(num[%d]=%d)%lld %lld\n",j,num[j],Gcd,query);
        }
        printf("%lld\n",(Gcd)%modd);
    }
    return 0;
}//50


