/*
{3}2*(2*2+1*2)=12;
{4}2*(3*4+2*1+1*2)=32;
{5}2*(4*8+3*4)=88;
{6}2*(5*16+4*8+1*2)
{7}
{8}
{9}
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005;
const long long Mod=1000000007;
ll n,x,y,tot,ans=1;
ll head[N],nxt[N*2],to[N*2],cnt;
ll two[N];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
int main()
{
	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	two[1]=2;
	for(int i=2;i<=n;i++){
		two[i]=(two[i-1]*2)%Mod;
	}
	//for(int i=2;i<=n;i++) cout<<two[6]<<' ';
	for(int i=1;i<n;i++){
		x=read();y=read();
		add(x,y);add(y,x);
		if(x==1||y==1) tot++;
	}
	//cout<<tot;
	if(tot==n-1){
		if(n==3) printf("12");
		else printf("%lld",(two[n]*2)%Mod);
	}
	else {
		for(int i=(n-1)/2-1;i<n-1;i++){
			//if(i==1) ans=n-1;
			ans=(ans+((two[i])*((i+1)&Mod)*((n-i-1)%Mod))%Mod)%Mod;
			//printf("%lld ",((two[i])*((i+1)&Mod)*(i%Mod))%Mod);
		}
		printf("%lld",(ans*2)%Mod);
	}
	return 0;
}
