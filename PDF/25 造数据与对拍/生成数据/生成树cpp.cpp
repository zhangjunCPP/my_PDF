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
//生成 n 个点的树，用n个节点n-1条边的无向图的形式输出，每条边附带一个size以内的正整数权值 
int main()
{
    srand((unsigned)time(0));
    ll size;
    
    for(int i=2;i<=n;i++){
    	//从2-n之间每个点i向1~i-1之间的点随机连边
		int fa=random(i-1)+1;
		int val=random(size)+1; 
		printf("%d %d %d\n",fa,i,val); 
	} 
    return 0;
}

