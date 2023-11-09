/*
B ����
�����...
������������֮�����ǿ϶�Ҫ���ұߵ����ܹ��ճ���ǰ���ֵ�ƽ����
��Ȼ�����ǻ������ղ����������Ϊ��ʹ���������������ܶ࣬���Ǵ�С�Ŀ�ʼ�գ�Ȼ�����Ҵ��
���������������ܹ��õ�һ�����ܱ������� $\mathcal{O}(n log^2 n)$ ������...��ܲ���
����������һ��
��һ��ʼ����������� $a$ ���������ƽ����
��ʱ���ǿ���ͨ��ɾ�����ִ���ʹ��ƽ������С
�õĺõ�
������ȻҪɾɾ���ģ�����������һ����������
��ô���������ˣ��ǳ��Ŀ죬ֻ�� $\mathcal{O}(n)$

������
�ڼ���С����ʱ��Ҫע�⵽ƽ�����ǻ���
��������һ��ʼ����ʹ�õ��������������������д��ʱ�������

��������A���ˣ��治��������
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
deque<long long>dq;//������д
long long a[N];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n;
	scanf("%d",&n);
	long long Sv=0;
	for(int i=1;i<=n;i++)scanf("%lld",a+i),Sv+=a[i];
	sort(a+1,a+n+1);//ƿ��
	int ptr=0;
	for(int i=1;i<=n;i++)if(a[i]*n>Sv)dq.push_back(a[i]);else ptr=max(ptr,i);
	int ans=dq.size();
//	for(int i=0;i<(int)dq.size();i++)printf("%lld ",dq[i]);
//	putchar(10);
	while(!dq.empty())
	{
		Sv-=dq.back();dq.pop_back();n--; 
		while(a[ptr]*n>Sv&&ptr>0)dq.push_front(a[ptr]),ptr--;
		ans=max(ans,(int)dq.size());
//		for(int i=0;i<(int)dq.size();i++)printf("%lld ",dq[i]);
//		putchar(10);
	}
	printf("%d",ans);
	return 0;
}
/*
Corner Cases:
�����Ϻ��ѱ�֤��ȷ��QAQ
#1 ��һ��ʮ
11
1 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000
Answer:10
Correct

#2 �Ȳ�����
10
1 5 9 13 17 21 25 29 33 37
Answer:5
Correct

#3 �ȱ�����
10
1 3 9 27 81 243 729 2187 6561 19683
Answer:2
�Ҿ���2Ӧ��û��
Correct

#4 Fibonacci����
10
1 1 2 3 5 8 13 21 34 55
Answer:3
���Բ�������4���������������Ե����⣡��
Wrong

#5 ÿ��������ǰ��������֮�ͣ�
10
1 4 5 10 20 40 80 160 320 640
Answer:3
��Ҳ��֪����
Correct
*/
