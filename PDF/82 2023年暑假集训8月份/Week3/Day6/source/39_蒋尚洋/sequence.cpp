//����trie���������?
//����׷��һ���ַ����������н���׷��Ҷ�ڵ�
//�����ͼ���Ҷ�ڵ�����?(8:18)
//czc:��������:((8:20) 
//������(8:29) 
//���԰�,Ҳ��һ����ҪҶ�Ӱ�
//�Ǿͼ�0/1��λ��(��Ȼ���)
//�ܷ��0������1����?
//�ܹ���k���Ǹ����,��ô�ͻ���k�����׹�ϵ
//����ʣ��2(k+1)-k=k+2����λ!(8:34) 
//8:41д��,��������Ӧ���ǶԵ� 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=998244353;
ll dp[50][260][260];//0��j����λ,k����ͬ������ 
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,k;
	cin>>n>>k;
	dp[0][1][0]=1;
	for(int i=0;i<n;i++)
	for(int w0=1;w0<=k+2;w0++)//jҪ��k+2���ȫ�� 
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
