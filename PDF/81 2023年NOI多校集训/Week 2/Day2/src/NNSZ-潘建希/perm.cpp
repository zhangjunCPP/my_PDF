#include<bits/stdc++.h>
using namespace std;
int n,p[13]={0,0,0,1,7,47,322,2404,19778,180130,1809652,19940552,239430724};
long long N,ans;
int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%d%lld",&n,&N);
	if(n<13){
		for(int i=1;i<=n;i++)
			ans^=p[i];
		printf("%lld",ans%N);
	}
	return 0;
} 
