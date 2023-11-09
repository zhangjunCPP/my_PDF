#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 1010
#define ll long long
#define pb push_back
int n,l[N],r[N],fg,ff1,ff2;
ll c[N],f[1<<20|1];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	For(i,1,n){
		cin>>l[i]>>r[i]>>c[i];
		fg=max({fg,i-l[i],r[i]-i});
		if(l[i]!=max(i-6,1)||r[i]!=min(i+6,n)||c[i]!=1)ff1=1;
		if(l[i]!=max(i-7,1)||r[i]!=min(i+7,n)||c[i]!=1)ff2=1;
	};
	if(!fg){
		cout<<0;
		return 0;
	}else if(n<=20){
		memset(f,-0x3f,sizeof(f));
		f[0]=0;
		For(s,0,(1<<n)-1){
			For(i,1,n)if(!((s>>(i-1))&1)){
				ll sum=0,x=s|(1<<(i-1));
				For(j,l[i],r[i]){
					if(j!=i&&!((s>>(j-1))&1)){
						sum+=c[i];
					}
				}
				f[x]=max(f[x],f[s]+sum);
			};
		};
		cout<<f[(1<<n)-1];
	}else if(!ff1){
		cout<<(n-14)*6+63<<'\n';
	}else if(!ff2){
		cout<<(n-16)*7+84<<'\n';
	}
	return 0;
}
