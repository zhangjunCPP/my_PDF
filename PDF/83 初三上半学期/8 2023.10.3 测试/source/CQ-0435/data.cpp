#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

mt19937 rng(time(0));

int rd(int x) {
	return rng()%x+1;
}

void B() {
	int n=rd(15), V=rd(5)!=1? 30+rd(70): rd(20);
//	V=1e9;
//	if (n%2==0) n++;
	cout<<n<<'\n';
	for (int i=1; i<=n; i++) {
		cout<<rd(V)<<' ';
	}
}

int main() {
//	freopen("data.in", "w", stdout);
	srand(time(0));
	B();
	return 0;
}
/*

*/
