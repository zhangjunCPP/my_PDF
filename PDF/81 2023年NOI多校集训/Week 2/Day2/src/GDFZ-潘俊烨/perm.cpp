#include<bits/stdc++.h>
#define int long long
#define _int __int128
#define y1 _
using namespace std;

static char buf[1000000],*p1=buf,*p2=buf;

inline int read(){
	char c=getchar();
	int res=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*f;
}

inline void write(int x){
	static char buf[20];
	static int len=-1;
	if(x<0){
		putchar('-');
		x=-x;
	}
	do{
		buf[++len]=x%10;
		x/=10;
	}
	while(x);
	while(len>=0){
		putchar(buf[len--]+48);
	}
}

const int maxn=10000050;
const int maxm=110;
//const int mod=1e9+7;
//const int inf=1e18;

int n;
int mod;

int a[maxn],b[maxn];

int dp[maxn];

int ans=0;
int ans114[maxn];
bool flag[maxn];


void dfs(int dep,int n){
	if(dep>n){
		bool flag=0;
		for(int i=1;i<=n;i++){
			b[ans114[i]]=i;
		}
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<" ";
//		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
			if(ans114[i]>b[i]){
				return ;
			}
			if(b[i]>ans114[i]){
				flag=1;
				break;
			}
		}
		if(flag==1){
//			cout<<"-------------------"<<endl;
//			for(int i=1;i<=n;i++){
//				cout<<ans114[i]<<" ";
//			}
//			cout<<endl;
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			ans114[dep]=i;
			flag[i]=1;
			dfs(dep+1,n);
			flag[i]=0;
		}
	}
}

int pre[maxn],pre1[maxn];

void init(){
	pre[0]=1;
	for(int i=1;i<=n+1;i++){
		pre[i]=(pre[i-1]*i)%mod;
		pre1[i]=(pre1[i-1]+i)%mod;
	}
}

void solve(){
	n=read(),mod=read();
	if(n==1||n==2){
		puts("0");
		return ;
	}
//	if(n<=6){
//		int cnt=0;
//		for(int i=1;i<=n;i++){
//			ans=0;
//			dfs(1,i);
//			cnt=cnt^ans;
//		}
//		write(cnt%mod);
//		puts("");
//		return ;
//	}
//	else{
//		int ans1=0;
		init();
		dp[1]=0;
		dp[2]=0;
		for(int i=3;i<=n;i++){
			dp[i]=(dp[i]+dp[i-1])%mod;
			dp[i]=(dp[i]+(dp[i-2]*(i-1+mod)%mod)%mod)%mod;
			dp[i]=(dp[i]+(pre[i-2]*pre1[i-2])%mod)%mod;
		}
		ans=dp[1];
		for(int i=2;i<=n;i++){
			ans=ans^dp[i];
		}
		write(ans%mod);
		puts(""); 
//	}
	return ;
}

signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}

