#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(i) i&(-i)
#define i64 __int128
const ll N = 2e5+7,P = 13331;
ll n,h[N],pw[N],ans[N];
char s[N];
ll f(int l,int r){
	return h[r]-h[l-1]*pw[r-l+1]; 
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> s+1;
	n = strlen(s+1);
	pw[0] = 1;
	for(int i=1;i<=n;i++) h[i] = h[i-1]*P+(s[i]-'a'),pw[i] = pw[i-1]*P;
	for(int i=n;i>=1;i--){
		ll v1,v2,v3,len;
		v1 = f(i,n),len = n-i+1;
		for(int j=i-2;j>=1;j--){
			if(j-2*len+1<1) break; 
			v2 = f(j-len+1,j);
			v3 = f(j-2*len+1,j-len);
			if(v1==v2 && v2==v3) ans[j-2*len+1]++;
		}
	}
	for(int i=1;i<=n;i++) cout << ans[i] << ' ';
	return 0;
}

