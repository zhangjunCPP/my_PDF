#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int read(){
	int ret=0,f=1;char c=getchar();
	while(c>57||c<48){if(c=='-')f= -1;c=getchar();}
	while(c<=57&&c>=48)ret=(ret<<3)+(ret<<1)+(c-48),c=getchar();
	return ret*f;
}
void write(int x){
	if(x<0) x= -x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int maxn=2e5+5;
const int mod =1e9+7;
int n,m,q;
struct ed{
	int h,t;
}e[maxn];
int last[maxn],ecnt,in[maxn],edu[maxn],edv[maxn];
void link(int x,int y){
	in[y]++;
	e[++ecnt].h=last[x];
	e[ecnt].t=y;
	last[x]=ecnt;
}
bool checkA(){
	for(int i=1;i<n;i++){
		if(i!=edu[i]||i!=edv[i]-1)return 0;
	}
	return 1;
}
bool checkB(){
	return in[1]==n-1;
}
void doB(){
	if(in[1]>=3){
		int x=1;
		for(int i=1;i<=n;i++)x=x*2%mod;
		write(x*2%mod);
	}else{
		if(in[1]==0)write(0);
		if(in[1]==1)write(2);
		if(in[1]==2)write(12);
	}
}
int f[maxn];
void doA(){
	f[1]=1;
	int x=1;
	for(int i=2;i<=n;i++,x=x*2%mod){
		f[i]=(x*3*i+f[i-2]+x)%mod;
	}
	write((f[n-2]*2+(n-1)*(x)%mod)%mod);
}
int dep[maxn];
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	for(int i=last[u];i;i=e[i].h){
		int v=e[i].t;
		if(v==f)continue;
		dfs(v,u);
	}
}
void doC(){
	dfs(1,0);
	int max_dep=0,x=1;
	for(int i=1;i<=n;i++){
		max_dep=max(max_dep,dep[i]);
		x=x*2%mod;
	}
	write(max_dep*x%mod);
}
int dis[21][21],w[maxn],b[maxn],wcnt,bcnt;
void do10(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<n;i++){
		dis[edu[i]][edv[i]]=dis[edv[i]][edu[i]]=1;
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int answer=0;
	for(int i=0;i<(1<<n);i++){
		wcnt=bcnt=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				w[++wcnt]=j+1;
			}else b[++bcnt]=j+1;
		}
		int ans=0;
		for(int j=1;j<=wcnt;j++){
			for(int k=1;k<=wcnt;k++){
				ans=max(ans,dis[w[j]][w[k]]);
			}
		}
		for(int j=1;j<=bcnt;j++){
			for(int k=1;k<=bcnt;k++){
				ans=max(ans,dis[b[j]][b[k]]);
			}
		}
		answer+=ans;
	}
	write(answer);
}
void solve(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    n=read();
    for(int i=1,x,y;i<n;i++){
    	edu[i]=read(),edv[i]=read();
    	link(edu[i],edv[i]),link(edv[i],edu[i]);
	}
	if(n<18){
		do10();
	}else if(checkA()){
		doA();
	}else if(checkB()){
		doB();
	}else{
		doC();
	}
}
signed main(){
    int t=1;
    while(t--)solve();
    return 0;
}
/*

6
1 2
2 3
3 4
4 5
3 6
*/
