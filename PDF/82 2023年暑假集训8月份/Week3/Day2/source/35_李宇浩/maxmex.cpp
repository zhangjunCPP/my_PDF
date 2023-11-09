#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
constexpr int N=100010;
struct ss{
	int l,r;
	bool operator<(const ss&b)const{
		return l!=b.l?l<b.l:r<b.r;
	}
}S[2][N<<3],*s=*S+1,*ls;
std::vector<int>v[N];
int Ch,n,q,a[N],x,i,cnt,lcnt,ans[N],ma,Cnt[N];
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	r(n);
	for(i=1;i<=n;i++)v[i].emplace_back(0);
	for(i=1;i<=n;i++){
		r(a[i]);
		if(!a[i])s[cnt++]={i,i};
		else v[a[i]].emplace_back(i);
	}
	r(q);
	if(!cnt){
		while(q--){
			putchar(48);
			putchar(10);
		}
		return 0;
	}
	if(q<11){
		std::set<int>st;
		for(i=0;i<=n+1;i++)st.emplace(i);
		auto add=[&](const int&x){
			//printf("add:%d\n",x);
			if(!Cnt[x]++)st.erase(x);
		};
		auto del=[&](const int&x){
			//printf("del:%d\n",x);
			if(!--Cnt[x])st.emplace(x);
		};
		while(q--){
			r(x);
			for(i=1;i<=x;i++)add(a[i]);
			int ans=*st.begin();
			for(i=2;i+x-1<=n;i++){
				add(a[i+x-1]);
				del(a[i-1]);
				if(ans<*st.begin())ans=*st.begin();
			}
			for(;i-1<=n;i++)del(a[i-1]);
			w(ans);
			putchar(10);
		}
		return 0;
	}
	for(x=1;x<=n;x++){//我直接碾过去，这波不是WA就是T 
		ans[x]=0x3fffffff;
		v[x].emplace_back(n+1);
		ls=s;
		ls[-1]={0,0};
		ls[cnt]={n+1,n+1};
		s=S[x&1]+1;
		lcnt=cnt;
		cnt=0;
		auto it=v[x].begin();
		auto it2=it;
		for(i=0;i<lcnt;i++){
			if(ls[i].l==ls[i-1].l||ls[i].r==ls[i+1].r)continue;
			ma=ls[i].r;
			while(*it<ls[i].l)it++;
			while(*it2<=ls[i].r)it2++;
			if(*it<=ls[i].r)s[cnt++]=ls[i];
			else{
				s[cnt++]={it[-1],ls[i].r};
				s[cnt++]={ls[i].l,*it2};
			}
		}
		std::sort(s,s+cnt);
		while(cnt&&!s->l){
			s++;
			cnt--;
		}
		while(cnt&&s[cnt-1].r==n+1)cnt--;
		for(i=0;i<cnt;i++){
			if(ans[x]>s[i].r-s[i].l+1)ans[x]=s[i].r-s[i].l+1;
//			printf("%d %d\n",s[i].l,s[i].r);
		}
//		printf("ed#%d: %d\n",x,ans[x]);
	}
	while(q--){
		r(x);
		w(std::upper_bound(ans+1,ans+n+1,x)-ans);
		putchar(10);
	}
	return 0;
}
