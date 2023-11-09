#include<stdio.h>

#define int long long
template<typename dy> dy max(dy x,dy y){return x>y?x:y;}
template<typename dy> dy min(dy x,dy y){return x<y?x:y;}
template<typename dy> dy abs(dy x){return x<0?-x:x;}

int n,q;
signed main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	while(q--)
	{
		int x1,y1,x2,y2,ans1,ans2;scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		ans1=min(abs(y1-y2)+abs(x1-x2),abs(y1+y2-n)+abs(n+1-abs(x1-x2)));
		ans2=min(abs(n+1-abs(y1-y2))+abs(x1-x2),abs(n+1-abs(y1+y2-n))+abs(n+1-abs(x1-x2)));
		printf("%lld\n",min(ans1,ans2));
	}
    return 0;
}