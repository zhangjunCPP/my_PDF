/*
T4 lihua
这题……卡空间啊……
所以动态开点的trie了解一下？
*/
#include<bits/stdc++.h>
using namespace std;
const int N=3000010;
struct edge
{
	int v,nex;
	char c;
}e[N];
int fir[N],ent;
inline void add(int u,int v,char c)
{
	e[++ent]={v,fir[u],c};
	fir[u]=ent;
	return;
}
int tot=1;
int ter[N],val[N];
inline void Insert(char s[],int ans)
{
	int u=1,len=strlen(s);
	for(int i=0;i<len;i++)
	{
		bool flag=false;
		for(int j=fir[u];j;j=e[j].nex)if(e[j].c==s[i])u=e[j].v,flag=true;
		if(!flag)add(u,++tot,s[i]),u=tot;
		val[u]++;
	}
	ter[u]=min(ter[u],ans);
	return;
}
char s[N];
int sum[35][30];
int main()
{
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	memset(ter,0x7f,sizeof ter);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int val=0,len=strlen(s);
		for(int j=0;j<len;j++)
		{
			sum[j][s[j]-'a']++;
			val+=sum[j][s[j]-'a'];
		}
		Insert(s,val+1);
	}
	int Q;
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		scanf("%s",s);
		int u=1,len=strlen(s),ans=0;
		for(int j=0;j<len;j++)
		{
			bool flag=false;
			for(int k=fir[u];k;k=e[k].nex)if(e[k].c==s[j])u=e[k].v,flag=true;
			if(!flag)break;
			ans+=val[u];
		}
		if(ter[u]<ter[0]){printf("%d\n",ter[u]+1);continue;}
		else printf("%d\n",ans+n);
	}
    return 0;
}