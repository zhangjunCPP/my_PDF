#include<bits/stdc++.h>
using namespace std;
int q;
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	srand(time(NULL));
	scanf("%d",&q);
	for(;q--;){
		int n,m; scanf("%d%d",&n,&m);
		if(n==1){
			if(m==0){
				puts("0");
			}else{
				puts("1");
			}
		}else if(n==2){
			if(m==0||m==1){
				puts("1");
			}else{
				puts("0");
			}
		}else if(n==3){
			if(m==0||m==2||m==3){
				puts("1");
			}else{
				puts("0");
			}
		}else if(n==4){
			if(m==6||m==5||m==4||m==3||m==0){
				puts("1");
			}else{
				puts("0");
			}
		}else if(n==5){
			if(m==10||m==9||m==8||m==7||m==6||m==4||m==0){
				puts("1");
			}else{
				puts("0");
			}
		}else{
			if(m>=0&&m<=(1+n-1)*(n-1)/2){
				puts("1");
			}else{
				puts("0");
			}
		}
	}
	return 0;
}
