/*
һ����Ϊ2�Ķο�������ƽ��.ƽ�ƾ���һ����1ʱЧ���൱������θ���ȥ,1��Ȼ����2��
��2�Ķο��Կ����ǳ������ļ�����
��0�Ķ�Ҳ���Ժ͵�1һ������
�����ȿ��ؼ�����һ��,problem is like this:
11 11 11 11 1
11 11 11 1 11
11 11 1 11 11
11 1 11 11 11
1 11 11 11 11
����5��! 
����Ļ���㼴��.x
ʵ���ϰ�2��0��һ�¼���.1�����������ܲ���
����DP...��Ȼ״̬������,���ǻ�ը�ռ�... 
Ȼ���Ǵ�:�����п��ܵľ�����sum(C(n-c1-c2,c0)).
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
