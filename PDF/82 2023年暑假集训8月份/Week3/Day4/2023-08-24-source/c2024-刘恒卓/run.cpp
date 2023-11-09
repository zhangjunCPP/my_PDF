#include<bits/stdc++.h>
using ll = long long;
const int N = 1e6 + 10;
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ll p, s;
	scanf("%lld%lld", &p, &s);
	if (p & 1) {
		printf("Impossible\n");
		return 0;
	} 
	if (s < p / 2 - 1) {
		printf("Impossible\n");
		return 0;
	}
	p /= 2;
	ll a = p / 2, b = p - a;
	if (s > a * b) {
		printf("Impossible\n");
		return 0;
	}
	ll x = a * b - s;
	ll u = x / (b - 1), v = x % (b - 1);
	if (u == 0 && v == 0) {
		for (int i = 1; i <= b; printf("2"), i++);
		printf("3");
		for (int i = 2; i <= a; printf("2"), i++);
	} else if (v == 0) {
		printf("23");
		for (int i = 1; i < u; printf("2"), i++);
		printf("1");
		for (int i = 3; i <= b; printf("2"), i++);
		printf("3");
		for (int i = 1; i < a - u; printf("2"), i++);
	} else if (u == 0) {
		for (int i = 1; i <= b - v; printf("2"), i++);
		printf("31");
		for (int i = 1; i < v; printf("2"), i++);
		printf("3");
		for (int i = 3; i <= a; printf("2"), i++);
	} else {
		printf("23");
		for (int i = 1; i < u; printf("2"), i++);
		printf("1");
		for (int i = 1; i < b - 1 - v; printf("2"), i++);
		printf("31");
		for (int i = 1; i < v; printf("2"), i++);
		printf("3");
		for (int i = 1; i < a - 1 - u; printf("2"), i++);
	}
	printf("3");
	for (int i = 2; i <= b; printf("2"), i++);
	printf("3");
	for (int i = 2; i <= a; printf("2"), i++);
	return 0;
}

