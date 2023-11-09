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
//生成 n 个绝对值在 size 以内的整数。 
int main()
{
    srand((unsigned)time(0));
    ll n_size,size;
    
    int n=random(n_size)+1; 
    for(int i=1;i<=n;i++){
    	a[i]=random(2*size+1)-size;
	}
    return 0;
}

