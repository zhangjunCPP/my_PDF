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

int vis[10000];

void B() {
	int k=rd(10), n=rd(10);
	int L=rd(20);
	while (L<n) L=rd(20);
	cout<<n<<" "<<k<<" "<<L<<'\n';
	for (int i=1; i<=n; i++) {
		int x=rd(L+1)-1;
		while (vis[x]) x=rd(L+1)-1;
		cout<<x<<" "<<rd(k)-1<<" "<<(rd(2)==1?'D':'L')<<'\n';
		vis[x]=1;
	}
}

int main() {
	B();
	return 0;
}
