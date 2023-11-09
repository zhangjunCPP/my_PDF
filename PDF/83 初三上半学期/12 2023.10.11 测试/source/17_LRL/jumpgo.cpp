#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=510;
const int mod=1e9+7;
int n,flag1,flag2,a[N],ans;
char s[N];
LL my_pow(LL a,LL b){
	LL res=1ll;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1ll;
	}
	return res;
}
int main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	n=read(),flag1=flag2=1;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
		if(s[i]!='?')flag1=0;
		else flag2=0;
	if(n<=20)printf("10\n");
	else if(flag1)printf("%lld\n",my_pow(2ll,n));
	return 0;
}
