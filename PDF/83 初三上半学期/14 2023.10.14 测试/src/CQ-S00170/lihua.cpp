#include<bits/stdc++.h>
#define ll int
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define pb push_back
const ll N=1e5+10;
using namespace std;

ll n,q;
char a[N][35],s[35];
ll len[N];



void mian(){
	
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",a[i]+1);
		len[i]=strlen(a[i]+1);
	}
	scanf("%d",&q);
	For(i,1,q){
		scanf("%s",s+1);
		ll m=strlen(s+1),ans=0;
		For(i,1,n){
			++ans;
			ll pos=1;
			while(a[i][pos]==s[pos]&&pos<=min(m,len[i]))++pos,++ans;
			if(pos>min(m,len[i])&&m==len[i])break;
		}
		printf("%d\n",ans);
	}
	
}

int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--)mian();
	return 0;
}
/*
9+10+28+10=57(((
*/ 
