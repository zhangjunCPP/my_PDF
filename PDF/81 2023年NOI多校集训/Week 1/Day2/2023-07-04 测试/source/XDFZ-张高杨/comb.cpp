/*
T4 元祖
不理解...
贪心总该是对的吧？
这不就没了。
哦~
子序列可以不连续
那么这也就是说
这题多少还是有点复杂
先起步一眼二分答案
其实先不管二分答案
贪心总该是对的吧？（梅开二度）
好的我的确举不出反例
这也就说明，每次发现一个abab就直接放入b是最优的
现在的问题是，怎么寻找abab？
数据范围给了提示：我们可以拿桶存ai啊！
为什么人家要给ai<=n，这是个至关重要的提示，离散化都帮我们省了
我们从入桶顺序中找到第一个abab
怎么找？好问题。
要出现一个abab，首先会出现aa
在aa中间出现过的都可以被选作b
那么此时再次出现的任何一个b都会被直接统计答案，此时的桶需要清零
事实上，我们不在意b是哪个，而只在意有没有b
那么好办了，我们只要能够快速地标记b的情况即可
这部分我们允许的时间仅有log n
那么观察发现，我们或许并不需要做太多标记
我们每次重复会将可能的b的区间扩大，仅此而已
那么双指针再度上场框定b的区间，这道题就能够用二分查找解决

突然发现问题
这玩意儿不单调
额...寄
我们需要再套个数据结构记录区间内出现过哪些数
嚯？区间内？
注意到由于是双指针扩展框定区间，这里是n的
那么我们只需要另一个简简单单的桶就可以解决
甚至连log都省了？ 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int ft[N];//first time 首次出现位置 
int a[N];//给定的序列a 
bool b[N];//桶的英文是啥来着... 
int main()
{
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	int n,ans=0,clear_ptr=1;//清空指针 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int l=0,r=0;//一开始没有框定区间 
	for(int i=1;i<=n;i++)
	{
		if(ft[a[i]])//发现重复 
		{
			if(b[a[i]])//找到力！清空继续！ 
			{
				ans+=4;
//				printf("%d ans+4\n",i);
				//memset(ft,0,sizeof ft);
				//memset(b,0,sizeof b);
				//这么清空会出事的 
				for(int j=clear_ptr;j<=i;j++)b[a[j]]=false,ft[a[j]]=0;
				clear_ptr=i+1;
				//这样清空不是最优但时间正确 
				continue;
			}
			//没找到，扩展区间
			if((!l&&!r)||ft[a[i]]>r)//第一次框选区间 
			{
				l=ft[a[i]],r=i;//这是左开右开 
				for(int j=l+1;j<r;j++)b[a[j]]=true;
			}
			else//扩展原有区间 
			{
				while(r<i)
				{
					b[a[r]]=true;
					r++;
				}
				while(l>ft[a[i]])
				{
					b[a[l]]=true;
					l--;
				}
			}
//			printf("now b:(%d,%d)\n",l,r);
		}
		else ft[a[i]]=i;//记录ft 
	}
	printf("%d",ans);
	return 0;
}
