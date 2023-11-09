#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
    	int x;
    	scanf("%d",&x);
    	a[x]++;
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i])
		{
			ans+=a[i]/2;
		}
	}
	cout<<ans/2*4;
}
