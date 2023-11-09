/*
B 报数
这道题...
先排序，排完序之后我们肯定要让右边的数能够凑出当前二分的平均数
自然，我们会遇到凑不出的情况，为了使得这样的数尽可能多，我们从小的开始凑，然后尝试找大的
于是算下来我们能够得到一个可能被卡掉的 $\mathcal{O}(n log^2 n)$ 的做法...这很不对
我们重新来一遍
在一开始我们求出整个 $a$ 序列里面的平均数
此时我们可以通过删除部分大数使得平均数减小
好的好的
我们自然要删删最大的，于是这便成了一个单调队列
那么这题做完了，非常的快，只用 $\mathcal{O}(n)$

这样啊
在加入小数的时候要注意到平均数是会变的
理论上在一开始我们使用的是所有数，因此我们在写的时候疏忽了

好了现在A掉了，真不愧是老子
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
deque<long long>dq;//懒得手写
long long a[N];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n;
	scanf("%d",&n);
	long long Sv=0;
	for(int i=1;i<=n;i++)scanf("%lld",a+i),Sv+=a[i];
	sort(a+1,a+n+1);//瓶颈
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
考场上很难保证正确了QAQ
#1 以一当十
11
1 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000
Answer:10
Correct

#2 等差数列
10
1 5 9 13 17 21 25 29 33 37
Answer:5
Correct

#3 等比数列
10
1 3 9 27 81 243 729 2187 6561 19683
Answer:2
我觉得2应该没错
Correct

#4 Fibonacci数列
10
1 1 2 3 5 8 13 21 34 55
Answer:3
绝对不可能有4！！你这个程序绝对的问题！！
Wrong

#5 每个数都是前面所有数之和？
10
1 4 5 10 20 40 80 160 320 640
Answer:3
我也不知道了
Correct
*/
