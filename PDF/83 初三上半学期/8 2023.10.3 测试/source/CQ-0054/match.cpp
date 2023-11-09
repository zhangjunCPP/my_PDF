#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;

char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
}

struct Item {
	int l, r;
} a[N];
int ans[N];
int n, m;


signed main() {
//	freopen("ex_match1.in", "r", stdin);
	file();
	n = read(), m = read();
	if(n == 1) {
		int k = read();	
		for(int j = 1, p; j <= k; ++ j)
			p = read(), ans[p] = 1;
		for(int i = m; i >= 1; -- i)
			printf("%d", ans[i]);
		return 0;
	}
	if(n == 2) {
		bitset<N> B1, B2, A, U, ANS1, ANS2, TMP;
		int k = read();
		for(int j = 1, p; j <= k; ++ j)
			p = read(), B1.set(p);
		k = read();
		for(int j = 1, p; j <= k; ++ j)
			p = read(), B2.set(p);
			
		A = B1 & B2;
		U = B1 | B2;
		if(!A.any()) ANS1 = ANS2 = U;
		else {
			int pos = m;
			for(; pos >= 1; -- pos) if(A[pos]) break;
			if(pos == m) return puts("-1"), 0;
			if(!B1[pos + 1]) {
				TMP = B1;
				for(int i = 1; i <= pos; ++ i)
					TMP[i] = 0;
				TMP[pos + 1] = 1;
				ANS1 = ANS2 = TMP | B2;
			} else if(!B2[pos + 1]) {
				TMP = B2;
				for(int i = 1; i <= pos; ++ i)
					TMP[i] = 0;
				TMP[pos + 1] = 1;
				ANS1 = ANS2 = B1 | TMP;
			} else {
				TMP = B1;
				for(int i = 1; i <= pos; ++ i)
					TMP[i] = 0;
				TMP[pos + 1] = 1;
				ANS1 = TMP | B2;
				
				TMP = B2;
				for(int i = 1; i <= pos; ++ i)
					TMP[i] = 0;
				TMP[pos + 1] = 1;
				ANS2 = B1 | TMP;
			}				
		}
		
		if(ANS1 == ANS2) {
			for(int i = m; i >= 1; -- i)
				cout << ANS1[i];
		} else {
			int op = 0;
			for(int i = m; i >= 1; -- i)
				if(op == 0) {
					if(ANS1[i] == ANS2[i]) cout << ANS1[i];
					else if(ANS1[i] < ANS2[i]) op = 1, cout << ANS1[i];
					else op = 2, cout << ANS2[i];
				} else if(op == 1) cout << ANS1[i];
				else cout << ANS2[i];
		}
	}

	
	return 0;
}
