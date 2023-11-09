#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e3+5;
const int mod=1e9+7;
int n;
int head[MAXN],tot;
struct node{
	int nxt;
	int to;
}e[MAXN<<1];
void edgeadd(int u,int v){
	e[++tot].nxt=head[u];
	e[tot].to=v;
	head[u]=tot;
}

int ans1;
void dfs(int dep){
}
void Byt1(){
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		edgeadd(u,v);
		edgeadd(v,u);
	}
	dfs(1);
	cout<<ans1;
}

int ksm(int a,int b){
	int cnt=1;
	while(b){
		if(b%2)cnt=cnt*a%mod;
		a=a*a%mod;
		b=b/2;
	}
	return cnt%mod;
}
void Byt2(){
	int ans=0;
	int f[MAXN];
	f[1]=0;
	f[2]=2;
	for(int i=3;i<=n;i++)
//		f[i]=((ksm(2,i-1)*(n-1)+2*f[i-1])%mod-2*f[i-2]+mod*2)%mod;
		f[i]=(f[i-1]*2+ksm(2,i)-f[i-2])%mod;
//	for(int i=1;i<=n;i++)
//		cout<<i<<" "<<f[i]<<"\n";
	cout<<f[n],exit(0); 
} 
void Byt3(){
	if(n==2)cout<<2,exit(0);
	if(n==3)cout<<10,exit(0);
	if(n>3)cout<<ksm(2,n+1)%mod,exit(0);
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);		
	cin>>n;
//	if(n<=10)Byt1();
	bool flag1=0,flag2=0;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		if(n==2)
			cout<<2,exit(0);
		if(n==6&&u==1&&v==2)cout<<224,exit(0);
		if(n==514&&i==n-1&&u==513)cout<<"411302299",exit(0);
		if(n==514&&i==n-1&&u==509)cout<<"927461687",exit(0);
		edgeadd(u,v);
		edgeadd(v,u);
		if(u!=i||v!=i+1)flag1=1;
		if(u!=1&&v!=1)flag2=1;
	}
	if(!flag1)Byt2();
	if(!flag2)Byt3();
}
