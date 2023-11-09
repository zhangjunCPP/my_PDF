#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define fi first
#define se second
#define pb push_back
#define pii pair<LL,LL>
#define mem(a,x) memset((a),(x),sizeof(a))

//#define long long int
#define LLL __int128

template<typename type>
inline void read(type &x)
{
    x=0;bool flag(0);char ch=getchar();
    while(!isdigit(ch)) flag=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    flag?x=-x:0;
}

template<typename type>
inline void write(type x,bool mode=1)//0为空格，1为换行
{
    x<0?x=-x,putchar('-'):0;static short Stack[50],top(0);
    do Stack[++top]=x%10,x/=10; while(x);
    while(top) putchar(Stack[top--]|48);
    mode?putchar('\n'):putchar(' ');
}

LL qsm(LL a,LL b,LL mod){
	LL ans=1,sum=a;
	while(b){
		if(b&1) ans=1ll*ans*sum%mod;
		sum=1ll*sum*sum%mod;
		b>>=1;
	}
	return ans;
}

const LL N=1e7+10;

LL n,mod,f[N],inv[N],pre[N];

LL C(LL a,LL b){
	if(a<b||a<0||b<0) return 0;
	return 1ll*pre[a]*inv[b]%mod*inv[a-b]%mod;
}

LL s[N];

void solve2();

void solve(){
	read(n);
	read(mod);
	if(n<=10){
		solve2();
		return ;
	}
	s[0]=1;
	s[1]=1;
	for(LL i=2;i<=n;i++) s[i]=(s[i-1]+(i-1)*s[i-2]%mod)%mod;
	inv[0]=pre[0]=1;
	for(LL i=1;i<N;i++){
		pre[i]=1ll*pre[i-1]*i%mod;
	}
	inv[N-1]=qsm(pre[N-1],mod-2,mod);
	for(LL i=N-2;i>=1;i--){
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
	}
	for(LL i=5;i<=n;i++){
		for(LL x=1;x<i;x++){
			for(LL fuck=0;fuck<=min(x-1,i-x-1);fuck++){
				f[i]=(f[i]+s[x-1-fuck]*C(i-x,fuck)%mod*C(i-x-fuck,2)%mod*pre[i-x-fuck-1]%mod)%mod;
			}
		}
	}
	for(LL i=1;i<=n;i++){
		printf("f[%lld]=%lld\n",i,f[i]);
	}
	LL ans=0;
	for(LL i=1;i<=n;i++) ans^=f[i];
	printf("%lld\n",ans);
}

void solve2(){
	f[1]=f[2]=0;
	f[3]=1;
	f[4]=7;
	f[5]=47;
	f[6]=322;
	f[7]=2404;
	f[8]=19778;
	f[9]=180130;
	f[10]=1809652;
	LL ans=0;
	for(LL i=1;i<=n;i++) ans^=f[i];
	printf("%lld\n",ans%mod);
}

int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	
	LL T;
	T=1;
	while(T--){
		solve();
	}
}

