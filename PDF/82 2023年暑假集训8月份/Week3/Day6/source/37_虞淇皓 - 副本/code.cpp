#include<bits/stdc++.h>
using namespace std;
long long a,b,k;
void sol1(){
	for(long long i=1;i<=k;i++) {
		printf("1");
	}
}
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	k=a*b-1;
	if(k<=200000)sol1();
	return 0;
}


