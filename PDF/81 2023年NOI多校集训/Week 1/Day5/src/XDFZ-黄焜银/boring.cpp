/*
lcm有结合律吗？
有吧，至少我举不出反例
时限3s，感觉莫队没戏
线段树是O(klog(n))的 
开long long 

好吧，原来这题的难点在于取模
在运算过程中
gcd和lcm都是不能模的
也就是说
我只能在最后模一次
所以，我必须改变存储数的方式
用质因数分解的方式存储 
*/ 
#include<bits/stdc++.h>
#define ll long long
#define ls (k<<1)
#define rs (k<<1|1)
using namespace std;
const ll N=1e5+10,mod=998244353;
inline ll re(){
    ll x=0;bool f=1;
    char c=getchar();
    while(c<48||c>57){if(c==45)f=0;c=getchar();}
    while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return f?x:-x;
}
void wr(ll x){
    if(x<0)putchar(45),x=-x;
    if(x>9)wr(x/10);
    putchar(x%10+48);
}
vector<pair<ll,ll> >st;
struct Number{
	vector<pair<ll,ll> >z=st;
}tr[N<<2];
int p[100010],cnt;
bool f[100010];
inline void change(Number &res,ll x){
	res.z=st;
	for(int i=1;p[i]*p[i]<=x;++i){
		if(x%p[i]==0){
			int s=0;
			while(x%p[i]==0)++s,x/=p[i];
			res.z.push_back({p[i],s});
		}
	}
	if(x>1)res.z.push_back({x,1});
}
inline Number cheng(Number x,Number y){
	Number res;
	int j=0,mx=y.z.size();
	for(auto i:x.z){
		if(j!=mx&&i.first==y.z[j].first)res.z.push_back({i.first,i.second+y.z[j].second}),++j;
		else if(j==mx||i.first<y.z[j].first)res.z.push_back({i.first,i.second});
		else{
			while(j<mx&&i.first>y.z[j].first)res.z.push_back({y.z[j].first,y.z[j].second}),++j;
			if(j==mx||i.first<y.z[j].first)res.z.push_back({i.first,i.second});
		}
	}
	return res;
}
inline Number chu(Number x,Number y){
	int j=1,mx=y.z.size(),i;
	for(i=1;i<x.z.size();++i){
//		printf("ij:%d %d\n",i,j);
		if(j==mx)break;
		if(x.z[i].first!=y.z[j].first)continue;
		x.z[i].second-=y.z[j].second;
		++j;
		if(!x.z[i].second)x.z.erase(x.z.begin()+i,x.z.begin()+i+1),--i;
	}
	return x;
}
inline void Prime(int n){
	for(int i=2;i<=n;++i){
		if(f[i])continue;
		p[++cnt]=i;
		for(int j=i+i;j<=n;j+=i)f[j]=1;
	}
}
inline qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline Number gcd(Number x,Number y){
	Number res;
	int j=0,mx=y.z.size();
	for(int i=0;i<x.z.size();++i){
		while(j<mx&&y.z[j].first<x.z[i].first)++j;
		if(j==mx)return res;
		if(y.z[j].first!=x.z[i].first)continue;
		res.z.push_back({x.z[i].first,min(y.z[j].second,x.z[i].second)});
	}
	return res;
}
inline Number lcm(Number x,Number y){
	return chu(cheng(x,y),gcd(x,y));
}
ll n,q,i,a[N],m,ans,x,y;
void build(ll k,ll l,ll r){
	if(l==r){
		change(tr[k],a[l]);
		return;
	}
	ll mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	tr[k]=lcm(tr[ls],tr[rs]);
}
Number query(ll k,ll l,ll r,ll x,ll y){
	if(r<x||l>y)return tr[0];
	if(x<=l&&r<=y)return tr[k];
	ll mid=(l+r)>>1;
	return lcm(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
}
inline void print(Number x){
	ll res=1;
	for(int i=0;i<x.z.size();++i)res=res*qpow(x.z[i].first,x.z[i].second)%mod/*,printf("%lld %lld\n",x.z[i].first,x.z[i].second)*/;
	printf("%lld\n",res);
}
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	st.push_back({1,1});
	scanf("%lld%lld",&n,&q);
	Prime(n);
//	for(i=1;i<=cnt;++i)printf("%d ",p[i]);puts("");
//	while(1){
//		scanf("%d%d",&x,&y);
//		Number a,b;
//		change(a,x);
//		change(b,y);
//		print(a);
//		print(b);
//		print(cheng(a,b));
//	}
//	scanf("%d%d",&x,&y);
//	change(tr[1],x);
//	change(tr[2],y);
//	tr[1]=cheng(tr[1],tr[2]);
//	printf("%d=",x*y);for(i=0;i<tr[1].z.size();++i){printf("%d^%d",tr[1].z[i].first,tr[1].z[i].second);if(i<tr[1].z.size()-1)putchar('*');}
	for(i=1;i<=n;++i)scanf("%lld",a+i);
	build(1,1,n);
	while(q--){
		scanf("%lld",&m);
		Number ans=tr[0];
		for(i=1;i<=m;++i){
			scanf("%lld%lld",&x,&y);
			ans=lcm(ans,query(1,1,n,x,y));
		}
		print(ans);
	}
    return 0;
}

