#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, cmpcnt;
vector <ll> s;

vector <ll> Sort (vector <ll> a) {
	if (a.size () <= 1)
		return a;
	ll pivot = a[ceil ((a.size () - 1) / 2)];
	vector <ll> al, ag;
	for (ll i = 0; i < a.size (); ++i) {
		++cmpcnt;
		if (a[i] < pivot)
			al.push_back (a[i]);
		if (a[i] > pivot)
			ag.push_back (a[i]);
	}
	al = Sort (al), ag = Sort (ag);
	for (ll i = 0; i < al.size (); ++i)
		a[i] = al[i];
	a[al.size ()] = pivot;
	for (ll i = 0; i < ag.size (); ++i)
		a[i + al.size () + 1] = ag[i]; 
	return a;
}

int main () {
	freopen ("sort.in", "r", stdin);
	freopen ("sort.out", "w", stdout);
	scanf ("%lld", &n);
	for (ll i = 1, x; i <= n; ++i) {
		scanf ("%lld", &x);
		s.push_back (x);
	}
	s = Sort (s);
	printf ("%lld\n", cmpcnt);
	return 0;
} 
