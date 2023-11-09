#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10;
int n;
int a[MAXN];
queue<int>q[MAXN];
int dp[MAXN];
bool t[110];
int pos[MAXN];

int find_mex(int l,int r)
{
    int ans;
    for(int i=0;i<=100;++i)
    {
        t[i]=0;
    }
    for(int i=l;i<=r;++i)
    {
        t[a[i]]=1;
    }
    for(int j=0;j<=100;++j)
    {
        if(!t[j])
        {
            ans=j;
			break;
        }
    }
    return ans;
}

int main()
{
    freopen("cut.in","r",stdin);
    freopen("cut.out","w",stdout);

    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;++i)
    {
        dp[i]=find_mex(i,i);
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<i;++j)
        {
            int y=find_mex(j+1,i);
            if(dp[i]<dp[j]+y)
            {
                dp[i]=dp[j]+y;
                q[i]=q[j];
                q[i].push(j+1);
            }
        }
    }

    cout<<dp[n]<<' '<<q[n].size()<<endl;
    while(!q[n].empty())
    {
        cout<<q[n].front()<<' ';
        q[n].pop();
    }

    return 0;
}
