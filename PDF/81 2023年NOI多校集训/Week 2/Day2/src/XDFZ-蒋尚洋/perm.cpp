//����Q(Q(p))=p,������ȥ��ȵĳ���2����
//��ȵ�:Q(p)_pi=i,Q(p)_pi=p_pi=>p_pi=i,��p_p_pi=p_i,��piҲ����p_pi=i!�ɶ�? 
//������i��λ������pi=i,�򷽰�ΪC(n,i)*n!/2^((n-i)/2) 
//�ʶ���һ��n,������Ϊ....
//��ʵ���ǵ���,��Fn=Fn-1 + C(n-1,1)Fn-2(�����¼ӵ�һ����:Ҫô����,Ҫô��֮ǰĳһ�����)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod;int n;
ll fac[10000010],F[10000010];
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>n>>mod;
	const int inv2=mod+1>>1;
	fac[0]=1,fac[1]=1,fac[2]=2,F[1]=1,F[2]=2;
	for(int i=3;i<=n;i++)fac[i]=fac[i-1]*i%mod,F[i]=(F[i-1]+(i-1)*F[i-2])%mod;
	ll ans=0;
	for(int i=3;i<=n;i++)ans^=(mod+fac[i]-F[i])*inv2%mod;
	cout<<ans;
	return 0;
}
