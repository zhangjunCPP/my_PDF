//直接搞要爆
//肯定是有什么贪心的性质...吗?
//反正是极差,那么分了一个后剩下两个均分最好
//如何计算均分?
//就是使两者差值的abs最小
//dp(8:25)
//8:43回来了
//8:46:等等哈dp是对的吗
//我如果要让s的极差最小不一定要让子集的极差最小啊..
//例如 1 1 1 1 1 5
//那就是要遵循某种贪心
//盲猜排序
//好像不显然,先跑了(8:48) 
//回来了(9:46)
//不咋会不咋会
//写暴力写暴力 
//10:05:至少3^n是写好了
//去厕所忽然想到会不会和骼绰原理有关:三人行,必有一人大于等于ceil(sum/3),必有一人小于等于floor(sum/3)
//如果我随机分配一个会如何
//那么一次有3!/3^25的概率成功
//来2^25次呢?几乎没机会成功...
//不过这题大概率是随机化吧.不然没法做啊
//有什么1-c/2^25成功率的方法吗?
//确定一个集合?不合理啊...
//不管了直接乱做
//不管了直接跑(10:42) 
#include<bits/stdc++.h>
using namespace std;
int n,a[30];
namespace task11{
	int sum[1<<15];
	void solve(){
		for(int s=0;s<(1<<n);s++)
		for(int i=1;i<=n;i++)if(s>>i-1&1)sum[s]+=a[i];
		int s0=0,s1=0,s2=0,ans=2e9,U=(1<<n)-1;
		for(int s=0;s<(1<<n);s++)
		for(int s_=U^s;s_;s_=s_-1&(U^s)){
			int s__=U^s^s_,
			dif=max({sum[s],sum[s_],sum[s__]})-
				min({sum[s],sum[s_],sum[s__]});
			if(dif<ans)ans=dif,s0=s,s1=s_,s2=s__;
		}
		for(int i=1;i<=n;i++,putchar(' ')){
			if(s0>>i-1&1)putchar('1');
			else if(s1>>i-1&1)putchar('2');
			else putchar('3');
		}
	}
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=15)return task11::solve(),0;
	return 0;
}
