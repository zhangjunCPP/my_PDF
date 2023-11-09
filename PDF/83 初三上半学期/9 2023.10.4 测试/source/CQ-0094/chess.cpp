#include<bits/stdc++.h>
using namespace std;
void Freopen(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int p,k,n;
inline int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans*=a;
		a*=a; b>>=1;
	}
	return ans;
}
int main(){
	Freopen();
	scanf("%d%d",&p,&k);
	n=ksm(p,k); 
	if(k==1){
		puts("1");
		for(int i=0;i<p;i++) printf("%d ",i);
		return 0; 
	}
	if(p==2){
		printf("%d\n",n*(n-1)/2);
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++)
				write(i),putchar(' '),
				write(j),putchar('\n');
		}
		return 0;
	}
	if(k==2){
		printf("%d\n",p*2+2);
		for(int i=0;i<=p*(p-1);i+=p){
			for(int j=0;j<p;j++)
				write(i+j),putchar(' ');
			printf("\n");
		}
		for(int i=0;i<p;i++){
			for(int j=0;j<p;j++)
				write(i+j*p),putchar(' ');
			printf("\n");
		}
		for(int i=0;i<p;i++) write(i*(p+1)),putchar(' ');
		printf("\n");
		for(int i=1;i<=p;i++) write(i*(p-1)),putchar(' ');
		printf("\n");
		return 0;
	}
	return 0;
} 
