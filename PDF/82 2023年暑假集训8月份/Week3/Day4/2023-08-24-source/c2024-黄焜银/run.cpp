/*
t1
给定步数
要你在画刚好这么多步的情况下画出一个多边形
并使它的面积为给定值

不难发现
无论如何我都会从原点造出一个固定大小的环
只是通过改变它的形状来改变面积而已
因此面积的最小值就是(p>>1)-1

p是奇数必定无解
因为最后的终点在原点
那么每次出去都必须对应着一条边回来
所以p只能是偶数

最开始我们构造的是长为(p>>1)-1，宽为1的矩形
我们设长为x，宽为y(x>=y)
每次尝试将y增加1
那么此时矩形的最大面积就是(x-1)*(y+1) 
而在此时，从(p>>1)-1到(x-1)*(y+1)的所有面积，我们都可以取到 

因此，无解当且仅当：
1.p&1!=0
2.a<(p>>1)-1或a>(p>>1)*(p>>1)
否则我们一定可以构造 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p,a,x,y,i,need;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&p,&a);
	if(p&1||a<(p>>1)-1||a>(p>>1)*(p>>1))return puts("Impossible"),0;
	x=(p>>1)-1,y=1;
	if(x*y==a){
		putchar('2');putchar('3');
		for(i=2;i<=x;++i)putchar('2');
		putchar('3');putchar('3');
		for(i=2;i<=x;++i)putchar('2');
		return 0;
	}
	for(--x,++y;x>=y;--x,++y){
//		printf("%lld %lld %lld\n",x,y,x+y<<1);
		if(x*y>=a){
			need=a-x*(y-1);
//			printf("need:%lld\n",need);
			if(need<=0)assert(0);
			for(i=1;i<=y;++i)putchar('2');
			putchar('3');
			for(i=2;i<=need;++i)putchar('2');
			putchar('3');
			if(need!=x){
				putchar('1');
				for(i=need+2;i<=x;++i)putchar('2');
				putchar('3');
				for(i=3;i<=y;++i)putchar('2');
			}
			else for(i=2;i<=y;++i)putchar('2');
			putchar('3');
			for(i=2;i<=x;++i)putchar('2');
			return 0;
		}
	}
	puts("Impossible");
	return 0;
}

