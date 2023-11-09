 #include <bits/stdc++.h>
 using namespace std;
 int n,m;
 int a[1000010];
 int b[1000010];
 int c[1000010];
 void suan(int x,int y)
 {
 	long long ans=1;
 	memset(b,0,sizeof(b));
 	for (int i=x;i<=y;i++)
 	{
 		ans*=a[i];
 		b[i]=a[i];
 		c[i]=a[i];
	}
	int l=y-x;
	int k=0;
	while(k<=l)
	{
		for (int o=1;o<=y-x-k+1;o++)
		{
			for (int i=x;i<=y-k-o;i++)
			{
				int g=__gcd(b[x+k],c[i]);
				ans*=g;
				c[i]=g;
			}
		}
		for (int i=x;i<=y;i++)
		{
			c[i]=a[i];
		}
		k++;
	}
	cout<<(ans%998244353)<<endl;
 }
 int main()
 {
 	freopen("ddickky.in","r",stdin);
 	freopen("ddickky.out","w",stdout);
 	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		suan(x,y);
	}
 	return 0;
 }
 
