/*
D match
暴力30pts跑路了，这把要是再是170pts那就成新的因果律武器了（
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2010;
char s[N],p[N];
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int k;
    scanf("%d",&k);
    scanf("%s",s+1);
    int n=strlen(s+1);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%s",p+1);
        int len=strlen(p+1),ans=0;
        for(int j=1;j<=n-len+1;j++)
        {
            int p1=1,p2=len;
            while(s[j+p1-1]==p[p1]&&p1<=len)p1++;
            while(s[j+p2-1]==p[p2]&&p2)p2--;
            if(p2-p1<k)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}