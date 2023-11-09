#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0){x=~(x-1);putchar('-');}if(x>9)write(x/10);putchar(x%10+'0');}
#define put() putchar(' ')
#define endl puts("")

int f[5];

void solve(){
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	int x = read(), mod = read();
	int pre = 1;
	int ans = 0;
	for(int i = 3; i <= x; i++){
		f[i % 3] = (f[(i - 2) % 3] * (i - 1) % mod + f[(i - 1) % 3]) % mod + ((i - 1) * (i - 2) / 2) % mod * pre % mod;
		pre *= i - 1;
		pre %= mod;
		f[i % 3] %= mod;
		ans ^= f[i % 3];
	}
	write(ans), endl;
}

signed main(){
	int t = 1;
	while(t--)	solve();
	return 0;
}