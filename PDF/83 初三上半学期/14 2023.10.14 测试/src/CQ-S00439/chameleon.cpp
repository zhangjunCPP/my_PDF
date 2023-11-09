#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5 ;
double b[N];
struct node{
	int b,d,f;
}a[N];
int n,k,l;
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%d %d %d",&n,&k,&l);
	for(int i=1;i<=n;i++){
		char op; 
		scanf("%d %d %c",&a[i].b,&a[i].d,&op);
		getchar();
		switch(op){
			case 'L':{a[i].f=0;break;}
			case 'D':{a[i].f=1;break;}
		}
	}
	
	return 0;
} 
