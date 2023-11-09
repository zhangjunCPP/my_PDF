#include<bits/stdc++.h>
#define int long long
using namespace std;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
}

const int N = 3e2;

int ans[N];
int T, n;

signed main() {
//	freopen("count1.in", "r", stdin);
//	freopen("data2.in", "r", stdin);
	file();
	
	T = read();
	while(T --) {
		n = read();
		
		if(n <= 1e3) {
			int cnt = 0;
			for(int a = 1; a <= n; ++ a)
			for(int b = 1; b <= n; ++ b)
			for(int c = 1; c <= n; ++ c) {
				if(a * b % c) continue;
				int d = a * b / c;
				if(1 <= d && d <= n) ++ cnt; 
			}
			cout << cnt << endl;
		}
	}
	return 0; 
} 
