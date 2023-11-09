#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=5e5+5;
struct node{int col,pos;}c[maxn];
set<int>s,s1;
long long ans;
int cutpos[maxn];
int cnt=1;
int main()
{
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d",&n);
	cutpos[cnt]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i].col);
		c[i].pos=i;
		if(c[i].col==0)
		{
			if(s.find(c[i].col)!=s.end())
			{
				if(s1.find(c[i].col)!=s1.end())
				{
					ans+=*(s1.end()--);
					s1.clear();
					s1.insert(c[i].col);
//										cnt++;
//										cutpos[cnt]=c[i].pos;
				}
				else
					s1.insert(c[i].col),cnt++,cutpos[cnt]=c[i].pos;
			}
			else
			{
				s.insert(c[i].col);
			}
		}
		else
		{
			if(s.find(c[i].col)==s.end())
			{
				s.insert(c[i].col);
			}
			else
			{
				if(s1.find(c[i].col)!=s1.end())
				{
					cnt++;
					cutpos[cnt]=c[i].pos;
					if(s1.find(0)!=s1.end())
					{
						ans+=*(s1.end()--);
						s1.clear();
						s1.insert(c[i].col);
					}
				}
				else
					s1.insert(c[i].col);
			}
		}
	}
	if(s.find(0)!=s.end())
	{
		ans+=*(s.end()--);
	}
	if(s1.find(0)!=s1.end())
	{
		ans+=*(s1.end()--);
	}
	printf("%lld %d\n",ans,cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d ",cutpos[i]);
	return 0;
}
