#include<bits/stdc++.h>
using namespace std;
int a[6], b[6];
int main() {
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	if (n == 1) {
		printf("Yes\n");
		for (int i = 1; i <= 6; i++) {
			printf("%d ", k * i);
		}
		return 0;
	}
	if (k == 30 || k == 31 || k == 45 || k == 51 || k == 60) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (int i = 1; i <= n; i++) {
		switch (k) {
			case 2 : {
				printf("0 2 4 8 16 32\n");
				break;
			}
			case 3 : {
				printf("0 3 12 48 192 768\n");
				break;
			}
			case 4 : {
				printf("0 4 8 16 32 64\n");
				break;
			}
			case 5 : {
				printf("0 5 10 80 160 1280\n");
				break;
			}
			case 6 : {
				printf("0 6 24 96 384 1536\n");
				break;
			}
			case 7 : {
				printf("0 7 56 448 3584 28672\n");
				break;
			}
			case 8 : {
				printf("0 8 16 32 64 128\n");
				break;
			}
			case 9 : {
				printf("0 9 18 36 576 1152\n");
				break;
			}
			case 10 : {
				printf("0 10 20 160 320 2560\n");
				break;
			}
			case 11 : {
				printf("0 11 132 352 528 11264\n");
				break;
			}
			case 12 : {
				printf("0 12 48 192 768 3072\n");
				break;
			}
			case 13 : {
				printf("0 13 130 624 3328 53248\n");
				break;
			}
			case 14 : {
				printf("0 14 112 896 7168 57344\n");
				break;
			}
			case 15 : {
				printf("0 15 240 3840 61440 983040\n");
				break;
			}
			case 16 : {
				printf("0 16 32 64 128 256\n");
				break;
			}
			case 17 : {
				printf("0 17 34 68 136 4352\n");
				break;
			}
			case 18 : {
				printf("0 18 36 72 1152 2304\n");
				break;
			}
			case 19 : {
				printf("0 19 76 1824 26752 233472\n");
				break;
			}
			case 20 : {
				printf("0 20 40 320 640 5120\n");
				break;
			}
			case 21 : {
				printf("0 21 42 1344 2688 86016\n");
				break;
			}
			case 22 : {
				printf("0 22 264 704 1056 22528\n");
				break;
			}
			case 23 : {
				printf("0 23 552 1472 141312 282624\n");
				break;
			}
			case 24 : {
				printf("0 24 96 384 1536 6144\n");
				break;
			}
			case 25 : {
				printf("0 25 100 2050 9600 102400\n");
				break;
			}
			case 26 : {
				printf("0 26 260 1248 6656 106496\n");
				break;
			}
			case 27 : {
				printf("0 27 324 2592 38016 221184\n");
				break;
			}
			case 28 : {
				printf("0 28 224 1792 14336 114688\n");
				break;
			}
			case 29 : {
				printf("0 29 290 9280 18560 430592\n");
				break;
			}
			case 32 : {
				printf("0 32 64 128 256 512\n");
				break;
			}
			case 33 : {
				printf("0 33 66 132 264 528\n");
				break;
			}
			case 34 : {
				printf("0 34 68 136 272 8704\n");
				break;
			}
			case 35 : {
				printf("0 35 140 3920 143360 573440\n");
				break;
			}
			case 36 : {
				printf("0 36 72 144 2304 4608\n");
				break;
			}
			case 37 : {
				printf("0 37 74 2960 37888 606208\n");
				break;
			}
			case 38 : {
				printf("0 38 152 3648 53504 466944\n");
				break;
			}
			case 39 : {
				printf("0 39 2184 4368 17472 139776\n");
				break;
			}
			case 40 : {
				printf("0 40 80 640 1280 10240\n");
				break;
			}
			case 41 : {
				printf("0 41 82 4100 10496 131200\n");
				break;
			}
			case 42 : {
				printf("0 42 84 2688 5376 172032\n");
				break;
			}
			case 43 : {
				printf("0 43 516 2064 5504 8256\n");
				break;
			}
			case 44 : {
				printf("0 44 528 1408 2112 45056\n");
				break;
			}
			case 46 : {
				printf("0 46 1104 2944 282624 565248\n");
				break;
			}
			case 47 : {
				printf("0 47 8272 66176 132352 577536\n");
				break;
			}
			case 48 : {
				printf("0 48 192 768 3072 12288\n");
				break;
			}
			case 49 : {
				printf("0 49 196 2058 12544 50176\n");
				break;
			}
			case 50 : {
				printf("0 50 200 4100 19200 204800\n");
				break;
			}
			case 52 : {
				printf("0 52 520 2496 13312 212992\n");
				break;
			}
			case 53 : {
				printf("0 53 2120 13568 196736 786944\n");
				break;
			}
			case 54 : {
				printf("0 54 648 5184 76032 442368\n");
				break;
			}
			case 55 : {
				printf("0 55 3080 21120 98560 925760\n");
				break;
			}
			case 56 : {
				printf("0 56 448 3584 28672 229376\n");
				break;
			}
			case 57 : {
				printf("0 57 1026 2052 25536 233472\n");
				break;
			}
			case 58 : {
				printf("0 58 580 18560 37120 861184\n");
				break;
			}
			case 59 : {
				printf("0 59 8260 181248 264320 528640\n");
				break;
			}
		}
	}
	return 0;
}
