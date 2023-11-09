#include<bits/stdc++.h>
using namespace std;
char s[100001];
int n;
unsigned long long p=131,h[100001],pn[100001];
bool check(int l1,int r1,int l2,int r2){
	return h[r1]-h[l1-1]*pn[r1-l1+1]==h[r2]-h[l2-1]*pn[r2-l2+1];
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	
	scanf("%s",s+1);
	n=strlen(s+1),pn[0]=1;
	for(int i=1;i<=n;i++) pn[i]=pn[i-1]*p;
	for(int i=1;i<=n;i++) h[i]=h[i-1]*p+s[i]-97;
	for(int i=1;i<=n;i++){
		long long now=0;
		for(int j=i+1;j<=n;j++){
			if(j+(j-i)>=n-(j-i)+1) break;
			if(check(i,j-1,j,j+(j-i)-1)&&check(i,j-1,n-(j-i)+1,n)) now++;
		}
		printf("%lld ",now);
	}
	return 0;
}
