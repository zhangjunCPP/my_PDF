#include<bits/stdc++.h>
using namespace std;
//��������forһ��Ϳ�ȷ������Щ��
//����ֱ�ӾͿ�ʼ�ݳ�
//������Ϊ����k����������
//��DP��k�������������в�*2^x,xΪ���ȷ�1�ĸ��� 
using ll=long long;
constexpr ll mod=998244353;
int n,m,a[4010],one[4010];
ll fac[2010],inv[2010],pow2[2010];
//void init(){
//	inv[1]=1;for(int i=2;i<=2000;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
//	inv[0]=fac[0]=pow2[0]=1;for(int i=1;i<=2000;i++)fac[i]=fac[i-1]*i%mod,(inv[i]*=inv[i-1])%=mod,pow2[i]=pow2[i-1]*2%mod;
//}
//inline ll C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
ll dp[2010][2010][2];//�ڴ˹����м���������2^x;��һ���Ƿ����� 
int main(){
//	init();
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	bool flag=true;
	for(int i=1;i<=n;i+=a[i])one[++m]=a[i]==1,flag=flag&&all_of(a+i,a+i+a[i],[x=a[i]](int y){return x==y;});
	if(!flag)return printf("0"),0;
	dp[1][0][0]=1;
	for(int i=2;i<=m;i++)
	for(int j=0;j<i;j++){//ÿ�ΰ�ǰһ��������Ƿ�x2;���Լ��ǿ�ͷ��������� 
		dp[i][j][0]=(dp[i-1][j][0]*(one[i-1]?1:2)+dp[i-1][j][1])*(i-j)%mod;//���������(��������0)
		if(j)dp[i][j][1]=(dp[i-1][j-1][0]*2+dp[i-1][j-1][1])%mod;//������x2
//		printf("%d %d 0=%lld,1=%lld\n",i,j,dp[i][j][0],dp[i][j][1]);
	}
	ll ans=0;
	for(int i=0;i<m;i++)
	(ans+=mod+(i&1?-1:1)*(dp[m][i][0]*(one[m]?1:2)+dp[m][i][1])%mod)%=mod;
	cout<<ans;
	return 0;
}
//qi+r=0(mod m)
//i=-r*q^-1(mod m)
//i^-1=-(r^-1)*q(mod m)
