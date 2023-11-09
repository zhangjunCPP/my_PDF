#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;
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
	return f*x;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
比较抽象的计数题
 
*/
const ll mod=1e9+7;
int n,m,t,col[105];
ll k,ans;
struct node{
	ll x,y,g,h;
}a[105]; 
void dfs(int now){
	if(now>n){
		ll val=1;
		for(int i=1;i<=m;i++){
			if(col[a[i].x]==col[a[i].y])
				val*=a[i].h;
			else
				val*=a[i].g;
			val%=mod;
		}
		ans+=val;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=k;i++){
		col[now]=i;
		dfs(now+1);
	}
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		m=read();
		k=read();
		if(n==2){
			ll val=1,val1=1;
			for(int i=1,x,y,g,h;i<=m;i++){
				x=read();
				y=read();
				g=read();
				h=read();
				val*=g;
				val%=mod;
				val1*=h;
				val1%=mod;
			}
			work((k*val1%mod+k*(k-1)%mod*val%mod)%mod);
			putchar('\n');
			continue;
		}
		ans=0;
		for(int i=1;i<=m;i++){
			a[i].x=read();
			a[i].y=read();
			a[i].g=read();
			a[i].h=read();
		}
		dfs(1);
		work(ans);
		putchar('\n');
	}
	return 0;
}
