#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll p,s,c,f,a,b,m,k; 
void fj(ll x) {
	ll sq=sqrt(x);
	for(ll i=sq;i>=2;i--) {
		if( x%i==0 ) {
			a=i; b=s/i;
			break;
		}
	}
	if(!a||!b) a=1,b=x;
	if(a>b) swap(a,b);
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&p,&s);
	if( p&1 ) {
		puts("Impossible");
		return 0;
	}
	fj(s);
	c=2ll*a+2ll*b;
	f=p-c; int lf=f>>1;
	if( b==1 && f ) {
		puts("Impossible");
		return 0;
	}
	int can=(a-1)*(b-1);
	if( can<lf ) {
		puts("Impossible");
		return 0;
	}
	k=(can-lf)/(b-1); m=(can-lf)%(b-1);
//	cout<<a<<" "<<b<<" "<<f<<" "<<lf<<" "<<k<<" "<<m<<endl; 
	if(!f) {
		putchar('3');
		for(int i=2;i<=a;i++) putchar('2');
		putchar('3');
		for(int i=2;i<=b;i++) putchar('2');
		putchar('3');
		for(int i=2;i<=a;i++) putchar('2');
		putchar('3');
		for(int i=2;i<=b;i++) putchar('2');
		return 0;
	}
	int fbi=0; int i=1;
//	for(int i=1;i<=p;i++) {
//		switch(fbi) {
//			case 0:{
//				cout<<"zero\n";
				putchar('3');//一上来向右走 
				fbi++; i++;
//				break;
//			}
//			case 1:{
//				cout<<"one\n";
				int doo=a-1-k;
//				cout<<doo<<" \n";
				if( m ) doo--;
				bool fo=false;
				if( doo ) {
					putchar('3'); doo--; i++;
					while(doo) {
						putchar('2'); i++; doo--;
	//					cout<<" "<<doo<<" \n";
					}
					fbi++; fo=true;
				}
				
//				break;
//			}
//			case 2:{
//				cout<<"twe\n";
				if( !m ) { fbi++; /*break;*/ }
				else {
					int sm=m;
					if( fo ) { putchar('1'); sm--; i++; }
					while(sm--) {
						putchar('2'); i++;
					}
					putchar('3'); i++;
					fbi++;
				}
				
//				break;
//			}
//			case 3:{
//				cout<<"three\n";
				int num=b-1-m;
				putchar('1'); num--; i++;
				while(num--) {
					putchar('2'); i++;
				}
				fbi++;
//				break;
//			}
//			case 4:{
//				cout<<"four\n";
				num=k+1+lf;
				putchar('3'); num--; i++;
				while( num-- ) {
					putchar('2'); i++;
				}
				fbi++;
				putchar('3');
//				break;
//			}
//			case 5:{
//				cout<<"five\n";
				num=lf;
				putchar('3'); num--; i++;
				while(num--) {
					putchar('2'); i++;
				}
				fbi++;
//				break;
//			}
//			case 6:{
//				cout<<"six\n";
				num=b-1;
				putchar('1'); num--; i++;
				while( num-- ) {
					putchar('2'); i++;
				}
				fbi++;
//				break;
//			}
//			case 7:{
//				cout<<"seven\n";
				num=a;
				putchar('3'); num--; i++;
				while(num--) {
					putchar('2'); i++;
				}
				fbi++;
//				break;
//			}
//			default:{
//				return 0;
//			}
//		}
//	}
//	cout<<"\n"<<i<<" ";
	return 0;
}
