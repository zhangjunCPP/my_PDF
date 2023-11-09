/*
T2 chameleon
这狗题还卡空间
我们考虑把东西读入之后，向左的相当于不变
考虑从最左边那个开始，找到向右的，加上贡献
遇到向左的，那么操作一手，结算贡献
遇到向右的，放入颜色贡献，继续操作
结束游戏，时间复杂度排序nlogn+操作nk
实现的时候我们稍微改动一下，把往左的固定不动，只考虑往右的
那么在向右走的时候，每个时刻会走两步，最后的答案要/2
需要注意理解上的难点：变色龙虽然同时计算贡献，但是它们是在不同的时间线上的！
还有很多的细节，比如最后一段路的长度需要单独计算
好似，我把左右看反了，不过问题不大（呵呵）
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=100010;
struct chameleon
{
	int d,b;
	char f;
	bool operator < (const chameleon &oth){return d<oth.d;}//从左到右排序
}c[N];
ll col[50],ans[50],tmp[50];
int n,k,L;
inline void upd(int u)
{
	for(int i=0;i<k;i++)ans[i]+=col[i]*(c[u-1].d-c[u].d);
	return;
}
int main()
{
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k>>L;
	for(int i=1;i<=n;i++)cin>>c[i].d>>c[i].b>>c[i].f;
	sort(c+1,c+n+1);reverse(c+1,c+n+1);
	for(int i=1;i<=n;i++)
	{
		upd(i);
		if(c[i].f=='L')col[c[i].b]++;
		if(c[i].f=='D')
		{
			ans[c[i].b]+=(L-c[i].d)*2;//直接给到全部
			for(int j=0;j<k;j++)tmp[(j+c[i].b)%k]=col[j];
			memcpy(col,tmp,sizeof col);//操作一手
		}
	}
	int delta=0;//偏移，用以计算最终颜色
	for(int i=n;i;i--)
	{
		if(c[i].f=='L')ans[(c[i].b+delta)%k]+=(c[n].d+c[i].d);
		if(c[i].f=='D')delta=(delta+c[i].b)%k;
	}
	for(int i=0;i<k;i++)cout<<ans[i]/2<<((ans[i]&1)?".5\n":".0\n");
	return 0;
}