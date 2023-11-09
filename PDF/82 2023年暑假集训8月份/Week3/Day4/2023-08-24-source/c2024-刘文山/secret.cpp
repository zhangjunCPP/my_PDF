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
出题人今天心情挺好的呀。
暴力分给这么高？
13 全排列
10 直接计算 n! 
模数 65535 有点小奇怪。
是 256^2 -1 ，有点高级。
考虑一个256进制数，相当于每一位的系数是。
1 256 1 256 1 256 挺 iteresting 的。
这应该是留给 27 分的，用于对每个数划分集合，系数要么是 1 要么是 256。
现在还有 2h，学习FF同学直接冲正解。
这次考试感觉简单点。
前面 3 题，如果不挂分是 100+100+60。
T4 再打 50 ，其实页挺高的了，现在有两个选择：
1.打了50去检查前面的，保证不挂分。
2.直接冲 T3 或 T4 正解。
鉴于我比较保守，所以果断选择第 1 项（wtcl）。
T3 T4 正解就先放一放吗？毕竟正解挂分很痛的。 
MMSD，我发现 y=1e9 求解很恶心耶。
就算降次，也要求 y! % phi(mod) md，出题人脑子进water了吧。 
T4还是有难度的。
所以最后只打了 40 pts，还行吧。
还有 1 h 40 min 检查前面的。 
*/ 
