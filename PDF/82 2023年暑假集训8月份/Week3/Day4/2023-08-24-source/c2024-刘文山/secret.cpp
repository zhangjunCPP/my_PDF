#include<bits/stdc++.h>
using namespace std;
int k;
#define ll long long
const int mod=65535;
vector<int> v; 
vector<int> v1,v2;
ll ans=1;
inline ll qpow(ll a,ll b){
	ll ret=1ll;
	for( ; b ; b>>=1ll){
		if(b&1ll) ret=ret*a%mod;
		a=a*a%mod;
	}
	return ret;
}
inline void dfs(int now){
	if(now==(int)v.size()){
		int n=v.size();
		int n2=n/2,n1=(n-1)/2ll+1;
		if((int)v1.size()==n1 && (int)v2.size()==n2){
			ll sum=0;
			for(auto x:v1){
				sum=(sum+(ll)x)%mod;
			}
			for(auto x:v2){
				sum=(sum+(ll)x*256ll)%mod;
			}
			ans=ans*sum%mod;
		}
		return ;
	}
	v1.push_back(v[now]);
	dfs(now+1);
	v1.pop_back();
	v2.push_back(v[now]);
	dfs(now+1);
	v2.pop_back(); 
}
inline void solve1(){
	v.clear();
	for(int i=1,x,y;i<=k;i++){
		cin>>x>>y;
		for(int j=1;j<=y;j++) v.push_back(x);
	}
	ans=1ll;
	dfs(0);
	int n=v.size();
	int n2=n/2,n1=(n-1)/2ll+1;
	ll b=1ll;
	for(ll i=1;i<=n2;i++) b=b*i;
	for(ll i=1;i<=n1;i++) b=b*i;
	cout<<qpow(ans,b)<<endl;
}
int main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout); 
	int T; 
	cin>>T;
	while(T--){
		cin>>k;
		solve1();
	}
	return 0;
}
/*
�����˽�������ͦ�õ�ѽ��
�����ָ���ô�ߣ�
13 ȫ����
10 ֱ�Ӽ��� n! 
ģ�� 65535 �е�С��֡�
�� 256^2 -1 ���е�߼���
����һ��256���������൱��ÿһλ��ϵ���ǡ�
1 256 1 256 1 256 ͦ iteresting �ġ�
��Ӧ�������� 27 �ֵģ����ڶ�ÿ�������ּ��ϣ�ϵ��Ҫô�� 1 Ҫô�� 256��
���ڻ��� 2h��ѧϰFFͬѧֱ�ӳ����⡣
��ο��Ըо��򵥵㡣
ǰ�� 3 �⣬������ҷ��� 100+100+60��
T4 �ٴ� 50 ����ʵҳͦ�ߵ��ˣ�����������ѡ��
1.����50ȥ���ǰ��ģ���֤���ҷ֡�
2.ֱ�ӳ� T3 �� T4 ���⡣
�����ұȽϱ��أ����Թ���ѡ��� 1 �wtcl����
T3 T4 ������ȷ�һ���𣿱Ͼ�����ҷֺ�ʹ�ġ� 
MMSD���ҷ��� y=1e9 ���ܶ���Ү��
���㽵�Σ�ҲҪ�� y! % phi(mod) md�����������ӽ�water�˰ɡ� 
T4�������Ѷȵġ�
�������ֻ���� 40 pts�����аɡ�
���� 1 h 40 min ���ǰ��ġ� 
*/ 
