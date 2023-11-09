#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 __int128
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
const int N = 7e5+77;
int n,a[N],b[N],al[N],ar[N];
ll ans;
void MergeSort(int l,int r){
	if(r-l+1<=1) return ;
	int mid = l+(r-l+1+1)/2-1,nl = 0,nr = 0;
	ans += (r-l+1);
	for(int i=l;i<=r;i++){
		if(a[i]<a[mid]) al[++nl] = a[i];
		if(a[i]>a[mid]) ar[++nr] = a[i];
	}
	for(int i=l;i<=l+nl-1;i++) a[i] = al[i-l+1];
	for(int i=l+nl;i<=l+nl+nr-1;i++) a[i] = ar[i-l-nl+1];
	MergeSort(l,l+nl-1),MergeSort(l+nl,l+nl+nr-1); 
	return ;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	MergeSort(1,n);
	cout << ans;
	return 0;
}

