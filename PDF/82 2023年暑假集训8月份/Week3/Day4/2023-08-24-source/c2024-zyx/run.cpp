#include<bits/stdc++.h>
using namespace std;
long long n,p,s;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	scanf("%lld%lld",&p,&s);
	n=p/2;
	if(p<=3||(p&1)||n-1>s||(n/2)*(n-n/2)<s) printf("Impossible");
	else{
		long long l=1,r=n/2;
		while(l<r){
			long long mid=(l+r)>>1;
			if(mid*(n-mid)<s) l=mid+1;
			else r=mid;
		}
		long long a=min(l,n-l),b=max(l,n-l),rest=a*b-s;
		if(!rest){
			for(int i=1;i<=a;i++) printf("2");
			printf("3");
			for(int i=2;i<=b;i++) printf("2");
			printf("3");
			for(int i=2;i<=a;i++) printf("2");
			printf("3");
			for(int i=2;i<=b;i++) printf("2");
		}
		else{
			for(int i=1;i<=a;i++) printf("2");
			printf("3");
			for(int i=2;i<=b-rest;i++) printf("2");
			printf("31");
			for(int i=2;i<=rest;i++) printf("2");
			printf("3");
			for(int i=3;i<=a;i++) printf("2");
			printf("3");
			for(int i=2;i<=b;i++) printf("2");
		}
	}
	return 0;
}
