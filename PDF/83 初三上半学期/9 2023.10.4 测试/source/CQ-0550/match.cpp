#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

const int N=2e5+3;
int k;
char s[N], p[N];

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	k=read();
	scanf("%s", s+1);
	int Q=read(), n=strlen(s+1);
	while (Q--) {
		scanf("%s", p+1);
		int len=strlen(p+1), ans=0;
		if (len>n) {
			puts("0"); continue;
		}
		for (int ed=len; ed<=n; ed++) {
			int mi=len+1, mx=0;
			for (int i=ed-len+1, j=1; i<=ed; i++, j++) {
				if (s[i]!=p[j]) mi=min(mi, j), mx=max(mx, j);
			}
			if (mx-mi<k) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
