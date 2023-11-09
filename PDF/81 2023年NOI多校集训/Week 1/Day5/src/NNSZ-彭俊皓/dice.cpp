#include<iostream>
using namespace std;
const int MAXN=1000005;
int a,b,c;
inline int read()
{
    char x=getchar();int t=0;
    while(!isdigit(x))x=getchar();
    while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
    return t;
}
int main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    a=read();b=read();
    if(a==1)
    {
        puts("Yes");
        for(register int i=1;i<=6;++i)printf("%d ",i*b);
    }
    else if(b==2)
    {
        puts("Yes");
        for(register int i=1;i<=a;++i)
        {
            for(register int j=1;j<=6;++j)
            {
                printf("%d ",b);b+=2;
            }
            puts("");
        }
    }
    else
    {
        if(__builtin_popcount(b)<6)puts("No");
        else puts("No");
    }
    return 0;
}
