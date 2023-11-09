#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=500005;
int a,b,c,tot=0;
int num[MAXN],last[MAXN];
int nxt[MAXN],to[MAXN];
int que[25][MAXN],stk[25][MAXN],bj[MAXN];
inline int read()
{
	char x=getchar();int t=0;
	while(!isdigit(x))x=getchar();
	while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
	return t;
}
int main()
{
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	a=read();
	for(register int i=1;i<=a;++i)
	nxt[to[num[i]=read()]]=i,to[num[i]]=i;
//	for(register int i=1;i<=a;++i)printf("%d ",nxt[i]);
	for(register int i=1;i<=a;++i)last[nxt[i]]=i;
//	for(register int i=1;i<=a;++i)printf("%d ",last[i]);
	for(register int i=1;i<=a;++i)if(nxt[i])que[0][++tot]=nxt[i],stk[0][tot]=i;
	int len;
	for(len=0;(1<<len)<a&&tot;len++)
	{
		memset(bj,0,sizeof(bj));
		int cnt=0;
//		printf("%d:\n",len);
//		for(register int i=1;i<=tot;++i)
//			printf("%d ",que[len][i]);
//			puts("");
		for(register int i=1;i<=tot;++i)
		{
			if(bj[i])continue;
			int lct=upper_bound(que[len]+i+1,que[len]+tot+1,que[len][i])-que[len];
//			printf("(%d)",lct);
			if(lct==tot+1||(len==0&&stk[len][lct]>que[len][i]))continue;
//			printf("goal=%d,lct=%d,locate in %d\n",que[len][i],que[len][lct],stk[len][lct]);
			bj[lct]=1;
			que[len+1][++cnt]=que[len][i];
			stk[len+1][cnt]=stk[len][i];
		}
		tot=cnt;
	}
	cout<<(1<<len);
	return 0;
}
