#include <bits/stdc++.h>
using namespace std;
ll random(ll mod)
{
    ll n1, n2, n3, n4, ans;
    n1 = rand();
    n2 = rand();
    n3 = rand();
    n4 = rand();
    ans = n1 * n2 % mod;
    ans = ans * n3 % mod;
    ans = ans * n4 % mod;
    return ans;
}
//生成一张n个点m条边的无向图，不存在重边、自环，且必须连通，保证 5<=n<=m<=n*(n-1)/4<=10^6 
int main()
{
	srand((unsigned)time(0));
	pair< int ,int > e[1000005]; //保存数据 
	map<pair<int ,int>,bool> h; //避免重边 
    
    //先生成一棵树，保证连通 
    for(int i=1;i<=n;i++){
    	int fa=random(i)+1;
    	e[i]=make_pair(fa,i+1);
    	h[e[i]]=h[make_pair(i+1,fa)]=1;	
	}
	//再生成剩下的m-n+1条边 
	for(int i=n;i<=m;i++)
	{
		int x,yl
		do{
			x=random(n)+1;
			y=random(n)+1;
		}while(x==y||h[make_pair(x,y)]);
		e[i]=make_pair(x,y);
		h[e[i]]=h[make_pair(y,x]=1;
	} 
	//随机打乱，输出 
	random_shuffle(e+1,e+m+1);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",e[i].first,e[i].second);
	
    return 0;
}

