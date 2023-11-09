#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+2,M=5e2+2,P=998244353;
ll n,m,a[N],s[N];//
namespace S2{
	ll length(bitset<M>s){
		for(int i=N-1;i>=0;i--){
			if(s[i]==1)return i+1;
		}
		return 0;
	}
	void out(bitset<M> s){
		for(int i=0;i<length(s);i++){
			cout<<s[i];
		}
	}
	bitset<M> operator+(bitset<M>s1,bitset<M>s2){
		bitset<M> s;
		int n1=length(s1),n2=length(s2);
	//	cout<<n1<<"and"<<n2<<"\n";
		for(int i=0;i<min(n1,n2);i++){
			int c1=s1[i],c2=s2[i];
			if(s[i]==1){
				if(c1+c2==2){
					s[i]=1;
					s[i+1]=1;	
				}else if(c1+c2==1){
					s[i]=0;
					s[i+1]=1;	
				}else{
					s[i]=0;
				}
			}else{
				if(c1+c2==2){
					s[i+1]=1;
					s[i]=0;	
				}else if(c1+c2==1){
					s[i]=1;
				}else{
					s[i]=0;
				}
			}
		}
	//	cout<<"-";out(s);cout<<"-\n";
		for(int i=min(n1,n2);i<max(n1,n2);i++){
			if(n1<n2){
				if(s[i]==0){
					if(s2[i]==1)s[i]=1;
					else s[i]=0;
				}else{
					if(s2[i]==1)s[i]=0,s[i+1]=1;
					else s[i]=1;
				}
			}else{
				if(s[i]==0){
					if(s1[i]==1)s[i]=1;
					else s[i]=0;
				}else{
					if(s1[i]==1)s[i]=0,s[i+1]=1;
					else s[i]=1;
				}
			}
		}
	//	cout<<s[max(n1,n2)]<<"-_\n";
	//	out(s1);cout<<"+";out(s2);cout<<"=";
	//	out(s);cout<<"\n";
	//	cout<<n1<<"and"<<n2<<"\n";
		if(!n1&&n2)s=s2;
		if(!n2&&n1)s=s1;
		
		return s;
	}
	bitset<M> s2(ll x){
		bitset<M> s;
		int t=0;
		while(x){
			s[t++]=(x&1);
			x>>=1;
		}
		return s;
	}
};
using namespace S2;
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
ll qpow(ll a,bitset<M> s){
//	cout<<a<<"^(";
//	out(s);
//	cout<<")=";
	ll res=1,b=length(s);
	for(int i=0;i<b;i++){
		if(s[i]==1){
			res=res*a%P;
		}
		a=a*a%P;
	}
//	cout<<res<<"\n";
	return res;
}
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	if(n<=17){
		s[n+1]=1;
		unordered_map<ll,ll>ans,tmp;
		for(ll i=n;i>=1;i--){
			tmp.clear();
			ll mul=1;
			for(auto j:ans){
				tmp[gcd(a[i],j.first)]=tmp[gcd(a[i],j.first)]+j.second;
			}
			tmp[a[i]]++;
			for(auto j:tmp){
				ans[j.first]=ans[j.first]+j.second;
				mul=mul*qpow(j.first,j.second)%P;
			}
			s[i]=s[i+1]*mul%P;
		}
		for(ll i=1;i<=m;i++){
			ll l,r;
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",s[l]*qpow(s[r+1],P-2)%P);
		}
	}else{
		unordered_map<ll,bitset<M>>ans,tmp;
		s[n+1]=1;
		bitset<M>s0;
		s0[0]=1;
		for(ll i=n;i>=1;i--){
			tmp.clear();
			ll mul=1;
			for(auto j:ans){
				tmp[gcd(a[i],j.first)]=tmp[gcd(a[i],j.first)]+j.second;
			}
			tmp[a[i]]=tmp[a[i]]+s0;
			for(auto j:tmp){
				ans[j.first]=ans[j.first]+j.second;
				mul=mul*qpow(j.first,j.second)%P;
			}
			s[i]=s[i+1]*mul%P;
		}
		bitset<M> inv=s2(P-2);
		for(ll i=1;i<=m;i++){
			ll l,r;
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",s[l]*qpow(s[r+1],inv)%P);
		}
	}
	
	return 0;
}

