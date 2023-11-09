//维护的一个单调栈,所以击败的人是前缀最大值的个数
//贪心的我让大的尽可能拿到多的击败数(毕竟总击败数=n-1)
//首先v第一大的会把i比他小的全击败
//v第二大的:1.在v第一大后面,跳过;2.前面,也是尽可能多拿
//还是DP吧:
//       长x 
//       |
//a b ........ k
//价值为:bx+a
//dpi=max(ai-1 + (k-i)ai);
//等等哈,一定是这样吃有序的吗?
//应该是吃v小的才对吧
//如果吃掉了前x小,那么???
//如果1的v最大,那么肯定让1吃完
//否则,如果2的v最大,应让2吃完后面的再让1吃2
//否则,如果3的v最大,应让3吃完后面的再看v1,v2:v1>v2应该让v1吃了2,3,否则按序吃掉
//否则,如果4的v最大,应让4吃完后面的再看
//不对啊这不是和一开始想的策略一样吗???
//刚才就是没想好搞法...其实让要被吃的在底下待一待就可以
#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
int n,a[200010],b[200010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=i;
	ll ans=0;
	deque<int>res;
	sort(b+1,b+n+1,[](int x,int y){return a[x]>a[y];});
	for(int i=1,las=n+1;i<=n;i++)
	if(b[i]<las){
		int p=b[i];
		ans+=(min(las,n)-p)*1ll*a[p];
		for(int j=las-1;j>p;j--)res.push_front(j);
		res.push_back(p),las=p;
	}cout<<ans<<endl;
	for(int x:res)printf("%d ",x);
	return 0;
}
