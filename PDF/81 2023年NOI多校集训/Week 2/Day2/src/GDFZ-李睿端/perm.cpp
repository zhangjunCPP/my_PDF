#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
int read(){
	int ret=0,f=1;char c=getchar();
	while(c>57||c<48){if(c=='-')f= -1;c=getchar();}
	while(c<=57&&c>=48)ret=(ret<<3)+(ret<<1)+(c-48),c=getchar();
	return ret*f;
}
void write(int x){
	if(x<0) x= -x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int maxn=1e7+5;
int mod;
int n,m,q,jc[maxn],f[maxn],ans;
void solve(){
	n=read(),mod=read();
	jc[2]=1;
	for(int i=3;i<=n;i++)jc[i]=jc[i-1]*i%mod;
	for(int i=3;i<=n;i++){
		f[i]=((f[i-1]+f[i-2]*(i-1)%mod+jc[i])%mod+mod-jc[i-1]*2%mod)%mod;
		ans^=f[i];
	}
	write(ans);
}
signed main(){
    int t=1;
    while(t--)solve();
    return 0;
}
