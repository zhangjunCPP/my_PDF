#include<bits/stdc++.h>
using namespace std;
const int N = 7e5 + 5;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
}

int a[N], b[N];
int n, ans;

void bf(int l, int r) {
	if(l >= r) return ;
	int pos = (r - l + 1 + 1) / 2;
	int pivot = l + pos - 1;
	
	int L = l, R = r;
	for(int i = l; i <= r; ++ i) {
		++ ans;
		if(a[i] < a[pivot]) b[L ++] = a[i];
		if(a[i] > a[pivot]) b[R --] = a[i];
	}
	a[R] = a[pivot];
	for(int i = l; i < L; ++ i) a[i] = b[i];
	for(int i = R + 1; i <= r; ++ i) a[i] = b[i];
	reverse(a + R + 1, a + r + 1);
	
	bf(l, L - 1), bf(R + 1, r);
}
void BF() {
	bf(1, n);
	printf("%d\n", ans);
}
bool ALLEQ() {
	for(int i = 1; i <= n; ++ i)
		if(a[i] != i) return false;
	return true;
}

signed main() {
//	freopen("sort3.in", "r", stdin);
//	freopen("data2.in", "r", stdin);
	file();
	n = read();
	for(int i = 1; i <= n; ++ i)
		a[i] = read();
	
	if(n <= 3e3) return BF(), 0;
	if(ALLEQ()) return printf("%d\n", 2 * n - 1), 0;
	return 0; 
} 
