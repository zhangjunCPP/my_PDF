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
//生成m个[1，n]的子区间，这些区间可以作为操作区间 
int main()
{
    srand((unsigned)time(0));
    ll n,m;
    //n,m的数据可以随机 
    for(int i = 1 ; i<=m;i++){
    	int l=random(n) + 1 ;
    	int r=random(n) + 1 ;
    	if(l>r) swap(l,r);
    	printf("%d %d\n",l,r);
	}
    return 0;
}

