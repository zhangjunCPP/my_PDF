#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){x=0;char c=getchar();/*T fl=1;*/
while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
template<typename T>void write(T x){if(x>=10)write(x/10);putchar((x%10)+'0');}
#define N 100005
#define INF 1145141919
#define LL long long
#define P 1000000007
//#define int LL
struct ed{
	int a,b;
	int d,s;
}e[N];
int n,m,k;
LL ans;
int col[N];
void dfs(int u){
	if(u==n+1){
		LL sum=1;
		for(int i=1;i<=m;i++){
			if(col[e[i].a]!=col[e[i].b])sum*=e[i].d;
			else sum*=e[i].s; 
			sum%=P; 
		}
		ans+=sum;
		ans%=P;
		return ;
	}
	for(int i=1;i<=k;i++){
		col[u]=i;
		dfs(u+1);
	}
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int T;
	read(T);
	while(T--){
		read(n);
		read(m);
		read(k);
		for(int i=1;i<=m;i++)read(e[i].a),read(e[i].b),read(e[i].d),read(e[i].s);
		dfs(1);
		printf("%lld",ans);
	} 
}
/*
1
2 4 3
2 1 1 1
2 1 2 2
2 1 2 0
1 2 1 1

*/ 
