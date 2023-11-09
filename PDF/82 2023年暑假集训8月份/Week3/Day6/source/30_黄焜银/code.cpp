/*
t1
我们先构造一个全0串，设它的长度为n
不难发现此时有n种方案
接着尝试在后面添加1
又惊奇的发现
每添加一个1，方案数就会增加n+1
设添完1之后的长度一共是len
那么方案数就是(len-n+1)*(n+1)-1
刚好对应题目所给的ab-1的形式
并且我们求解时发现
n=b-1
len=a+n-1=a+b-2
所以总长度刚好不会超过2e5-2
简直精妙绝伦 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,a,b,n,len;
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	n=b-1;
	len=a+b-2;
	for(i=1;i<=n;++i)putchar('0');
	for(i=1;i<=len-n;++i)putchar('1');
	return 0;
}

