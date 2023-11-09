#include <bits/stdc++.h>

using namespace std;

int T=5000;

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
