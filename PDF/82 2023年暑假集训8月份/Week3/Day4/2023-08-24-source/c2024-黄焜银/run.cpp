/*
t1
��������
Ҫ���ڻ��պ���ô�ಽ������»���һ�������
��ʹ�������Ϊ����ֵ

���ѷ���
��������Ҷ����ԭ�����һ���̶���С�Ļ�
ֻ��ͨ���ı�������״���ı��������
����������Сֵ����(p>>1)-1

p�������ض��޽�
��Ϊ�����յ���ԭ��
��ôÿ�γ�ȥ�������Ӧ��һ���߻���
����pֻ����ż��

�ʼ���ǹ�����ǳ�Ϊ(p>>1)-1����Ϊ1�ľ���
�����賤Ϊx����Ϊy(x>=y)
ÿ�γ��Խ�y����1
��ô��ʱ���ε�����������(x-1)*(y+1) 
���ڴ�ʱ����(p>>1)-1��(x-1)*(y+1)��������������Ƕ�����ȡ�� 

��ˣ��޽⵱�ҽ�����
1.p&1!=0
2.a<(p>>1)-1��a>(p>>1)*(p>>1)
��������һ�����Թ��� 
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

