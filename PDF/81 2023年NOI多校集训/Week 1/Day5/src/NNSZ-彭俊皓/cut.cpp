#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=500005,MAXM=25;
int a,b,c,tot=1,sum=0;
int num[MAXN],dp[MAXN],lct[MAXN];
bitset<MAXM> last[MAXN];
inline int read()
{
    char x=getchar();int t=0;
    while(!isdigit(x))x=getchar();
    while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
    return t;
}
int mex(bitset<MAXM> x)
{
    int to=0;
    while(x[to])to++;
    return to;
}
int main()
{
    freopen("cut.in","r",stdin);
    freopen("cut.out","w",stdout);
    a=read();
    lct[1]=1;
    for(register int i=1;i<=a;++i)
    {
        num[i]=read();
        if(num[i]==mex(last[tot]))
        {
            dp[tot]++,last[tot][num[i]]=1;
        }
        else if(num[i]<mex(last[tot]))
        {
            lct[++tot]=i;last[tot][num[i]]=1;
            dp[tot]=mex(last[tot]);
        }
        else
        {
            bitset<MAXM> x,y;
            x[num[i]]=y[num[i]]=1;
            x|=last[tot],y|=last[tot-1]|last[tot];
            if(mex(y)>mex(x)+dp[tot-1])
            {
                dp[--tot]=mex(y);
                last[tot]=y;
            }
            else
            {
                dp[tot]=mex(x);last[tot]=x;
            }
        }
    }
//    for(register int i=1;i<=tot;++i)cout<<last[i]<<endl;
    for(register int i=1;i<=tot;++i)sum+=mex(last[i]);
    printf("%d %d\n",sum,tot);
    for(register int i=1;i<=tot;++i)printf("%d ",lct[i]);
    return 0;
}
