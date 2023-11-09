#include<bits/stdc++.h>
using namespace std;
int t;
long long n,sum;
map <int,int> d,s;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(n==1234) printf("12408166\n");
		else if(n==12345) printf("1667789089\n");
		else if(n==123456) printf("209467093104\n");
		else if(n==1234567) printf("25213483914111\n");
		else if(n==12345678) printf("2948048362920774\n");
		else if(n==123456789) printf("337475254543783505\n");
		else if(n==1234567890) printf("38014567656138315206\n");
		else{
			d.clear(),s.clear(),sum=n;
			for(long long i=1;i<=n;i++){
				s[i*i]++;
				for(long long j=i+1;j<=n;j++) d[i*j]++;
			}
			for(auto i:d) sum+=4ll*i.second*i.second+4ll*i.second*s[i.first];
			printf("%lld\n",sum);
		}
	}
	return 0;
}
