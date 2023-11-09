#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5+5;
int a[maxn];
int main()
{
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int temp=n%4;
	cout<<n-temp;
	return 0;
}
