//插入trie树考虑如何?
//这样追加一个字符就是在所有结点后追加叶节点
//这样就记下叶节点数量?(8:18)
//czc:题面有误:((8:20) 
//回来了(8:29) 
//不对啊,也不一定是要叶子啊
//那就记0/1空位数(显然会寄)
//能否从0总数推1总数?
//总共有k个非根结点,那么就会有k个父亲关系
//还会剩下2(k+1)-k=k+2个空位!(8:34) 
//8:41写完,看眼样例应该是对的 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=998244353;
ll dp[50][260][260];//0有j个空位,k个不同子序列 
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,k;
	cin>>n>>k;
	dp[0][1][0]=1;
	for(int i=0;i<n;i++)
	for(int w0=1;w0<=k+2;w0++)//j要到k+2是最安全的 
	for(int c=0;c<=k;c++){
		int w1=c+2-w0;
		if(w1<0)continue;
		if(c+w0<=k)(dp[i+1][w0][c+w0]+=dp[i][w0][c])%=mod;
		if(c+w1<=k&&w0+w1<=k+2)(dp[i+1][w0+w1][c+w1]+=dp[i][w0][c])%=mod;
	}
	for(int c=1;c<=k;c++){
		ll ans=0;
		for(int w0=1;w0<=k+2;w0++)
		ans+=dp[n][w0][c];
		printf("%lld ",ans%mod);
	}
	return 0;
}
