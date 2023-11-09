#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using ll=long long;
constexpr int N=500010,M=998244353;
int Ch,n,i,cnt[N],j,k,k1,tot,L,R,s,F[2][N],*f,*lf,G_cnt[N],*p_tmp,ANS[N];
ll ans_=1,ans;
std::vector<int>a[N],Group[N];
std::set<int>st;
std::map<int,int>mp;
decltype(st.end())it;
decltype(mp.end())it2;
decltype(a->begin())Begin[N];
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
inline ll pow(ll a,int b){
	ll s=1;
	while(b){
		if(b&1)s=s*a%M;
		a=a*a%M;
		b>>=1;
	}
	return s;
}
int main(){
	freopen("marketeers.in","r",stdin);
	//freopen("marketeers.out","w",stdout);
	r(n);
	a[0].emplace_back(0);
	cnt[0]=1;
	for(i=1;i<=n;i++){
		r(cnt[i]);
		for(j=0;j<cnt[i];j++){
			r(k);
			a[i].emplace_back(k);
		}
		std::sort(a[i].begin(),a[i].end());
		it=st.upper_bound(a[i].front());
		if(it!=st.end())
			while(a[i].back()>=*it)a[i].pop_back();
		st.emplace(a[i].back());
//	}
//	st.clear();
//	for(i=n;i;i--){
//		cnt[i]=a[i].size();
//		Begin[i]=a[i].begin();
//		it=st.lower_bound(a[i].back());
//		if(it!=st.begin()){
//			it--;
//			while(*Begin[i]<=*it){
//				Begin[i]++;
//				cnt[i]--;
//			}
//		}
//		st.emplace(*Begin[i]);
//	}
//	for(i=1;i<=n;i++){
		it2=mp.lower_bound(a[i].front());
		if(it2==mp.end())it2=mp.emplace(a[i].back(),++tot).first;
		Group[it2->second].emplace_back(i);
		G_cnt[it2->second]++;
//		printf("%d\n",it2->second);
	}
	for(i=1;i<=tot;i++){
//		Group[i].emplace_back(0);
		f=*F;
		lf=F[1];
		f[0]=1;
		k=0;
		for(j=G_cnt[i]-1;~j;j--){
			p_tmp=lf;
			lf=f;
			f=p_tmp;
			k1=k;
			k=Group[i][j];
			s=R=0;
			for(L=0;L<cnt[k];L++){
				while(R<cnt[k1]&&a[k][L]>a[k1][R]){
					s+=lf[R++];
					if(s>=M)s=M;
				}
				f[L]=s;
			}
		}
		s=0;
		for(j=0;j<cnt[Group[i].front()];j++){
			s+=f[j];
			if(s>=M)s=M;
		}
		ANS[i]=s;
		ans_=ans_*s%M;
	}
	w(ans_);
//	for(i=1;i<=n;i++){
//		printf("%d %d size=%d\n",*Begin[i],a[i].back(),cnt[i]);
//	}
	return 0;
}
