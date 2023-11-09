#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w; 
} 
void file() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
}

int p, k, n;

signed main() {
	file();
	p = read(), k = read(), n = 1;
	for(int i = 1; i <= k; ++ i) n *= p;
	
	if(k == 1) {
		printf("%d\n", 1);
		for(int i = 0; i < n; ++ i)
			printf("%d ", i);
		return 0;
	}
	if(p == 2) {
		printf("%d\n", n * (n - 1) / 2);
		for(int i = 0; i < n; ++ i)
			for(int j = i + 1; j < n; ++ j)
				printf("%d %d\n", i, j);
		return 0;
	}
	
	puts("GG");
	return 0; 
}
