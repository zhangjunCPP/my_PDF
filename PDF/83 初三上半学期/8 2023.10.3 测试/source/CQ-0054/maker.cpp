#include<bits/stdc++.h>
using namespace std;



signed main() {
	srand(time(0));
	mt19937 rnd(rand());
	
	int n = 18;
	printf("%d\n", n);
	for(int i = 1; i <= n; ++ i)
		printf("%d ", rnd() % 20 + 1);
	
	return 0;
}
