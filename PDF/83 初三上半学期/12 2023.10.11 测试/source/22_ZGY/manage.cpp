/*
T2 manage
一个元素前面最近的相同元素的位置决定了贡献
BIT维护即可轻松解决
*/
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int lt[N],a[N];
int tr[2][N];
inline void ad(int p,int x,int c){for(;x<N;x+=(x&(-x)))tr[p][x]+=c;return;}
inline int ask(int p,int x){int ret=0;for(;x;x-=(x&(-x)))ret+=tr[p][x];return ret;}
int main()
{
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",a+i);
	m=unique(a+1,a+m+1)-a-1;
	for(int i=1;i<=m;i++)
	{
		if(lt[a[i]])ad(0,ask(1,i)-ask(1,lt[a[i]])+1,1);
		if(lt[a[i]])ad(1,lt[a[i]],-1);
		lt[a[i]]=i,ad(1,i,1);
	}
	for(int i=1;i<=n;i++)printf("%d ",m-ask(0,i));
	return 0;
}
