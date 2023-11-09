#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

int cnt, n;

void pai(vector<int> a) {
	if (a.size()<=1) return;
	int t=a[(a.size()-1)/2];
	vector<int> a1, a2;
	for (auto x:a) {
		cnt++;
		if (x<t) a1.push_back(x);
		if (x>t) a2.push_back(x);
	}
	pai(a1), pai(a2);
}
void solve1() {
	vector<int> a;
	for (int i=1; i<=n; i++) a.push_back(read());
	pai(a);
	cout<<cnt;
}

int main() {
	freopen("sort5.in", "r", stdin);
	n=read();
	if (n<=3000) solve1();
	return 0;
}

