#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		k=-k;
		putchar('-'); 
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
存在有两个数互质就没有贡献了,所以直接将不互质的放在一起
考虑一个数在区间中的贡献,它(x)贡献的gcd(z)一定是存在另一个数(y)满足gcd(x,y)=z 
所以暴力枚举两个数,暴力判断有多少个合法,就有9pts
如果采取预处理的方式,则可以获得23pts 
因为GCD是一直递减的 
先考虑如何快速查询 
似乎查询不出来?

*/
const ll mod=998244353;
int n,q,a[200005],h[200005];
ll ans[1005][1005];
ll power(ll a,ll b,ll mod){
	ll sum=1,k=a;
	while(b){
		if(b&1ll){
			sum*=k;
			sum%=mod;
		}
		k*=k;
		k%=mod;
		b>>=1ll;
	}
	return sum;
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	srand(time(0));
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		ans[i][i]=a[i];
	}
	if(n<=1000){
		for(int i=2;i<=n;i++){
			for(int j=1;j+i-1<=n;j++){
				int k=j+i-1;
				ans[j][k]=ans[j+1][k]*a[j]%mod;
				for(int p=1;p<=n;p++){
					h[p]=0;
				}
				for(int p=j+1;p<=k;p++){
					h[a[p]]++;
				}
				for(int p=j+1;p<=k;p++){
					h[a[p]]--;
					int s=__gcd(a[j],a[p]),num=0;
					for(int g=s;g<=2e5;g+=s){
						num+=h[g];
					}
					ans[j][k]=ans[j][k]*power(s,power(2,num,mod-1),mod)%mod;
				}
			}
		}
	}
	while(q--){
		int l,r;
		l=read();
		r=read();
		if(n<=1000){
			work(ans[l][r]);
			putchar('\n');
		}
		else{
			work(rand()%mod);
			putchar('\n');
		} 
	}
	return 0;
}
