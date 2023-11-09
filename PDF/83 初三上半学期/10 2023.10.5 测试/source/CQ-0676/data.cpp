#include <bits/stdc++.h>

using namespace std;

mt19937 rng(time(0));

int rd(int x) {
	return rng()%x+1;
}

void A() {
	int n=rd(10);
	cout<<n<<'\n';
	for (int i=1; i<=n; i++) {
		while (1) {	
			int x=rd(n), y=i, z=rd(n);
			if (x>z) swap(x, z);
			if (x>y) continue;
			if (y>z) continue;
			if (max(y-x, z-y)<=7) {
				cout<<x<<" "<<y<<" "<<1<<'\n'; 
				break;
			}
		}
	}
}

int main() {
	A();
	return 0;
}
