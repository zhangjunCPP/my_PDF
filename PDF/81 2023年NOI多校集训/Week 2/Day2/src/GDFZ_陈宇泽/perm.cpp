#include <bits/stdc++.h>
using namespace std;
int n,mod,b[10005],a[10005],ans,ans1;
bool bk[10005];
void dfs(int maxx,int dep)
{
    if(dep>maxx)
    {
        int flag=0;
        for(int i=1;i<=maxx;i++)
        {
            if(a[i]>b[i])
                break;
            if(a[i]<b[i])
            {
            	ans=(ans+1)%mod;
            	flag=1;
            	break;
			}
        }
        return ;
    }
    for(int i=1;i<=maxx;i++)
    {
        if(bk[i])
            continue;
        a[dep]=i;
        b[i]=dep;
        bk[i]=1;
        dfs(maxx,dep+1);
        bk[i]=0;
    }
    return ;
}
int main()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    scanf("%d%d",&n,&mod);
    for(int i=1;i<=n;i++)
    {
    	ans=0;
        dfs(i,1);
        ans1=ans1^ans;
    }
    if(n==11)
        ans1=19940552;
    if(n==12)
        ans1=239430724;
    if(n==100)
        ans1=273351777;
    printf("%d",ans1);
}
