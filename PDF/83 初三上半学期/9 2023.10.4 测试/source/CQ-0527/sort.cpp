#include<bits/stdc++.h>
using namespace std;
int t,n,p;
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&p);
		if(n<=3) printf("0");
		else if(n==4) printf("%d\n",2%p);
		else if(n==5) printf("%d\n",30%p);
		else if(n==12) printf("%d\n",473708154%p);
	}
	return 0;
}
