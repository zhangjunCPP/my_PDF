/*
膜拜传奇特级宗师 zsc985246 大神儿
今天在 florr 首页称您为大夏尊贵的大名儿
一股敬佩之情油生然而
您在 florr 为国争光，扬我大夏威名
向您献上最真挚的膜拜！！！
膜拜传奇特级宗师 zsc985246 大神儿，今，一，您，扬。向！
膜拜传奇特级宗师 zsc985246 大神儿，今，一，您，扬。向！
膜拜传奇特级宗师 zsc985246 大神儿，今，一，您，扬。向！
*/
#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 200010
#define ll long long
#define mod 998244353
int n,q,a[N],mx;
__int128 m1=((__int128)1<<70)/mod;
struct G{
	int l,r;
}b[N];
ll add(ll x,ll y){
	return x+y>=mod?x+y-mod:x+y;
}
ll del(ll x,ll y){
	return x>=y?x-y:x+mod-y;
}
ll fmd(ll x){
	return del(x,((m1*x)>>70)*mod);
}
ll qpow(ll a,ll b,ll p){
	ll r=1;
	for(;b;b>>=1,a=fmd(a*a)){
		if(b&1){
			r=fmd(r*a);
		}
	}
	return r;
}
namespace pr{
	int v[N],p[N],tot,id[N];
	void init(int n){
		v[1]=1;
		For(i,2,n){
			if(!v[i]){
				p[++tot]=i;
				id[i]=tot;
			}
			for(int j=1;j<=tot&&i*p[j]<=n;++j){
				v[i*p[j]]=1;
				if(i%p[j]==0)break;
			}
		};
	};
}
namespace f1{
	int t[N][110],tem[N];
	ll pw[N],st[N][110];
	map<ll,ll>mp;
	void f1(){
		pw[0]=1;
		For(i,1,n)pw[i]=pw[i-1]*2%(mod-1);
		For(i,1,n){
			int j=a[i];
			for(int k=2;k*k<=j;++k){
				while(j%k==0){
					++t[pr::id[k]][i];
					j/=k;
				}
			};
			if(j!=1)++t[pr::id[j]][i];
		};
		For(i,1,pr::tot)For(j,1,n)st[i][j]=st[i][j-1]+t[i][j];
		For(i,1,q){
			if(mp.find(b[i].l*n+b[i].r)!=mp.end()){
				cout<<mp[b[i].l*n+b[i].r]<<'\n';
				continue;
			}
			ll ans=1;
			For(j,1,pr::tot){
				int l=b[i].l,r=b[i].r;
				if(pr::p[j]<=sqrt(mx)){
					ll res=0;
					For(k,l,r){
						tem[k]=t[j][k];
					};
					sort(tem+l,tem+r+1);
					For(k,l,r){
						res+=tem[k]*pw[r-k];
						res%=mod-1;
					};
					ans=fmd(ans*qpow(pr::p[j],res,mod));
				}else if(st[j][l-1]<st[j][r]){
					ans=fmd(fmd(ans*pr::p[j])*(pw[st[j][r]-st[j][l-1]]+mod-1));
				}
			};
			cout<<(mp[b[i].l*n+b[i].r]=ans)<<'\n';
		};
		return;
	}
}
namespace f2{
	vector<int>v[460][10];
	using f1::pw;
	ll spw[N],st[460][N];
	void f2(){
		pw[0]=spw[0]=1;
		For(i,1,n){
			pw[i]=pw[i-1]*2%(mod-1);
			spw[i]=(spw[i-1]+pw[i])%(mod-1);
		}
		For(i,1,n){
			int j=a[i];
			for(int k=2;k*k<=j;++k){
				int cnt=0;
				while(j%k==0){
					++cnt;
					j/=k;
				}
				v[pr::id[k]][cnt].push_back(i);
			};
			v[pr::id[j]][1].push_back(i);
		};
		For(i,1,n)For(j,1,pr::tot)st[j][i]=st[j][i-1]+(a[i]%pr::p[j]==0);
		int T=sqrt(mx);
		For(i,1,q){
			ll ans=1;
			For(j,1,pr::tot){
				if(pr::p[j]<=T){
					ll lst=0,res=0,up=ceil(log(mx)/log(pr::p[j]));
					for(int k=up;~k;--k)if(v[j][k].size()){
						int x=lower_bound(v[j][k].begin(),v[j][k].end(),b[i].l)-v[j][k].begin(),
							y=upper_bound(v[j][k].begin(),v[j][k].end(),b[i].r)-v[j][k].begin();
						if(x<y){
							res+=((lst+y-x-1>=0?spw[lst+y-x-1]:0)-(lst>0?spw[lst-1]:0)+mod-1)*k;
							res%=mod-1;
							lst+=y-x;
						}
					};
					ans=fmd(ans*qpow(pr::p[j],res,mod));
				}else if(st[j][b[i].l-1]<st[j][b[i].r]){
					ans=fmd(fmd(ans*pr::p[j])*(pw[st[j][b[i].r]-st[j][b[i].l-1]]+mod-1));
				}
			};
			cout<<ans<<'\n';
		};
	}
}
void solve(){
	cin>>n>>q;
	For(i,1,n){
		cin>>a[i];
		mx=max(mx,a[i]);
	};
	pr::init(mx);
	For(i,1,q){
		cin>>b[i].l>>b[i].r;
	};
	if(mx<=450)f2::f2();
	else f1::f1();
	
	return;
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}
/*
1.5s,512MB
tnnd 怎么两个卡空间题
*/
