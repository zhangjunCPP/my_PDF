#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);

    int n,k;
    scanf("%d%d",&n,&k);

    if(n==1)
    {
        cout<<"Yes"<<endl;
        for(int i=1;i<=6;++i)
        {
            cout<<i*k<<' ';
        }
        return 0;
    }

    if(k%2==0)
    {
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=6;++j)
            {
                cout<<j*k<<' ';
            }
            cout<<endl;
        }
        return 0;
    }

    cout<<"No"<<endl;

    return 0;
}