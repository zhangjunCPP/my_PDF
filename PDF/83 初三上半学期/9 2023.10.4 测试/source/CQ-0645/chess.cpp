#include<bits/stdc++.h>
using namespace std;
int n=1,p,k;
int rest[2005];
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10^48);
}
void Freopen(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&p,&k);
	for(int i=1;i<=k;i++)n*=p;
	write(n*(n-1)/(p*(p-1)));
	putchar('\n');
	for(int l=0;l<n-1;l+=p-1){
		for(int i=0;i<=l;i++){
			write(i),putchar(' ');
			for(int j=l+1;j<=l+p-1;j++)write(j),putchar(' ');
			putchar('\n');
		}
	}
}
