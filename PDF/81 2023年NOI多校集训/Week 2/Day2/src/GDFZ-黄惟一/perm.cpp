#include<bits/stdc++.h>
using namespace std;
namespace my_std{
#define mems(x,y) memset(x,y,sizeof x)
#define Mp make_pair
#define eb emplace_back
#define gc getchar
#define pc putchar
#define fi first
#define se second
	typedef long long ll;
	typedef pair<int,int> pii;
	inline int read(){
		int x=0,f=1;
		char c=gc();
		while(!isdigit(c)){
			if(c=='-')
				f=-1;
			c=gc();
		}
		while(isdigit(c)){
			x=x*10+c-48;
			c=gc();
		}
		return x*f;
	}
}
using namespace my_std;
const int N=1e7+7,M=-1,inf=0x3f3f3f3f,mod=0;
int n,p,f[N];
void solve(){
	scanf("%d%d",&n,&p);
	int ans=0,sm=1;
	f[2]=1,f[3]=2;
	for(int i=2;i<=n;i++){
		if(!f[i])
			f[i]=(f[i-1]+1ll*(i-1)*f[i-2]%p)%p;
		if(i>2)
			sm=1ll*sm*i%p;
		ans^=(sm-f[i]+p)%p;
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	int t=1;
	//	scanf("%d",&t);
	while(t--)
		solve();
}

