#include<bits/stdc++.h>
#define int long long
#define il inline
using namespace std;
const int N=2*1e5+10;
const int mod=998244353;
il int read()
{
	int w=1,c=0;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())c=c*10+ch-'0';
	return w*c;
}
int n,q;
int a[N];
int l,r;//一次询问 
int sum;
void dfs(int x,int gcd)
{
	if(x>r)
	{
		sum=sum*gcd%mod;
		return;
	}
	if(gcd==-1)//没选第一个 
	{
		dfs(x+1,gcd);//不选 
		dfs(x+1,a[x]);//选 
	}
	else
	{
		dfs(x+1,gcd);
		dfs(x+1,__gcd(gcd,a[x]));
	}
}
signed main()
{
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=q;i++)
	{
		sum=1;
		l=read(),r=read();
		dfs(l,-1);
		cout<<-sum<<"\n";
	}
	return 0;
}
