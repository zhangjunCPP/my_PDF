#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 2e5 + 5 ;
const int N = 20 ;
const int mod = 998244353 ;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int n,q,a[N];
ll b[20][20],ans;
ll st[18][M];
void X(int t,int n,int j){
	if(t>n){
		if(j!=0)
		ans=(ans*j)%mod;
		return;
	}
	X(t+1,n,j);
	X(t+1,n,gcd((j==0?a[t]:j),a[t]));
}
inline void prework(){
	int t=log(n)/log(2)+1;
	for(int i=1;i<=n;i++)st[0][i]=a[i];
	for(int k=1;k<=t;k++)
		for(int i=1;i+(1<<k)<=n;i++){
			st[k][i]=gcd(st[k-1][i],st[k-1][i+(1<<k-1)]);
		}
}
inline int query(int l,int r){
	int t=log(r-l+1)/log(2);
	return gcd(st[t][l],st[t][r-(1<<t)+1]);
}
inline int ask(int l,int r){
	int ans=1;
	return query(l,r);
}
int main(){
	freopen("ddickky.in","r",stdin);
	freopen("ddickky.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	if(n<=17){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ans=1;
				X(i,j,0);
				b[i][j]=ans;
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			printf("%d\n",b[x][y]);
		}
	}else{
		prework();
		for(int i=1;i<=q;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			printf("%d\n",ask(x,y));
		} 
	}
	return 0;
}
/*
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb
我是sb 
*/
