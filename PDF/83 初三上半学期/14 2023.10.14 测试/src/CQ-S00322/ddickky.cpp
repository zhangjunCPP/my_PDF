#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;/*T fl=-1;*/char c=getchar();while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 200005
#define K 45
#define LL long long
#define P 998244353
map<int,int> cnt;
int a[N];
int n,q;
int MX;
LL qp(LL a,int b){
	LL sum=1;
	while(b){
		if(b&1)sum=(sum*a)%P;
		a=(a*a)%P;
		b>>=1;
	}
	return sum;
}
void f1(){
	for(int i=1;i<=q;i++){
		int l,r;
		read(l);
		read(r);
		LL sum=1;
		for(int j=l;j<=r;j++){
			for(auto k:cnt){
				if(k.second){
					int g=__gcd(a[j],k.first);
					cnt[g]+=k.second;
					cnt[g]%=(P-1);
				}
			}
			cnt[a[j]]++;
		}
		for(int j=2;j<=MX;j++)
			sum=(sum*qp(j,cnt[j]))%P;
		cnt.clear();
		printf("%lld\n",sum);
	}
}
vector<pair<int,int> > v;
unordered_map<int,int> cnt1;
void f2(){
	for(int i=1;i<=q;i++){
		int l,r;
		read(l);
		read(r);
		LL sum=1;
		for(int j=l;j<=r;j++){
			for(auto k:cnt1){
				if(k.second){
					int g=__gcd(a[j],k.first);
					v.push_back({g,k.second});
				}
			}
			for(auto k:v)
				cnt1[k.first]+=k.second;
			v.clear();
			cnt1[a[j]]++;
		}
		for(int j=2;j<=MX;j++)
			sum=(sum*qp(j,cnt1[j]))%P;
		cnt1.clear();
		printf("%lld\n",sum);
	}
}
int main(){
	freopen("ddickky.in","r",stdin);
//	freopen("ex_sub3.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	read(n);
	read(q);
	for(int i=1;i<=n;i++){
		read(a[i]);
		MX=Max(MX,a[i]);
	}
	f2();
	return 0;
}
/*
5 2
8 2 8 8 9
1 5
2 4
*/
