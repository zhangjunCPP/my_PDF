#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0; char ch=getchar();
	while (ch<'0') ch=getchar();
	while (ch>='0') x=x*10+ch-48, ch=getchar();
	return x;
}

int T=3000;

int main() {
	while (T--) {
		system("data.exe > data.in");
		system("my.exe < data.in > my.out");
		system("oth.exe < data.in > oth.out");
		if (system("fc my.out oth.out")) {
			break;
		}
	}	
	return 0;
}
/*
f[i][num][S] 表示序列填了 i 个数，第 num 块里面的状态为 S 

*/
