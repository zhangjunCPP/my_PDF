#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
const int INF=0x3f3f3f3f;
int n,p,k,pos[maxn],add[maxn],val[maxn];
int qpow(int x,int y){
	int val=1;
	while(y){
		if(y&1)val=val*x;
		x=x*x,y/=2;
	}
	return val;
}
void solve1(){
	cout<<1<<"\n";
	for(int i=0;i<n;i++)cout<<i<<" ";
}
void solve2(){
	cout<<n*(n-1)/2<<"\n";
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)cout<<i<<" "<<j<<"\n";
	}
}

int out[maxn][maxn];
void solve3(){//k==2 ¹»Òõ¼ä 
	int ans;
	ans=qpow(p,k-1)*(qpow(p,k)-1)/(p-1);
	cout<<ans<<"\n";
	for(int i=0;i<p*p;i+=p){
		for(int j=i;j<i+p;j++)cout<<j<<" ";
		cout<<"\n";
	}
	int tot=0;
	for(int i=p;i<p*p;i+=p){
		tot++;
		for(int j=i;j<i+p;j++){
			out[tot][j-i+1]=j;
		}
	}
	for(int i=1;i<=tot;i++)add[i]=i-1;
	add[tot+1]=tot;
	for(int i=0;i<p;i++){
		for(int j=1;j<=p;j++){
			cout<<i<<" ";
			for(int k=1;k<=tot;k++){
				int id=(j+val[k])%p;
				if(id==0)id=p;
				cout<<out[k][id]<<" ";
			}
			cout<<"\n";
		}
		for(int j=1;j<=tot;j++)val[j]+=add[j];
		int v=add[tot+1];
		for(int i=tot;i>=1;i--)add[i+1]=add[i];
		add[1]=v;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>p>>k;
	n=qpow(p,k);
	if(k==1)solve1();
	else if(p==2)solve2();
	else solve3();
	return 0;
}
