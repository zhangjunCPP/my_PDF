//由于Q(Q(p))=p,所以抛去相等的除以2即可
//相等的:Q(p)_pi=i,Q(p)_pi=p_pi=>p_pi=i,而p_p_pi=p_i,对pi也满足p_pi=i!成对? 
//考虑有i个位置满足pi=i,则方案为C(n,i)*n!/2^((n-i)/2) 
//故对于一个n,方案数为....
//其实考虑递推,则Fn=Fn-1 + C(n-1,1)Fn-2(考虑新加的一个数:要么单着,要么和之前某一个配对)
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
