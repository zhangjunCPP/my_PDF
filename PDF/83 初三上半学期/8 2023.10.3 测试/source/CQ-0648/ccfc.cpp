#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=1e5+5,P=131,Q=998244353;
int n;
char s[N];
ull hash1[N],hash2[N],pow1[N],pow2[N];
ull get1(int l,int r){
	return hash1[r]-hash1[l-1]*pow1[r-l+1];
}
ull get2(int l,int r){
	return hash2[r]-hash2[l-1]*pow2[r-l+1];
}
bool check(int s,int len){
	return get1(s,s+len-1)==get1(s+len,s+len+len-1)&&get2(s,s+len-1)==get2(s+len,s+len+len-1)&&get1(s,s+len-1)==get1(n-len+1,n)&&get2(s,s+len-1)==get2(n-len+1,n);
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1),n=strlen(s+1);
	pow1[0]=pow2[0]=1;
	for(int i=1;i<=n;++i) hash1[i]=hash1[i-1]*P+(s[i]-'a'),hash2[i]=hash2[i-1]*Q+(s[i]-'a'),pow1[i]=pow1[i-1]*P,pow2[i]=pow2[i-1]*Q;
	for(int i=1,ans;i<=n;++i){
		ans=0;
		for(int j=1;i+j*3-1+1<=n;++j) ans+=check(i,j);
		printf("%d ",ans);
	}
	return 0;
}
