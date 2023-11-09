/*
A 01密码
从性质下手，注意到题目不存在无解，很可能是ab的原因
没事为什么给ab呢？好问题，这说明ab很可能意味着正解中的某个参数
稍等，这是不是输出(a-1)个1和(b-1)个0就可以了啊...
啊？
啊？？？？？
为什么啊？？
我正觉得说这题居然第一级结论我就不会证的时候，发现甚至a,b<=10^5
卧槽？！？！牛逼！？！？
出于正确性考虑，等会儿写个SPJ看看...
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)putchar(49);
	for(int i=1;i<b;i++)putchar(48);
	return 0;
}
