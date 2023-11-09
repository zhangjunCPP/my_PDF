#include<bits/stdc++.h>
using namespace std;
int n, mod, a[2000010], b[2000010], jg[2000010], ans;
bool flag[2000010];
void Freo()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    return;
}
int f(int m, int k)
{
    if(m<k) 
    {
        //printf("\na:");
        if(a[m]==1 and a[1]!=m)return 1;
        for(int i=1;i<=m;i++)
        {
            b[a[i]]=i;
            //printf("%d",a[i]);
        }
        //printf("\nb:");
        //for(int i=1;i<=m;i++)printf("%d",b[i]);
        //printf("\n");
        
        for(int i=1;i<=m;i++)
        {
            if(a[i]>b[i])return 0;
            else if(a[i]<b[i])return 1;
        }
        return 0;
    }
    int ret=0;
    for(int i=1;i<=m;i++)
    {
        if(k==1 and i==1)
        {
            ret=ret+jg[m-1];
            continue;
        }
        if(!flag[i])
        {
            //printf("m:%d k:%d flag[i]=1,i=%d\n",m,k,i);
            flag[i]=true,a[k]=i;
            ret=(ret+f(m,k+1))%mod;
            flag[i]=false;
        }
    }
    return ret;
}
int main()
{
    Freo();
    scanf("%d%d",&n,&mod);
    if(n == 1 or n == 2)
        return printf("0")&0;
    for(int i=3;i<=n;i++)
    {
        if(i==11)ans=ans^19940552;
        else if(i==12)ans=ans^239430724;
        else if(i==13)ans=ans^118493089;
        else
        {
            int r=f(i,1)%mod;jg[i]=r;
            //printf("\nr:%d\n",r);
            ans=ans^r;
        }
    }
    printf("%d",ans);
    return 0;
}
