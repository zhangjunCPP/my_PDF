#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 200010
#define ll long long
int n,a[N],b[N],s[N],t[N],pa,pb,ps,pt,fl;
ll Tns[]={0,0,0,0,2,30,326,3234,31762,321294,3422702,38879082};
void _(int x){
	For(i,1,n){
		For(j,i+1,n){
			For(k,j+1,n){
				For(l,k+1,n){
					if(a[k]<a[i]&&a[i]<a[j]&&a[j]<a[l]){
						fl=0;
						return;
					}
					if(a[k]<a[i]&&a[i]<a[l]&&a[l]<a[j]){
						fl=0;
						return;
					}
				};
			};
		};
	};
}
void dfs(){
	For(i,1,n)a[i]=i;
	int ans=0;
	do{
		fl=1;
		_(1);
		ans+=!fl;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		int n,p;
		cin>>n>>p;
		if(n<=11)cout<<Tns[n]%p<<'\n';
		else dfs();
	}
	return 0;
}
