#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
const int mo=1e9+7;
int n;
int tot=0,head[MAXN],to[MAXN],nxt[MAXN];
int color[MAXN];
long long result=0;

void addEdge(int a,int b);
void dfs(int x);

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n-1;++i)
	{
		int a,b;
		cin>>a>>b;
		addEdge(a,b);
		addEdge(b,a);	
	}
	dfs(1);
	cout<<result<<endl;
	return 0;
}

void addEdge(int a,int b)
{
	++tot;
	to[tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
}

void dfs(int x)
{
	if(x==n+1)
	{
		int f=1,l=n;
		for(int i=1;i<=n;++i)
		{
			if(color[i]==color[1])
			{
				f=i;
			}
			if(color[i]==color[n] and l==n)
			{
				l=i;
			}
		}
		result=(result+max(f-1,n-l)%mo)%mo;
		return ;
	}
	
	color[x]=1;
	dfs(x+1);
	
	color[x]=0;
	dfs(x+1);
}


