/*
一个长为2的段可以任意平移.平移经过一个单1时效果相当于这个段浮上去,1自然下落2格
而2的段可以看作非常单独的几个段
而0的段也可以和单1一样看待
于是先可重集排列一下,problem is like this:
11 11 11 11 1
11 11 11 1 11
11 11 1 11 11
11 1 11 11 11
1 11 11 11 11
会算5遍! 
解决的话随便即可.x
实际上把2和0排一下即可.1可以让它智能插入
暴力DP...虽然状态数不多,但是会炸空间... 
然后考虑答案:对所有可能的局面算sum(C(n-c1-c2,c0)).
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
int n;
char str[510];
ll C[510][510],las[510][510][2],now[510][510][2];
auto forsta=[](const auto&f){
	for(int c1=0;c1<=n;c1++)
	for(int c2=0;c2*2+(c1?c1*2-1:0)<=n;c2++)
	f(c1,c2);
};
int main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	scanf("%d%s",&n,str+1);str[n+1]='0';
	for(int i=0;i<=n;i++)
	for(int j=0;j<=i;j++)
	C[i][j]=j?(C[i-1][j]+C[i-1][j-1])%mod:1;
	las[0][0][0]=1;
	for(int i=1;i<=n+1;i++){
		if(str[i]!='1')
		forsta([](int c1,int c2){
		(now[c1][c2][0]+=las[c1][c2][0])%=mod,
		(now[c1+1][c2][0]+=las[c1][c2][1])%=mod;});
		if(str[i]!='0')
		forsta([](int c1,int c2){
		(now[c1][c2+1][0]+=las[c1][c2][1])%=mod,
		(now[c1][c2][1]+=las[c1][c2][0])%=mod;});
		forsta([](int c1,int c2){
		las[c1][c2][0]=now[c1][c2][0],now[c1][c2][0]=0;
		las[c1][c2][1]=now[c1][c2][1],now[c1][c2][1]=0;});
	}ll ans=0;
	forsta([&ans](int c1,int c2){(ans+=las[c1][c2][0]*C[n-c1-c2][c2])%=mod;});
	cout<<ans;
	return 0;
}
