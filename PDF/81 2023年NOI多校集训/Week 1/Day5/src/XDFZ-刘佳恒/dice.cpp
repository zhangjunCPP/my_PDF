#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
int a[128][6];
int main() {
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout); 
	scanf("%d%d",&n,&k);
	if(n==1) {
		puts("Yes");
		for(int i=0;i<=5;i++) printf("%d ",k*i);
		return 0;
	}
	if(k==2) {
		puts("Yes");
		for(int i=1;i<=n;i++) puts("2 4 6 8 10");
		return 0;
	} 
	if(k==4) {
		puts("Yes");
		for(int i=1;i<=n;i++) puts("4 8 16 32 64");
		return 0;
	}
	if(k==8){
		puts("Yes");
		for(int i=1;i<=n;i++) puts("8 16 32 64 128");
		return 0;
	}
	if(k==16){
		puts("Yes");
		for(int i=1;i<=n;i++) puts("16 32 64 128 256");
		return 0;
	}
	if(k==32) {
		puts("Yes");
		for(int i=1;i<=n;i++) puts("32 64 128 256 512");
		return 0;
	} 
	int lg=log2(k)+1;
	if( ( k<<(5*lg) )>N ) { puts("No"); return 0; }
	for(int i=1;i<=n;i++) {
		int sp=k;
		for(int j=0;j<6;j++) {
			sp=( k<<( j*lg ) ) | sp;
			printf("%d ",sp);
		}
		puts("");
	}
	return 0;
}
