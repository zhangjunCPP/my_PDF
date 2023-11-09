#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
} 
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
ll n,q;
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	n=read();
	q=read();
	while(q--){
		ll x,y,l,r,ans=2e9;
		x=read();
		y=read();
		l=read();
		r=read();
		ans=min(ans,y+1+abs(x-l)+n-r);
		ans=min(ans,y+1+x+1+n-l+r);
		ans=min(ans,y+1+n-x+1+l+r);
		ans=min(ans,n-y+1+abs(x-l)+r);
		ans=min(ans,n-y+1+x+1+n-l+n-r);
		ans=min(ans,n-y+1+n-x+1+l+n-r);
		ans=min(ans,x+1+n-l+abs(n-y-r));
		ans=min(ans,n-x+1+l+abs(n-y-r));
		work(min(ans,abs(x-l)+abs(y-r)));
		putchar('\n');
		//横着走,用(i,0)<->(i,n)的边 
		//竖着走,用(0,j)<->(n,n-j)的边 
	}
	return 0;
}
