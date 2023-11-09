/*
这又是什么神奇的找规律题目
我们算一个乘积有多少种方法需要sqrt(n)的时间
我们有这么多种乘积，肯定不能暴力
考虑递推
当我们知道[1,n-1]一共的方案数之后
怎么算[1,n]的？

没怎么想出来，先打暴力吧 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=3e8+10;
int i,z,n,j,ans;
int mp[N];
void work(){
	for(i=1;i<=n*n;++i)mp[i]=0;
	ans=0;
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			int x=++mp[i*j];
			ans+=x*x-(x-1)*(x-1);
		}
	}
	printf("%d\n",ans);
//	s[ask[z].second]=ans;
}
int T;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d",&T);
//	for(i=1;i<=T;++i)scanf("%d",&ask[i].first),ask[i].second=i;
//	sort(ask+1,ask+1+T);
	for(z=1;z<=T;++z){
//		n=ask[z].first,work();
		scanf("%d",&n);
		work();
	}
//	for(z=1;z<=T;++z)printf("%d\n",s[i]);
	return 0;
}
/*
4
1
2
7
35
*/
