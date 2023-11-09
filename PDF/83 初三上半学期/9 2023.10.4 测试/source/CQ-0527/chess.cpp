#include<bits/stdc++.h>
using namespace std;
int p,k,n=1,sum,len,a[2001][2001];
void turn(int c){
//	for(int i=1;i<=p;i++){
//		for(int j=1;j<=p;j++){
//			if(c) printf("%d ",a[i][j]);
//			else sum++;
//		}
//		printf("\n");
//	}
	for(int w=0;w<p;w++){
		for(int i=1;i<=p;i++){
			int l=i;
			for(int j=1;j<=p;j++){
				if(c) printf("%d ",a[j][l]-1);
				l=(l+w)%p+1;
			}
			if(c) printf("\n");
			else sum++;
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d%d",&p,&k);
	for(int i=1;i<=k;i++) n*=p;
	if(k==1){
		printf("1\n");
		for(int i=1;i<=p;i++) printf("%d ",i-1);
	}
	else if(p==2){
		for(int i=1;i<n;i++) sum+=(n-i);
		printf("%d\n",sum);
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) printf("%d %d\n",i-1,j-1);
	}
	else{
		sum=n/p,len=1;
		for(int i=0;i<k-1;i++){
			int lst=len;
			len*=p;
			for(int k3=1;k3<=p;k3+=len){
				for(int j=k3,k1=1;k1<=p;j+=len,k1++){
					for(int l=j,k2=1;k2<=p;k2++,l+=lst){
						a[k1][k2]=l;
					}
				}
				turn(0);
			}
		}
		printf("%d\n",sum);
		for(int i=1;i<=n;i+=p){
			for(int j=i;j<=i+p-1;j++) printf("%d ",j-1);
			printf("\n");
		}
		len=1;
		for(int i=0;i<k-1;i++){
			int lst=len;
			len*=p;
			for(int k3=1;k3<=p;k3+=len){
				for(int j=k3,k1=1;k1<=p;j+=len,k1++){
					for(int l=j,k2=1;k2<=p;k2++,l+=lst){
						a[k1][k2]=l;
					}
				}
				turn(1);
			}
		}
	}
	return 0;
}
