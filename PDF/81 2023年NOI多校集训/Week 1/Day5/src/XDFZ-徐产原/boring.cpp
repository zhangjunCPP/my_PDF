#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int n,m,q,l,r,tot;__int128 ans,g;
int a[100005],cnt[100005],num[100005],vis[100005];
void exgcd(__int128 a,__int128 b,__int128 &x,__int128 &y){
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
	return;
}
__int128 gcd(__int128 a,__int128 b){
	return !b?a:gcd(b,a%b);
}
__int128 inv(__int128 a){
	__int128 x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}

void solve1(){
	while(q--){
		tot=0,ans=1;
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&l,&r);
			++cnt[l];--cnt[r+1];
		}
		for(int i=1;i<=n;i++){
			if(cnt[i])num[++tot]=a[i];
			cnt[i+1]+=cnt[i];cnt[i]=0;
		}
		for(int i=1;i<=tot;i++)
			ans=ans*num[i]/gcd(ans,num[i]);
		printf("%d\n",(int)(ans%p));
	}
}
void Freopen(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	solve1();
}