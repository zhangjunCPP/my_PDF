#include<bits/stdc++.h>
#define int long long
using namespace std;
int p,s;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&p,&s);
	if(p&1) return puts("Impossible"),0;
	int x=0,y=0; bool flag=false;
	for(int i=1;i*i<=s;i++){
		if(s%i!=0) continue;
		int j=s/i;
		if((i+j)*2==p){
			x=i; y=j;
			flag=true;
			break;
		}
	} 
	if(!flag) return puts("Impossible"),0;
	if(flag){
		putchar('3');
		for(int i=2;i<=x;i++) putchar('2');
		putchar('3');
		for(int i=2;i<=y;i++) putchar('2');
		putchar('3');
		for(int i=2;i<=x;i++) putchar('2');
		putchar('3');
		for(int i=2;i<=y;i++) putchar('2');
		return 0;
	}
	return 0;
}

