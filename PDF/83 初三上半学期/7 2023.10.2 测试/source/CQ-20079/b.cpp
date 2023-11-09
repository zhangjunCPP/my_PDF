#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,a[N];
void sol1(){
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		int s=0,g=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				s+=a[j];
				g++;
			}
		}
		double p=s*1.0/(g*1.0);
		int ss=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				if(a[j]>p){
					ss++;
				}
			}
		}
		ans=max(ans,ss);
//		cout<<i<<" "<<ss<<endl;
	}
	printf("%lld",ans);
}
int b[N];
void sol2(){
	int ans=0;
	mt19937 rand(time(0));
	for(int t=1;t<=49000;t++){
		int s=0,g=0;
		for(int j=1;j<=n;j++)b[j]=rand()%2;
		for(int j=1;j<=n;j++){
			if(b[j]){
				s+=a[j];
				g++;
			}
		}
		double p= s*1.0/(g*1.0);
		int ss=0;
		for(int j=1;j<=n;j++){
			if(b[j]){
				if(a[j]>p){
					ss++;
				}
			}
		}
		ans=max(ans,ss);
	}
	printf("%lld",ans);
}
void sol3(){
	double st=clock();
	int ans=0;
	mt19937 rand(time(0));
	for(int t=1;clock()-st<=960;t++){
		int s=0,g=0;
		for(int j=1;j<=n;j++)b[j]=rand()%2;
		for(int j=1;j<=n;j++){
			if(b[j]){
				s+=a[j];
				g++;
			}
		}
		double p= s*1.0/(g*1.0);
		int ss=0;
		for(int j=1;j<=n;j++){
			if(b[j]){
				if(a[j]>p){
					ss++;
				}
			}
		}
		ans=max(ans,ss);
	}
	printf("%lld",ans);
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=20){
		sol1();
	}
	else if(n<=2000){
		sol3();
	}
	else{
		sol3();
	}
	return 0;
}

