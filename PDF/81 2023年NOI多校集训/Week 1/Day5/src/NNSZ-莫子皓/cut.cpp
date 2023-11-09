/*
如果判断无误的话，就是纯搜索，从头找到尾，如果出现找过的就切
因为就算它还在这一段也对mex没有贡献
但是总感觉怪怪的
思考一下反例 
暂时想不到，还是先这么写了吧
找到反例了
8
3 3 2 2 1 1 0 0
理应是
5 2
1 8
但实际输出为 
3 5
1 2 4 6 8
因为单纯的判重会漏掉这种重复的数列
暂时放置去写t1了 
尝试实现了这种，还是放弃了，拿个差不多50'也不是不行 
*/
#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,ans,tmp;
int c[N],k=1;
bool s[N],vis[25],flag;
int Find()
{
	for(int i=0;i<=20;i++){
		if(vis[i]==false)
			return i;
	}
	return 21;
}
void solve()
{
	for(int i=2;i<=n;i++){
		flag=false;
		if(vis[c[i]]==true){
			s[i]=true;
			++k;
			ans+=Find();
			memset(vis,false,sizeof(vis));
			vis[c[i]]=true;
			continue;
		}
		vis[c[i]]=true;
	}
}
int main()
{
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	s[1]=true;
	vis[c[1]]=true;
	solve();
	ans+=Find();
	printf("%d %d\n",ans,k);
	for(int i=1;i<=n;i++){
		if(s[i]==true) printf("%d ",i);
	}
	return 0;
}
