/*
A Klein
题目显然想要我们O(1)回答
可以根据不同的经过边界的情况，在外面额外展开八个图，计算出对应终点坐标
由于有八个，非常地难搞，这就是道阴间结论题
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int x[3],y[3];
		scanf("%d%d%d%d",&x[1],&y[1],&x[2],&y[2]);
		int y_dis=min(abs(y[1]-y[2]),n-abs(y[1]-y[2])+1);
		int ans=y_dis+abs(x[1]-x[2]);
		y[1]=n-y[1];
		y_dis=min(abs(y[1]-y[2]),n-abs(y[1]-y[2])+1);
		int x_dis=n-abs(x[1]-x[2])+1;
		printf("%d\n",min(ans,x_dis+y_dis));
	}
	return 0;
}
