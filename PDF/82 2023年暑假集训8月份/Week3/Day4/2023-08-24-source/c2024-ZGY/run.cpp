/*
A run
�ܸо����������
�������Ҽ������ѵ�T1
ע�⵽��ʵ���������ܹ�ͨ���ı���Χ���������
������ö�ٵ׵ĳ��ȣ���ô�ߵĳ��ȿ�֪
��ʱ����Χ���������С�����֪�����Խ���ж��Ƿ��н�
�н��ʱ��ֱ�ӿ�ʼ���켴��
ע�⵽��С������������������������
    #
    #
    # 
    #
    #
#####
һ��L
���ȷ�������ܹ����ز�©��
��ͼ֤������û�а취֤QAQ
��������ȥȷʵ�ܶԣ�����ֱ��д

����Dev��GDB���ã����������ǿ�����ܲ����㣬��Ҫ�ֶ�����
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void r(T &&x)
{
	char c;x=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9')x*=10,x+=c-'0',c=getchar();
	return;
}
template<typename T,typename ...Args>
inline void r(T &&x,Args &&...args){r(x);r(args...);return;}
inline void RUN(long long x,long long y,long long a)
{
	if(x==1&&y==1){printf("3333");exit(0);}
	if(x==1)swap(x,y);
	long long s=x*y;
	for(int i=1;i<=y;i++)printf("2");
	printf("3");
	long long f=(s-a)/(x-1);
	bool d=false;
	if(f)printf("3"),d=true;
	for(int i=2;i<=f;i++)printf("2");
	if(d)printf("1");
	else printf("2");
	long long k=x-2-(s-a)%(x-1);
	bool n=(k!=x-2);
	for(int i=1;i<=k;i++)printf("2");
	printf("3");
	if(n)printf("1");
	for(int i=1;i<x-2-k;i++)printf("2");
	if(n)printf("3");
	for(long long i=f+1+n;i<y;i++)printf("2");
	printf("3");
	for(int i=1;i<x;i++)printf("2");
	exit(0);
}
int main()
{
	int p;
	long long a;
	r(p,a);
	if(p&1||p/2-1>a){printf("Impossible");return 0;}
	for(int i=1;i<=p;i++)
	{
		long long x=i,y=p/2-i;
		if(x*y>=a)RUN(x,y,a);
	}
	printf("Impossible");
	return 0;
}
