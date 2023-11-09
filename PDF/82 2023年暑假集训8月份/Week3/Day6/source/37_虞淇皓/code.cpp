#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,k;
void sol1(){
	for(int i=1;i<=k;i++) {
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


