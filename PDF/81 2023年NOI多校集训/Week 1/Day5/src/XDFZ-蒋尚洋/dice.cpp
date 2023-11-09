#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int n,k;cin>>n>>k;
	puts("Yes");
	for(int i=1;i<=n;puts(""),i++)
	for(int j=1,x=0;j<=6;x=(x<<6)+k,j++)printf("%d ",x);
	return 0;
}
