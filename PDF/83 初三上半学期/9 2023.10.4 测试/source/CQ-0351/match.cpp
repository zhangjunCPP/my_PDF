#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
using ull=unsigned long long;
const int Maxn=2e5+5;
const ull Pri=1789;
char s[Maxn],t[Maxn];
ull P [Maxn]={1};
ull H1[Maxn],H2[Maxn];
inline ull calc1(int l,int r){
	return H1[r]-H1[l-1]*P[r-l+1];
}
inline ull calc2(int l,int r){
	return H2[r]-H2[l-1]*P[r-l+1];
}
inline int L(int x,int n,int m){
	int l=1,r=m,res=m;
	while(l<=r){
		int mid=l+r>>1;
		if(calc1(x,x+mid-1)!=calc2(1,mid))res=mid,r=mid-1;
		else l=mid+1;
	}
	return x+res-1;
}
inline int R(int x,int n,int m){
	int l=1,r=m,res=m;
	while(l<=r){
		int mid=l+r>>1;
		if(calc1(x-mid+1,x)!=calc2(m-mid+1,m))res=mid,r=mid-1;
		else l=mid+1;
	}
	return x-res+1;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int d;cin>>d>>(s+1);
	int n=strlen(s+1);
	for(int i=1;i<=2e5;++i)P [i]=P [i-1]*Pri;
	for(int i=1;i<= n ;++i)H1[i]=H1[i-1]*Pri+s[i];
	int q;cin>>q;
	while(q--){
		cin>>(t+1);
		int m=strlen(t+1);
		if(m<=d){cout<<n<<'\n';continue;}
		for(int i=1;i<=m;++i)H2[i]=H2[i-1]*Pri+t[i];
		int cnt=0;
		for(int i=1;i+m-1<=n;++i)cnt+=R(i+m-1,n,m)-L(i,n,m)<d;
		cout<<cnt<<'\n';
	}
	return 0;
}
