#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
const int N=1e5+10;
int n,q,sum;
string dic[N],ss;
int main()
{
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>dic[i];
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>ss;
		sum=0;//次数 
		for(int j=1;j<=n;j++)
		{
			sum++;
			if(ss==dic[j])
			{
				sum+=dic[j].size(); 
				break;
			}
			for(int k=0,len=ss.size();k<len;k++)//一个一个比较 
			{
				if(k>dic[j].size()||dic[j][k]!=ss[k]) break;
				else sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
