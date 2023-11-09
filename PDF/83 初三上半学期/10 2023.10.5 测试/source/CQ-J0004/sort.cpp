#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a[700005],n,ans,num[700005],num2[700005],cn1,cn2,cn3;
void f(int l,int r){
	if (l >= r) return;
	int t = a[l+r>>1],cn1 = cn2 = 0,cn3 = l;
	for (register int i = l;i <= r;i++){
		ans++;
		if (a[i] < t) num[++cn1] = a[i];
		if (a[i] > t) num2[++cn2] = a[i];
	}
	for (register int i = 1;i <= cn1;i++) a[cn3++] = num[i];
	int l1 = l,r1 = cn3-1;
	a[cn3++] = t,l = cn3;
	for (register int i = 1;i <= cn2;i++) a[cn3++] = num2[i];
	f(l1,r1);
	f(l,cn3-1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//*
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	//*/
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	f(1,n);
	cout << ans;
	return 0;
}
