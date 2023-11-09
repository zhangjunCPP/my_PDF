#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x; 
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int cnt=0;
	do stk[++cnt]=x%10+48,x/=10;while(x);
	for(;cnt;)putchar(stk[cnt--]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}
const int maxn=2e5+4,mod=998244353;
int fast_pow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=x*x%mod)if(y&1)res=res*x%mod;
	return res;
}
std::vector<int>prime;
int n,Q,a[maxn];
std::vector<int>E[maxn];
std::vector<std::pair<int,int> >jk[maxn];
bool cmp(int x,int y){return x<y;}
void work(int x,int id){
	int gh=id;
	for(int i=2;i*i<=x;++i)
		if(x%i==0){
			int cnt=0;
			for(;x%i==0;x/=i)cnt++;
			jk[gh].emplace_back(std::make_pair(i,cnt));
//			E[i].emplace_back(cnt);
		}
	if(x!=1)
		jk[gh].emplace_back(std::make_pair(x,1));
//		E[x].emplace_back(1),;
}
bool flag=1;
bool check(int x){
	for(int i=2;i*i<=x;++i)
		if(x%i==0)return 0;
	return 1;
} 
signed main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	read(n,Q);
	for(int i=1;i<=n;++i){
		read(a[i]),work(a[i],i);
		if(a[i]>450)flag=0;
	}
	if(flag){
		for(int i=2;i<=450;++i)
			if(check(i))
				prime.emplace_back(i);
	}
	else{
		for(int i=2;i<=200000;++i)
			if(check(i))
				prime.emplace_back(i);		
	}
	for(;Q--;){
		int ans=1,l,r;read(l,r);
		for(int i=l;i<=r;++i)
			for(auto y:jk[i])
				E[y.first].emplace_back(y.second);
		for(auto i:prime){
			std::sort(E[i].begin(),E[i].end(),cmp);
			int len=E[i].size();
			for(int j=0;j<len;++j)ans=ans*fast_pow(fast_pow(i,E[i][j]),fast_pow(2,len-j-1))%mod;
			E[i].clear();
		}
		write(ans,'\n');
	}
	return 0;
}
