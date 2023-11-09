#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

int p, k, n=1;

int main() {
	p=read(), k=read();
	for (int i=1; i<=k; i++) n*=p;
	if (k==1) {
		puts("1");
		for (int i=0; i<n; i++) printf("%d ", i);
		return 0;
	}
	if (p==2) {
		printf("%d\n", n*(n-1)/2);
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++) printf("%d %d\n", i, j);
		return 0;
	}
	if (k==2) {
		for (int i=0; i<n; i+=p) {
			for (int j=0; j<p; j++) {
				printf("%d ", i+j);
			}
			puts("");
		}
		for (int i=0; i<p; i++) {
			for (int j=0; j<n; j+=p) {
				printf("%d ", i+j);
			}
			puts("");
		}
		for (int i=0; i<p; i++) {
			int now=i;
			for (int j=0; j<n; j+=p, now=(now+1)%p) {
				printf("%d ", j+now);
			}
			puts("");
		}
	}
	return 0;
}
